#include "bmp_processor.h"
#include <fstream>
#include "map"
#include "iostream"

bool operator==(const Pixel &a, const Pixel &b){
    return (a.blue == b.blue) && (a.green == b.green) && (a.red == b.red);
}
bool operator!=(const Pixel& a, const Pixel& b) {
    return !(a == b);
}

void BMPProcessor::drawCircle(int64_t x, int64_t y, int radius, const Pixel& color) {
    for (int64_t i = x - radius; i <= x + radius; ++i) {
        for (int64_t j = y - radius; j <= y + radius; ++j) {
            if (sqrt((i - x) * (i - x) + (j - y) * (j - y)) <= radius) {
                if (i >= 0 && i < width_ && j >= 0 && j < pixels_.size() / width_) {
                    pixels_[j * width_ + i] = color;
                }
            }
        }
    }
}

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void BMPProcessor::drawLine(int64_t x1, int64_t y1, int64_t x2, int64_t y2, const Pixel &color) {
    int64_t dx = abs(x2 - x1);
    int64_t dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int64_t err = (dx > dy ? dx : -dy) / 2;
    int64_t e2;

    while (true) {
        if (x1 >= 0 && x1 < width_ && y1 >= 0 && y1 < height_) {
            pixels_[y1 * width_ + x1] = color;
        }

        if (x1 == x2 && y1 == y2) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

void BMPProcessor::drawDigit(int digit, const Pixel& digitColor, int64_t startX, int64_t startY) {
    std::map<int, std::vector<Point>> points = {
            {0, {Point(1, 12), Point(8, 12), Point(8, 1), Point(1, 1), Point(1, 12)}},
            {1, {Point(3,9), Point(6,12), Point(6,1)}},
            {2, {Point(1, 12), Point(8, 12), Point(8, 7), Point(1, 7), Point(1, 1), Point(8, 1)}},
            {3, {Point(1, 12), Point(8, 12), Point(1, 7), Point(8, 7), Point(8, 1), Point(1,1)}},
            {4, {Point(8, 1), Point(8, 12), Point(1, 7), Point(8, 7)}},
            {5, {Point(8, 12), Point(1, 12), Point(1, 7), Point(8, 7), Point(8, 1), Point(1, 1)}},
            {6, {Point(8, 12), Point(1, 12), Point(1, 1), Point(8, 1), Point(8, 7), Point(1, 7)}},
            {7, {Point(1, 12), Point(8, 12), Point(8,1)}},
            {8, {Point(8, 7), Point(8, 12), Point(1, 12), Point(1, 1), Point(8, 1), Point(8, 7), Point(1, 7)}},
            {9, {Point(1, 1), Point(8,1), Point(8, 7), Point(8, 12), Point(1, 12), Point(1, 7), Point(8, 7)}}
    };

    for (size_t i = 0; i < points[digit].size() - 1; ++i) {
        int64_t x1 = startX + points[digit][i].x;
        int64_t y1 = startY + points[digit][i].y;
        int64_t x2 = startX + points[digit][i + 1].x;
        int64_t y2 = startY + points[digit][i + 1].y;
        drawLine(x1, y1, x2, y2, digitColor);
    }
}

void BMPProcessor::drawNumber(int number, const Pixel& numberColor, int64_t startX, int64_t startY) {
    if(number){
        std::vector<int> d;
        while(number){
            d.push_back(number % 10);
            number /= 10;
        }
        std::reverse(d.begin(), d.end());
        for(int i = 0; i < d.size(); ++i){
            drawDigit(d[i], numberColor, startX + i * 9, startY);
        }
    } else{
        drawDigit(number, numberColor, startX, startY);
    }
}

void BMPProcessor::drawGraph(const std::vector<Point> &positions, const Graph &g) {
    // Draw vertices
    for (auto p : positions) {
        drawCircle(p.x, p.y, 7, black_);
    }

    // Draw edges
    for (int i = 0; i < g.size(); i++) {
        for (auto j : g.get_neighbours(i)) {
            if (j > i) continue;
            drawLine(positions[i].x, positions[i].y, positions[j].x, positions[j].y, black_);
        }
    }

    // Draw numbers
    for (int v = 0; v < g.size(); ++v) {
        auto p = positions[v];
        drawNumber(v, {0,0,255}, p.x + 15, p.y);
    }
}

void BMPProcessor::saveImage(const std::string& filename) {
    std::ofstream out_file(filename, std::ios::out | std::ios::binary);
    if (!out_file) {
        std::cerr << "Error: Unable to create BMP file." << "\n";
        return;
    }

    out_file.write(reinterpret_cast<const char*>(&fileHeader_), sizeof(BMPFileHeader));
    out_file.write(reinterpret_cast<const char*>(&infoHeader_), sizeof(BMPInfoHeader));
    out_file.write(reinterpret_cast<const char*>(pixels_.data()), width_ * height_ * sizeof(Pixel));
    out_file.close();

    std::cout << "Image generated successfully!\n";
}
