//
// Created by Apoll on 14/06/2025.
//

#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>
#include <mutex>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

namespace WebServer {

    bool initialize_winsock();
    SOCKET create_server_socket(int port);
    void run_server(SOCKET server_socket);
    void log_request(const std::string &message);
    void handle_client(SOCKET client_socket);
}
