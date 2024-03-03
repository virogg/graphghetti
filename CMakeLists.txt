cmake_minimum_required(VERSION 3.26)
project(graphghetti)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphghetti
        main.cpp
        vector_operations.cpp
        vector_operations.h
        fruchterman_reingold.cpp
        fruchterman_reingold.h
        graph.cpp
        graph.h
        bmp_processor.cpp
        bmp_processor.h
)
