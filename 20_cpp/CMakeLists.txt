cmake_minimum_required(VERSION 3.5)

project(20_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(20_cpp main.cpp Student.h Student.cpp Course.h Course.cpp)

install(TARGETS 20_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
