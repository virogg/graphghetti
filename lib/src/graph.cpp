#include "graph.h"
#include <iostream>
#include "fstream"

Graph::Graph(const std::string& path) {
    std::ifstream fs(path);
    if(!fs.is_open()){
        throw std::runtime_error("Can not open the file " + path);
    }
    size_t V;
    size_t E;
    fs >> V >> E;
    graph_.resize(V);
    for (int i = 0; i < E; ++i) {
        int u;
        int v;
        fs >> u >> v;
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