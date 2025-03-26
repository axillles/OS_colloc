cmake_minimum_required(VERSION 3.10)
project(FibonacciProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основной исполняемый файл
add_executable(fibonacci_main main.cpp fibonacci.cpp)

# Тесты
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(fibonacci_tests fibonacci_test.cpp fibonacci.cpp)
target_link_libraries(fibonacci_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
