cmake_minimum_required(VERSION 3.27.7)

project(leetcode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs/Unity)
add_subdirectory(src/array_string)
add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
target_link_libraries(${PROJECT_NAME} PUBLIC array_string)
