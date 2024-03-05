#include "graph_vizualization.h"

int main() {
    Graph graph;

    int width = 1000;
    int height = 1000;

    BMPProcessor bmp_processor(width, height);

    ForceDirectedPlacement fdp(graph, width, height);

    fdp.run_algorithm(1000);

    bmp_processor.drawGraph(fdp.get_vertices(), graph);
    bmp_processor.saveImage("graph_.bmp");

    return 0;
}
