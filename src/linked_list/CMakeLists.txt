cmake_minimum_required(VERSION 3.27.7)

project(linked_list)

add_library(    ${PROJECT_NAME} 
                linked_list.c
                linked_list_cycle.c
                merge_two_sorted_lists.c
)
target_link_libraries(${PROJECT_NAME} PUBLIC unity)
