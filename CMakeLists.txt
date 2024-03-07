cmake_minimum_required(VERSION 3.10)

project(SocketLib)

set(CMAKE_CXX_STANDARD 20)

add_library(libSocket socket/Socket.cpp)

target_include_directories(libSocket PUBLIC ${PROJECT_SOURCE_DIR}/include/socket)
target_include_directories(libSocket PUBLIC ${PROJECT_SOURCE_DIR}/include/stream)
target_include_directories(libSocket PUBLIC ${PROJECT_SOURCE_DIR}/include/datagram)
target_include_directories(libSocket PUBLIC ${PROJECT_SOURCE_DIR}/include/unix)
target_include_directories(libSocket PUBLIC ${PROJECT_SOURCE_DIR}/include/inet)

add_executable(server main_server.cpp)

target_link_libraries(server libSocket)

add_executable(client main_client.cpp)

target_link_libraries(client libSocket)
