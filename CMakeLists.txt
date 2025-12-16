cmake_minimum_required(VERSION 3.27)
project(Cache_System)

set(CMAKE_CXX_STANDARD 23)


add_executable(Cache_System src/main.cpp
        include/LRUCache.h
        src/LRUCache.cpp)

target_include_directories(Cache_System PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)