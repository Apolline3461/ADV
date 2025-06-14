#include "server.hpp"


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
    std::vector<std::thread> threads;

    std::cout << "run svr" << std::endl;

    while (true) {
        SOCKET new_cl_socket = accept(server_socket, (struct sockaddr*)&client_add, &add_len);
        if (new_cl_socket == INVALID_SOCKET) {
            perror("new client invalid socket");
            break;
        }
        threads.emplace_back(WebServer::handle_client, new_cl_socket);
    }
    for (auto& t : threads) t.join();
}
