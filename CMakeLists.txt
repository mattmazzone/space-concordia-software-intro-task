cmake_minimum_required(VERSION 3.20)
project(space_concordia_software_intro_task)

set(CMAKE_CXX_STANDARD 14)

add_executable(space_concordia_software_intro_task
        main.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sample-board.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
