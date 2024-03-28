#include "graph_vizualization.h"

int main(int argc, char *argv[]) {
    std::string input;
    std::string output;
    int width;
    int height;
    size_t iterations;

    if (!parse_args(argc, argv, input, output, iterations, width, height)) {
        return 0;
    }

    Graph graph(input);

    BMPProcessor bmp_processor(width, height);

    ForceDirectedPlacement fdp(graph, width, height);

    fdp.run_algorithm(iterations);

    bmp_processor.drawGraph(fdp.get_vertices(), graph);
    bmp_processor.saveImage(output);
}
