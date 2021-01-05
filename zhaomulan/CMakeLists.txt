cmake_minimum_required(VERSION 3.0.0)
add_definitions(CMAKE_CXX_COMPILER /usr/bin/g++)
project(zhaomulan)


include_directories(zhaomulan include)


add_executable(main main.cpp "include/http_server.h" "include/http_server.cpp")