cmake_minimum_required(VERSION 3.10)
project(LinkedListProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(list_main main.cpp linked_list.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(list_tests linked_list_test.cpp linked_list.cpp)
target_link_libraries(list_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
