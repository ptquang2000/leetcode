cmake_minimum_required(VERSION 3.27.7)

project(stack)

add_library(    ${PROJECT_NAME} 
                stack.c
                valid_parentheses.c
)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
