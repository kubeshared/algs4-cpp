add_library(digraph
        digraph.cpp
        digraph.h
        directed_dfs.cpp
        directed_dfs.h
        directed_cycle.cpp
        directed_cycle.h)

add_executable(digraph_example digraph_example.cpp)

add_executable(directed_dfs_example directed_dfs_example.cpp)

add_executable(directed_cycle_example directed_cycle_example.cpp)

target_link_libraries(digraph_example digraph)

target_link_libraries(directed_dfs_example digraph)

target_link_libraries(directed_cycle_example digraph)