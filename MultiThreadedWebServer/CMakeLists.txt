cmake_minimum_required(VERSION 3.26)
project(MultiThreadedWebServer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

add_executable(MultiThreadedWebServer server.cpp
        main.cpp
        client.cpp
        thread_pool.cpp
        include/thread_pool.hpp
        include/server.hpp
        applink.c
)

target_include_directories(MultiThreadedWebServer PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(MultiThreadedWebServer PRIVATE OpenSSL::SSL OpenSSL::Crypto ws2_32 )
