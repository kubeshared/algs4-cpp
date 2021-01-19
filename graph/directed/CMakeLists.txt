add_library(digraph
        digraph.cpp
        digraph.h
        directed_dfs.cpp
        directed_dfs.h
        directed_cycle.cpp
        directed_cycle.h
        directed_dfs_order.cpp
        directed_dfs_order.h
        directed_topological.cpp
        directed_topological.h
        directed_scc.cpp
        directed_scc.h
        )

add_executable(digraph_example digraph_example.cpp)

add_executable(directed_dfs_example directed_dfs_example.cpp)

add_executable(directed_cycle_example directed_cycle_example.cpp)

add_executable(directed_topological_example directed_topological_example.cpp)

target_link_libraries(digraph_example digraph)

target_link_libraries(directed_dfs_example digraph)

target_link_libraries(directed_cycle_example digraph)

target_link_libraries(directed_topological_example digraph)