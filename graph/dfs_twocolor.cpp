//
// Created by 徐元昌 on 2020/12/26.
//

#include "dfs_twocolor.h"

DepthFirstSearchTwoColor::DepthFirstSearchTwoColor(const Graph &g) {
    _marked = std::vector<bool> (g.V(), false);
    _color = std::vector<bool> (g.V(), false);
    _isTwoColorable = true;
    for (auto x = 0; x < g.V(); x++)
        if (!_marked[x])
            _dfs(g, x);
}

void DepthFirstSearchTwoColor::_dfs(const Graph &g, int v) {
    _marked[v] = true;
    auto adj = g.adj(v);
    for (auto it = adj->cbegin(); it != adj->cend(); it++) {
        if (!_marked[*it]) {
            _color[*it] = !_color[v];
            _dfs(g, *it);
        } else if (_color[*it] == _color[v]) {
            _isTwoColorable = false;
        }
    }
    delete adj;
}

bool DepthFirstSearchTwoColor::isBipartite() {
    return _isTwoColorable;
}