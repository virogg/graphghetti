cmake_minimum_required(VERSION 3.26)
project(lib)

set(CMAKE_CXX_STANDARD 20)

set(SourceFiles
        src/bmp_processor.cpp
        src/fruchterman_reingold.cpp
        src/graph.cpp
        src/vector_operations.cpp
)

include_directories(include)
add_library(${PROJECT_NAME} ${SourceFiles})