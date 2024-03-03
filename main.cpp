#include <iostream>
#include "fruchterman_reingold.h"
#include "graph.h"
#include "bmp_processor.h"

int main() {
    Graph graph;

    int width = 1000, height = 1000;

    BMPProcessor bmpProcessor(width, height);

    ForceDirectedPlacement fdp(graph, width, height);

    fdp.run_algorithm(1000);

    bmpProcessor.drawGraph(fdp.get_vertices(), graph);
    bmpProcessor.saveImage("graph.bmp");

    return 0;
}
