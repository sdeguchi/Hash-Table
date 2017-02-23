cmake_minimum_required(VERSION 3.6)
project(HashTable)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Entry.h Entry.cpp HashTable.h HashTable.cpp)
add_executable(HashTable ${SOURCE_FILES})