cmake_minimum_required(VERSION 3.27.7)

project(leetcode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(TARGET leetcode PROPERTY C_STANDARD 99)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_subdirectory(libs/Unity)
add_subdirectory(src/array_string)
add_subdirectory(src/linked_list)
add_subdirectory(src/stack)
add_subdirectory(src/two_pointers)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
target_link_libraries(${PROJECT_NAME} PUBLIC array_string)
target_link_libraries(${PROJECT_NAME} PUBLIC linked_list)
target_link_libraries(${PROJECT_NAME} PUBLIC stack)
target_link_libraries(${PROJECT_NAME} PUBLIC two_pointers)
