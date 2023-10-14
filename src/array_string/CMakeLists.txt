cmake_minimum_required(VERSION 3.27.7)

project(array_string)

add_library(    ${PROJECT_NAME} 
                array_string.c
                merge_sorted_array.c
                remove_element.c
                remove_duplicates.c
)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
