#ifndef GRAPHGHETTI_FRUCHTERMAN_REINGOLD_H
#define GRAPHGHETTI_FRUCHTERMAN_REINGOLD_H

#include "vector_operations.h"
#include "graph.h"
#include "bmp_processor.h"
#include "string"

class ForceDirectedPlacement {
public:
    ForceDirectedPlacement(const Graph &graph, int width, int height, double k = 15.0);

    [[nodiscard]] inline std::vector<Point> get_vertices() const {
        return positions_;
    };

    void run_algorithm(int iterations) {
        for (int i = 0; i < iterations; ++i) {
            run_iteration();
        }
        scale_frame();
    }

private:
    const Graph &graph_;
    const double k_; // The spring constant
    double t_; // Temperature
    const int width_;
    const int height_;
    std::vector<Vector> displacement_;
    std::vector<Point> positions_;

    [[nodiscard]] inline double attractive_force(double x) const {
        return (x * x) / k_;
    }

    [[nodiscard]] inline double repulsive_force(double x) const {
        return (k_ * k_) / x;
    }

    // Function to cool down the temperature
    static inline void cool(double &t) {
        t *= 0.99;
        if (t < 0.001) {
            t = 0.001;
        }
    }

    void run_iteration(); // Run one iteration of the algorithm
    void scale_frame(); // Scale the vertices within the frame
};

#endif //GRAPHGHETTI_FRUCHTERMAN_REINGOLD_H
