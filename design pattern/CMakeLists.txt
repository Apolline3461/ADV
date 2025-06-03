cmake_minimum_required(VERSION 3.26)
project(design_pattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_pattern main.cpp
        ConfigManager.cpp
        ConfigManager.hpp
        ShapeFactory.cpp
        ShapeFactory.hpp
        IShape.hpp
        CIrcle.cpp
        Circle.hpp
        Square.cpp
        Square.hpp
        Event.hpp
        IObserver.hpp
        Subject.hpp
        ConcreteObserver.hpp
        ISortStrategy.hpp
        BubbleSort.cpp
        BubbleSort.hpp
        QuickSort.cpp
        QuickSort.hpp
        SortContext.hpp
        IFileSystemItem.hpp
        File.cpp
        File.hpp
        Directory.cpp
        Directory.hpp
)
