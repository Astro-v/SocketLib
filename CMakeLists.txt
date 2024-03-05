cmake_minimum_required(VERSION 3.10)

project(SocketLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(SocketLib main.cpp)

target_include_directories(SocketLib PUBLIC include)