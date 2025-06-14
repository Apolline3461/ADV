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

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class WebServer {
public:
    static int port;
    static int max_thr;
    static std::string www_root;

    static void load_conf(const std::string &conf_path = "config.json");
    static bool initialize_winsock();
    static SOCKET create_server_socket(int port);
    void run_server(SOCKET server_socket);
    static void handle_client(SOCKET client_socket);

private:

    static void log_request(const std::string &message);
    static std::string read_file_to_string(const std::string& full_path);
    static std::string build_http_response(int status_code, const std::string& content);
};
