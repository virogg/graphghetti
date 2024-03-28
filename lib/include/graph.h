#ifndef GRAPHGHETTI_GRAPH_H
#define GRAPHGHETTI_GRAPH_H

#include <vector>
#include "vector_operations.h"


class Graph {
public:
    Graph(const std::string& path);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] const std::vector<int> &get_neighbours(size_t vertex_num) const;

private:
    std::vector<std::vector<int>> graph_;
};

#endif //GRAPHGHETTI_GRAPH_H