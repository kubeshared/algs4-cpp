//
// Created by 徐元昌 on 2021/1/8.
//

#include "symbol_graph.h"
#include "bfs.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

SymbolGraph::SymbolGraph(const std::string &filename, std::string delim) {
    ifstream in(filename);
    if (!in.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    string line;
    while (getline(in, line)) {
        vector<string> a = _split(line, delim);
        for (int i = 0; i < a.size(); i++) {
            if (_st.find(a[i]) == _st.end()) {
                _st[a[i]] = _st.size();
            }
        }
    }

    _keys = std::vector<string>(_st.size());
    for (const auto & kv : _st) {
        _keys[kv.second] = kv.first;
    }
    in.close();

    in.open(filename);
    if (!in.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    _g = new GraphList(_keys.size());
//    _g = new Graph(_keys.size(), false);
    while (getline(in, line)) {
        vector<string> a = _split(line, delim);
        if (a.empty()) {
            continue;
        }
        int v = _st[a[0]];
        for (int i = 1; i < a.size(); i++) {
            _g->addEdge(v, _st[a[i]]);
        }
    }
    in.close();
}

SymbolGraph::~SymbolGraph()
{
    delete _g;
}

std::vector<std::string> SymbolGraph::_split(string &line, string &delim) {
    vector<string> results;
    auto start = 0U;
    auto end = line.find(delim);
    while (end != std::string::npos) {
        results.push_back(line.substr(start, end - start));
        start = end + delim.length();
        end = line.find(delim, start);
    }
    results.push_back(line.substr(start, end - start));
    return move(results);
}

void SymbolGraph::degreesOfSeparation()
{
    cout << "please input your query route of start station: ";

    string query;
    if (!getline(cin, query)) {
        return;
    }

    // TODO lamda
    auto it = _st.find(query);
    if (it == _st.end()) {
        string err("input " + query + " invalid!");
        perror(err.c_str());
        exit(1);
    }

    BreadthFirstSearch bfs(*_g, it->second);

    cout << "please input your query route of end station: ";

    while(getline(cin, query)) {
        it = _st.find(query);
        if (it == _st.end()) {
            cout << "input " << query << "invalid!" << endl;
            continue;
        }
        if (bfs.hasPathTo(it->second)) {
            cout << query << ":" << it->second << endl;
            auto sk = bfs.pathTo(it->second);
            while(!sk->empty()) {
                cout << "\t" << _keys[sk->top()] << endl;
                sk->pop();
            }
            delete sk;
        }
        cout << "if continue query, please input your query route of end station: ";
    }
}