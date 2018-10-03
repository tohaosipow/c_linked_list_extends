cmake_minimum_required(VERSION 3.9)
project(lab2 C)

set(CMAKE_C_STANDARD 99)

add_library(lab3-list list.c list.h)
add_library(lab3-menu listmenu.c listmenu.h)
add_library(lab3-subject transport.c transport.h)
add_executable(lab3-main main.c)
target_link_libraries(lab3-main lab3-list)
target_link_libraries(lab3-main lab3-menu)
target_link_libraries(lab3-main lab3-subject)