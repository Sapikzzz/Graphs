cmake_minimum_required(VERSION 3.28)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs
        main.cpp
        adjacency_list.cpp
        adjacency_matrix.cpp
        adjacency_matrix.h)
