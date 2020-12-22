
add_library(graph graph.cpp search.cpp)

add_executable(graph_example graph_example.cpp)

target_link_libraries(graph_example graph)