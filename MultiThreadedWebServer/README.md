# Multi-threaded Web Server

This project implements a multi-threaded Web Server in C++.
It uses **winsock** for the networking and a **thread pool** to handle HTTP requests.

___
## Security / SSL

The server now supports HTTPS using a self-signed SSL certificate.

### Generate a self-signed certificate (Windows)

To generate your own SSL certificate and private key with OpenSSL:

1. Make sure [OpenSSL](https://slproweb.com/products/Win32OpenSSL.html) is installed and available in your PATH.
2. Open PowerShell or CMD in the project root.
3. Run the following command:

`openssl req -x509 -newkey rsa:2048 -nodes -keyout key.pem -out cert.pem -days 365`

This creates two files:

key.pem: your private key (keep it secret)

cert.pem: your certificate

Place both files in a folder (e.g., certs/)

⚠️ Warning: Browsers will display a security warning when accessing your server with a self-signed certificate. This is normal for development purposes.


## Prerequisites

- CMake ≥ 3.15
- A C++17-compatible compiler
- vcpkg installed and configured 
- OpenSSL (for SSL support)


## Project Structure

- `include/`: Header files

- `www/`: Root folder for static HTML files (`index.html`, `404.html`, `500.html`)

- `config.json`: Configuration file (port, root folder, max threads)
- `build/`: Build directory
- `CMakeLists.txt`: CMake configuration
- `main.cpp`, `server.cpp`, `thread_pool.cpp`: Source files
- `img/`: Contains screenshots demonstrating the correct operation of the thread pool and HTTPS support.


## Execution
- You can update information in the config.json file at the root repository.
- You can add your html file, to create your own website, in the www/ directory at the root of it. 
  _The index.html, the 404 and 500.html page are provides_

To start the server :

`mkdir build`

`cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/Users/Apoll/vcpkg/scripts/buildsystems/vcpkg.cmake`

`cmake --build build`

`cd ./build/Debug/; cp MultiThreadWebServer.exe ../ ; cd ../`

`./MultiThreadedWebServer`
