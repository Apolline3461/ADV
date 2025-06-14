#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

void handle_client(int client_socket){
    const char* msg = "Welcome from server!\n";
    send(client_socket, msg, strlen(msg), 0);
    closesocket(client_socket);
}

int main() {
    SOCKET server_fd;
    sockaddr_in address{};
    int addrlen = sizeof(address);

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

// Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
// Forcefully attaching socket to the port 8080
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,(char*) &opt, sizeof(opt))) {
        perror("setsockopt");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
// Binding the socket to the port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address))
        < 0) {
        perror("bind failed");
        closesocket(server_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
// Start listening
    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) {
        perror("listen failed");
        closesocket(server_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    std::vector<std::thread> threads;
    while (true) {
        SOCKET newClient = accept(server_fd, (struct sockaddr*)&address, &addrlen);
        if ( newClient == INVALID_SOCKET) {
            perror("accept Failed");
            break;
        }
        threads.emplace_back(handle_client, newClient);
    }
    for (auto& t : threads) t.join();
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
