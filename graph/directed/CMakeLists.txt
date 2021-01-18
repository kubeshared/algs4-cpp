add_library(digraph
        digraph.cpp
        digraph.h
        directed_dfs.cpp
        directed_dfs.h
        digraph_example.cpp)

add_executable(digraph_example digraph_example.cpp)

add_executable(directed_dfs_example directed_dfs_example.cpp)

target_link_libraries(digraph_example digraph)

target_link_libraries(directed_dfs_example digraph)