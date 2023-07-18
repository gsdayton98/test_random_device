cmake_minimum_required(VERSION 3.25)
project(test_random_device)

set(CMAKE_CXX_STANDARD 23)

add_executable(test_random_device main.cpp random_device.cpp random_device.hpp)
