cmake_minimum_required(VERSION 3.15)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        LinkedListInterface.h LinkedList.cpp LinkedList.h)