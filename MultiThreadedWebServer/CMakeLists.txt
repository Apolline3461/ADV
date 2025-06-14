cmake_minimum_required(VERSION 3.26)
project(MultiThreadedWebServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultiThreadedWebServer server.cpp
        client.cpp
        include/server.hpp
        main.cpp
        include/thread_pool.hpp
        thread_pool.cpp)

target_include_directories(MultiThreadedWebServer PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(MultiThreadedWebServer ws2_32)
