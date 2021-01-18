
add_library(graph graph.cpp
        dfs.cpp bfs.cpp
        dfs_cc.cpp
        bfs_cc.cpp
        dfs_cycle.cpp
        bfs_cycle.cpp
        dfs_twocolor.cpp
        bfs_twocolor.cpp
        symbol_graph.cpp
        symbol_graph.h directed/digraph.cpp directed/digraph.h)

#add_executable(graph_example graph_example.cpp)

add_executable(symbol_graph_example symbol_graph_example.cpp )

#target_link_libraries(graph_example graph)
target_link_libraries(symbol_graph_example graph)