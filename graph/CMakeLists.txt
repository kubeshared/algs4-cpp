
add_library(graph graph.cpp dfs.cpp bfs.cpp)

add_executable(graph_example graph_example.cpp)

target_link_libraries(graph_example graph)