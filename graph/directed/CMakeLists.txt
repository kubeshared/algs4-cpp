add_library(digraph digraph.cpp digraph.h digraph_example.cpp)

add_executable(digraph_example digraph_example.cpp)

target_link_libraries(digraph_example digraph)