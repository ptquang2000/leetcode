cmake_minimum_required(VERSION 3.27.7)

project(two_pointers)

add_library(    ${PROJECT_NAME} 
                two_pointers.c
                is_palindrome.c
                is_subsequence.c
)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
