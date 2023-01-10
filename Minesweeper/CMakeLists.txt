cmake_minimum_required(VERSION 3.5)

project(12_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12_cpp main.cpp field.h field.cpp)

install(TARGETS 12_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
