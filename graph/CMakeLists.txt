
add_library(graph
        graph.cpp
        edge.h
        edge.cpp
        edge_weighted_graph.cpp
        edge_weighted_graph.h
#        dfs.cpp bfs.cpp
#        dfs_cc.cpp
#        bfs_cc.cpp
#        dfs_cycle.cpp
#        bfs_cycle.cpp
#        dfs_twocolor.cpp
#        bfs_twocolor.cpp
#        symbol_graph.cpp
#        symbol_graph.h
        )

add_executable(graph_example graph_example.cpp)

add_executable(symbol_graph_example symbol_graph_example.cpp )

target_link_libraries(graph_example graph)
target_link_libraries(symbol_graph_example graph)