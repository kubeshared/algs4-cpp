//
// Created by 徐元昌 on 2021/1/9.
//

#include "symbol_graph.h"

int main(const int argc, const char **argv)
{
    SymbolGraph sg("/Users/xyc/workspace/code/github.com/kubeshared/algs4-cpp/graph/routes.txt", " ");
    sg.degreesOfSeparation();

//    SymbolGraph sg("/Users/xyc/workspace/code/github.com/kubeshared/algs4-cpp/graph/movies.txt", "/");
//    sg.degreesOfSeparation();
}