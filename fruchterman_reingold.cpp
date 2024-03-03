#include "fruchterman_reingold.h"
#include "cmath"

ForceDirectedPlacement::ForceDirectedPlacement(const Graph &graph, int width, int height, double k)
    : graph_(graph),
      k_(k),
      t_(static_cast<double>(graph.size())),
      displacement_(graph.size()),
      positions_(graph.size()),
      width_(width),
      height_(height) {
    // Initially put vertices on a circle
    double angle = 2.0 * M_PI / static_cast<double>(graph.size());
    for(int i = 0; i < graph.size(); ++i){
        positions_[i].x = cos(static_cast<double>(i) * angle);
        positions_[i].y = sin(static_cast<double>(i) * angle);
    }
}

void ForceDirectedPlacement::scale_frame() {
    // Find current width and height
    int x_min = INT_MAX;
    int x_max = INT_MIN;
    int y_min = INT_MAX;
    int y_max = INT_MIN;

    for (int v_id = 0; v_id < graph_.size(); v_id++) {
        x_min = std::min(x_min, positions_[v_id].x);
        x_max = std::max(x_max, positions_[v_id].x);
        y_min = std::min(y_min, positions_[v_id].y);
        y_max = std::max(y_max, positions_[v_id].y);
    }

    double cur_width = x_max - x_min;
    double cur_height = y_max - y_min;

    // Calculate the scale factor
    double x_scale = static_cast<double>(width_) / cur_width;
    double y_scale = static_cast<double>(height_) / cur_height;
    double scale = 0.9 * std::min(x_scale, y_scale);

    // Scale the graph to fit the frame
    Vector center(x_max + x_min, y_max + y_min);
    Vector offset = center / 2.0 * scale - Vector{static_cast<int>(width_ / 2.0),static_cast<int>(height_ / 2.0)};
    for (int v_id = 0; v_id < graph_.size(); v_id++) {
        positions_[v_id] = (Point)((Vector)positions_[v_id] * scale - offset);
    }
}

void ForceDirectedPlacement::run_iteration() {
    // Clear the displacement
    std::fill(displacement_.begin(), displacement_.end(), Vector(0, 0));

    // Calculate repulsive forces between a pair of vertices
    for (int v = 0; v < graph_.size(); ++v) {
        for (int u = v + 1; u < graph_.size(); ++u) {
            if(v == u){
                continue;
            }
            Vector delta = positions_[v] - positions_[u];
            double distance = delta.length();

            // distance > 100.0 is not worth calculating
            if(distance > 100.0){
                continue;
            }

            displacement_[v] += (delta * repulsive_force(distance) / distance);
            displacement_[u] -= (delta * repulsive_force(distance) / distance);
        }
    }

    // Calculate attractive forces between edges
    for (int v = 0; v < graph_.size(); ++v) {
        for (int u : graph_.get_neighbours(v)) {
            if (u > v){
                continue;
            }
            Vector delta = positions_[v] - positions_[u];
            double distance = delta.length();
            if(distance == 0.0){
                continue;
            }
            displacement_[v] -= (delta * attractive_force(distance) / distance);
            displacement_[u] += (delta * attractive_force(distance) / distance);
        }
    }

    // Limit the maximum displacement to the temperature
    for (int v = 0; v < graph_.size(); ++v) {
        double disp_length = displacement_[v].length();
        // disp_length < 1.0 is not worth calculating
        if(disp_length < 1.0){
            continue;
        }
        positions_[v] += (displacement_[v] * std::min(t_, displacement_[v].length()) / displacement_[v].length());
    }

    // Reduce the temperature as the layout approaches a better configuration
    cool(t_);
}