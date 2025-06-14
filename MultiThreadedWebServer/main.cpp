//
// Created by Apoll on 14/06/2025.
//

#include "server.hpp"

int main() {

    if (!WebServer::initialize_winsock()) return EXIT_FAILURE;

    SOCKET server_socket = WebServer::create_server_socket(8080);
    if (server_socket == INVALID_SOCKET) {
        WSACleanup();
        return EXIT_FAILURE;
    }

    WebServer::run_server(server_socket);

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
