#include "graph.h"
#include <iostream>

Graph::Graph() {
    size_t V;
    size_t E;
    std::cin >> V >> E;
    graph_.resize(V);
    for (int i = 0; i < E; ++i) {
        int u;
        int v;
        std::cin >> u >> v;
        graph_[u].push_back(v);
        graph_[v].push_back(u);
    }
}

const std::vector<int> &Graph::get_neighbours(size_t vertex_num) const {
    return graph_[vertex_num];
}

size_t Graph::size() const {
    return graph_.size();
}