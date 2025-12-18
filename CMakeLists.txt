cmake_minimum_required(VERSION 3.27)
project(Cache_System)

set(CMAKE_CXX_STANDARD 23)


add_executable(Cache_System src/main.cpp
        include/LRUCache.h
        src/LRUCache.cpp
        tests/tests_LRU.cpp)

target_include_directories(Cache_System PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# -----Google_Test------
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # Windows fix
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        lru_tests
        tests/tests_LRU.cpp
        src/LRUCache.cpp
)

target_include_directories(lru_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(lru_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lru_tests)