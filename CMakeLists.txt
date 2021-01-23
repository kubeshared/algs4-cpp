cmake_minimum_required(VERSION 3.10)
project(src CXX)
set (CMAKE_C_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(graph)

add_subdirectory(graph/directed)

add_subdirectory(src)