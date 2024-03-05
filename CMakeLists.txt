cmake_minimum_required(VERSION 3.26)
project(graphghetti)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib)
add_subdirectory(lib)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} lib)