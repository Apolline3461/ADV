//
// Created by Apoll on 14/06/2025.
//

#include "server.hpp"
std::mutex log_mutex;

void WebServer::log_request(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << message << std::endl;
}

void WebServer::handle_client(SOCKET client_socket) {
    char buffer[1024] = {0};
    recv(client_socket, buffer, 1024, 0);
    std::string request(buffer);
    std::string method, path;
    std::istringstream request_stream(request);
    request_stream >> method >> path;
    log_request("Received request: " + method + " " + path);
    std::string response;
    if (path == "/") {
        path = "/index.html";
    }
    std::ifstream file("www" + path);
    if (file) {
        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        response = "HTTP/1.1 200 OK\r\nContent-Length: " +
                   std::to_string(content.size()) + "\r\n\r\n" + content;
    } else {
        response = "HTTP/1.1 404 Not Found\r\nContent-Length:0\r\n\r\n";
    }
    send(client_socket, response.c_str(), response.size(), 0);
    closesocket(client_socket);
}