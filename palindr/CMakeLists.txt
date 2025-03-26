cmake_minimum_required(VERSION 3.10)
project(PalindromeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(palindrome_main main.cpp palindrome.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(palindrome_tests palindrome_test.cpp palindrome.cpp)
target_link_libraries(palindrome_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
