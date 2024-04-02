cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Lab6")

add_executable(Lab6 "lab6.cpp" "item.h" "item.cpp" "book.h" "book.cpp" "comic.h" "comic.cpp")