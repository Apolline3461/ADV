//
// Created by Apoll on 14/06/2025.
//

#include "server.hpp"

int main() {
    WebServer server;
    WebServer::load_conf("../config.json");

    if (!WebServer::initialize_winsock()) return EXIT_FAILURE;

    SOCKET server_socket = WebServer::create_server_socket(WebServer::port);
    if (server_socket == INVALID_SOCKET) {
        WSACleanup();
        return EXIT_FAILURE;
    }

    server.run_server(server_socket);

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
