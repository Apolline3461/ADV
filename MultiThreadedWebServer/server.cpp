#include "server.hpp"
#include "thread_pool.hpp"

SSL_CTX* WebServer::create_ssl_context() {
    const SSL_METHOD* method = TLS_server_method();
    SSL_CTX* ctx = SSL_CTX_new(method);

    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Charge cert et key
    if (SSL_CTX_use_certificate_file(ctx, "../certs/cert.pem", SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ctx, "../certs/key.pem", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

bool WebServer::initialize_winsock() {
    std::cout << "init winsock" << std::endl;
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2,2), &wsaData) == 0;
}

SOCKET WebServer::create_server_socket(int port) {
    SOCKET svr_socket = socket(AF_INET, SOCK_STREAM, 0);

    std::cout << "create svr" << std::endl;
    if (svr_socket == INVALID_SOCKET) return INVALID_SOCKET;
    int opt = 1;
    std::cout << "Set socket" << std::endl;
    if (setsockopt(svr_socket, SOL_SOCKET, SO_REUSEADDR,(char*) &opt, sizeof(opt))) {
        perror("set sockopt");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    std::cout << "bind socket" << std::endl;
    if (bind(svr_socket, (struct sockaddr*)&address, sizeof(address)) < 0 || listen(svr_socket, SOMAXCONN) == SOCKET_ERROR) {
        perror("bind failed");
        closesocket(svr_socket);
        return INVALID_SOCKET;
    }
    return svr_socket;
}

void WebServer::run_server(SOCKET server_socket) {
    sockaddr_in client_add{};
    int add_len = sizeof(client_add);

    ThreadPool pool(WebServer::max_thr);
    std::cout << "run svr" << std::endl;

    SSL_CTX* ctx = create_ssl_context();

    while (true) {
        SOCKET new_cl_socket = accept(server_socket, (struct sockaddr*)&client_add, &add_len);
        if (new_cl_socket == INVALID_SOCKET) {
            perror("new client invalid socket");
            break;
        }
        pool.enqueue([this, new_cl_socket, &ctx]() {
            SSL* ssl = SSL_new(ctx);
            SSL_set_fd(ssl, new_cl_socket);

            if (SSL_accept(ssl) <= 0) {
                ERR_print_errors_fp(stderr);
                SSL_shutdown(ssl);
                SSL_free(ssl);
                closesocket(new_cl_socket);
                return;
            }

            this->handle_client_ssl(ssl, new_cl_socket);

            SSL_shutdown(ssl);
            SSL_free(ssl);
        });
        std::cout << "[ThreadPool] Actifs : " << ThreadPool::active_clients
                  << " | En attente : " << ThreadPool::queued_tasks << std::endl;

    }
    SSL_CTX_free(ctx);
}
