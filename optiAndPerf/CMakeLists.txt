cmake_minimum_required(VERSION 3.26)
project(optiAndPerf)

set(CMAKE_CXX_STANDARD 17)

add_executable( optiAndPerf
        main.cpp
)
add_executable( Astar
        astar.cpp
)
target_compile_options(Astar PRIVATE -O2 -pg)
target_link_options(Astar PRIVATE -pg)
