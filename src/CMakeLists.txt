add_library(algs4
        uf.h
        uf_impl.h
        uf_impl.cpp
        min_pq.h
        max_pq.h
        index_min_pq.h
        graph.cpp
        edge.cpp
        edge_weighted_graph.cpp
        lazy_prim_mst.cpp
        prim_mst.cpp
        alphabet.h
        alphabet.cpp
        kruskal_mst.h
        kruskal_mst.cpp)

add_executable(max_pq_example pq_example.cpp)

add_executable(graph_example graph_example.cpp)

add_executable(edge_weighted_graph_example edge_weighted_graph_example.cpp)

add_executable(lazy_prim_mst_example lazy_prim_mst_example.cpp)

add_executable(index_pq_example index_pq_example.cpp)

add_executable(alphabet_example alphabet_example.cpp)
add_executable(uf_example uf_example.cpp)

target_link_libraries(max_pq_example algs4)

target_link_libraries(graph_example algs4)

target_link_libraries(edge_weighted_graph_example algs4)

target_link_libraries(lazy_prim_mst_example algs4)

target_link_libraries(index_pq_example algs4)

target_link_libraries(alphabet_example algs4)
target_link_libraries(uf_example algs4)
