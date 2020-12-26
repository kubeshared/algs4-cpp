//
// Created by 徐元昌 on 2020/12/26.
//

#include "bfs_twocolor.h"

BreadthFirstSearchTwoColor::BreadthFirstSearchTwoColor(const Graph &g) {
    _marked = std::vector<bool> (g.V(), false);
    _color = std::vector<bool> (g.V(), false);
    _isTwoColorable = true;
    for (auto s = 0; s < g.V(); s++)
        if (_marked[s])
            _bfs(g, s);
}

void BreadthFirstSearchTwoColor::_bfs(const Graph &g, int v) {
    _color[v] = true;
    _marked[v] = true;
    auto q = std::queue<int>();
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        auto adj = g.adj(v);
        for (auto it = adj->cbegin(); it != adj->cend(); it++) {
            if (!_marked[*it]) {
                _marked[*it] = true;
                q.push(*it);
                _color[*it] = ! _color[v];
            } else if (_color[*it] == _color[v]) {
                _isTwoColorable = false;
            }
        }
        delete adj;
    }
}

bool BreadthFirstSearchTwoColor::isBipartite() {
    return _isTwoColorable;
}