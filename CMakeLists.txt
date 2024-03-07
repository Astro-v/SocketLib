cmake_minimum_required(VERSION 3.10)

project(SocketLib)

set(CMAKE_CXX_STANDARD 20)


add_executable(server main_server.cpp )

target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/socket)
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/stream)
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/datagram)
target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR}/include/unix)
target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR}/include/inet)

add_executable(client main_client.cpp)

target_include_directories(client PUBLIC include)
