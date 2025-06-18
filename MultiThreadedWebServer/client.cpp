//
// Created by Apoll on 14/06/2025.
//

#include "server.hpp"
std::mutex log_mutex;
std::string WebServer::www_root = "../www";
int WebServer::port = 8080;
int WebServer::max_thr = 4;

void WebServer::log_request(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << message << std::endl;
}

std::string WebServer::read_file_to_string(const std::string& full_path) {
    std::ifstream file(full_path);
    if (!file) return "";
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

std::string WebServer::build_http_response(int status_code, const std::string& content) {
    std::string status_text;

    switch (status_code) {
        case 200: status_text = "OK"; break;
        case 404: status_text = "Not Found"; break;
        case 500: status_text = "Internal Server Error"; break;
        default:  status_text = "Unknown";
    }

    return "HTTP/1.1 " + std::to_string(status_code) + " " + status_text +
           "\r\nContent-Length: " + std::to_string(content.size()) +
           "\r\n\r\n" + content;
}

void WebServer::handle_client(SOCKET client_socket) {
    try {
        char buffer[1024] = {0};
        int received = recv(client_socket, buffer, 1024, 0);
        if (received <= 0) {
            closesocket(client_socket);
            return;
        }
        std::string request(buffer);
        std::string method, path;
        std::istringstream request_stream(request);
        request_stream >> method >> path;

        log_request("Received request: " + method + " " + path);

        if (path == "/") path = "/index.html";
        std::string file_content = read_file_to_string(www_root + path);
        std::string response;

        if (!file_content.empty()) {
            response = build_http_response(200, file_content);
            log_request("200 OK: " + path);
        } else {
            std::string not_found_content = read_file_to_string(www_root + "/404.html");
            if (!not_found_content.empty()) {
                response = build_http_response(404, not_found_content);
            } else {
                response = build_http_response(404, "");
            }
            log_request("404 Not Found: " + path);
        }
        send(client_socket, response.c_str(), response.size(), 0);
    } catch (const std::exception &e) {
        std::string content = read_file_to_string(www_root + "/500.html");
        std::string response = build_http_response(500, content);
        send(client_socket, response.c_str(), response.size(), 0);
        log_request(std::string("500 Internal Server Error: ") + e.what());
    }
    closesocket(client_socket);
}

void WebServer::handle_client_ssl(SSL* ssl, SOCKET client_socket) {
    try {
        char buffer[1024] = {0};
        int received = SSL_read(ssl, buffer, sizeof(buffer));
        if (received <= 0) return;

        std::string request(buffer);
        std::string method, path;
        std::istringstream request_stream(request);
        request_stream >> method >> path;

        log_request("Received HTTPS request: " + method + " " + path);

        if (path == "/") path = "/index.html";
        std::string file_content = read_file_to_string(www_root + path);
        std::string response;

        if (!file_content.empty()) {
            response = build_http_response(200, file_content);
            log_request("200 OK: " + path);
        } else {
            std::string not_found_content = read_file_to_string(www_root + "/404.html");
            response = build_http_response(404, not_found_content);
            log_request("404 Not Found: " + path);
        }

        SSL_write(ssl, response.c_str(), response.size());
    } catch (const std::exception &e) {
        std::string content = read_file_to_string(www_root + "/500.html");
        std::string response = build_http_response(500, content);
        SSL_write(ssl, response.c_str(), response.size());
        log_request(std::string("500 Internal Server Error: ") + e.what());
    }
    closesocket(client_socket);
}


void WebServer::load_conf(const std::string &conf_path) {

    std::ifstream file(conf_path);
    if (!file) {
        std::cerr << "Could not open config file, using default settings." << std::endl;
        return;
    }

    try {
        nlohmann::json config;
        file >> config;
        if (config.contains("port")) port = config["port"];
        if (config.contains("www_root")) www_root = config["www_root"];
        if (config.contains("max_threads")) max_thr = config["max_threads"];
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config file: " << e.what() << std::endl;
    }
}
