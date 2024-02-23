#ifndef GRAPHGHETTI_BMP_H
#define GRAPHGHETTI_BMP_H
#include "cmath"
#include "vector"

struct BMPFileHeader {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
};

struct BMPInfoHeader {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};
#pragma pack(pop)

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

void writeBMP(const char* filename, int width, int height, const std::vector<Pixel>& pixels);

void drawCircle(std::vector<Pixel>& pixels, int width, int x, int y, int radius, Pixel color);

void drawLine(std::vector<Pixel>& pixels, int width, int x1, int y1, int x2, int y2, Pixel color);


#endif //GRAPHGHETTI_BMP_H
