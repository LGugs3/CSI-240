cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Lab7")

add_executable(Lab7 "lab7.cpp" "encryption.h" "encryption.cpp" "method1.h" "method1.cpp" "method2.h" "method2.cpp")