
add_library(graph graph.cpp dfs.cpp bfs.cpp dfs_cc.cpp bfs_cc.cpp dfs_cycle.cpp bfs_cycle.cpp)

add_executable(graph_example graph_example.cpp)

target_link_libraries(graph_example graph)