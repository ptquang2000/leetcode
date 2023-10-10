cmake_minimum_required(VERSION 3.27.7)

project(leetcode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs/Unity)
add_executable(${PROJECT_NAME} src/main.c src/array_string/array_string.c)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
