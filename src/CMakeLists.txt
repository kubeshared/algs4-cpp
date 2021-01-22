add_library(pq
        max_pq.cpp
        max_pq.h)

add_executable(max_pq_example max_pq_example.cpp)

target_link_libraries(max_pq_example pq)