# Multi-threaded Web Server

This project implements a multi-threaded Web Server in C++.
It uses **winsock** for the networking and a **thread pool** to handle HTTP requests.

## Project Structure

- `include/`: Header files
- `www/`: Root folder for static HTML files (`index.html`, `404.html`, `500.html`)
- `config.json`: Configuration file (port, root folder, max threads)
- `build/`: Build directory
- `CMakeLists.txt`: CMake configuration
- `main.cpp`, `server.cpp`, `thread_pool.cpp`: Source files


## EXECUTION
- You can update information in the config.json file at the root repository.
- You can add your html file, to create your own website, in the www/ directory at the root of it. 
  _The index.html, the 404 and 500.html page are provides_

To start the server :
`mkdir build
cd build
cmake --build .
./MultiThreadedWebServer
`
