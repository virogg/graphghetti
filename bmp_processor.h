#ifndef GRAPHGHETTI_BMP_PROCESSOR_H
#define GRAPHGHETTI_BMP_PROCESSOR_H

#include "graph.h"
#include "string"
#pragma once

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};
bool operator==(const Pixel &a, const Pixel &b);
bool operator!=(const Pixel &a, const Pixel &b);

#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t type{0x4D42};
    uint32_t size{0};
    uint16_t unused[2]{0};
    uint32_t offset{0};
};

struct BMPInfoHeader {
    uint32_t size{0};
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bitCount{24};
    uint32_t unused[6]{0};
};
#pragma pack(pop)

class BMPProcessor {
public:
    BMPProcessor(int width, int height) : width_(width), height_(height) {
        fileHeader_.size = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + width * height * sizeof(Pixel);
        fileHeader_.offset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

        infoHeader_.size = sizeof(BMPInfoHeader);
        infoHeader_.width = width;
        infoHeader_.height = height;

        // Set background color to white
        pixels_.resize(width * height, {255, 255, 255});

    }

    void drawGraph(const std::vector<Point>& positions, const Graph& g);
    void saveImage(const std::string& filename);

private:
    BMPFileHeader fileHeader_;
    BMPInfoHeader infoHeader_;
    const int width_;
    const int height_;
    std::vector<Pixel> pixels_;
    Pixel black = {0, 0, 0};

    void drawLine(int64_t x1, int64_t y1, int64_t x2, int64_t y2, const Pixel& color);
    void drawCircle(int64_t x, int64_t y, int radius, const Pixel& color);
    void drawDigit(int digit, const Pixel& digitColor, int64_t startX, int64_t startY);
    void drawNumber(int number, const Pixel& numberColor, int64_t startX, int64_t startY);
};


#endif //GRAPHGHETTI_BMP_PROCESSOR_H
