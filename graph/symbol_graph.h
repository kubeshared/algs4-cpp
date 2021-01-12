//
// Created by 徐元昌 on 2021/1/8.
//

#ifndef ALGS4_SYMBOL_GRAPH_H
#define ALGS4_SYMBOL_GRAPH_H
#include <vector>
#include <list>
#include <string>
#include <map>
#include "graph.h"

class SymbolGraph {
public:
    explicit SymbolGraph(const std::string &filename, std::string delim);
    void degreesOfSeparation();
    ~SymbolGraph();
private:
    size_t _v{};
    size_t _e{};
    std::map<std::string, int> _st;
    std::vector<std::string> _keys;
    GraphInterface *_g;

    std::vector<std::string> _split(std::string &line, std::string &delim);
};

#endif //ALGS4_SYMBOL_GRAPH_H
