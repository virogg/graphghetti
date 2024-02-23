#include "BMP.h"
#include "fstream"
#include "iostream"

void writeBMP(const char* filename, int width, int height, const std::vector<Pixel>& pixels) {
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fileHeader.type = 0x4D42; // "BM"
    fileHeader.size = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + width * height * sizeof(Pixel);
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    fileHeader.offset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.planes = 1;
    infoHeader.bitCount = 24;
    infoHeader.compression = 0;
    infoHeader.imageSize = 0;
    infoHeader.xPixelsPerMeter = 0;
    infoHeader.yPixelsPerMeter = 0;
    infoHeader.colorsUsed = 0;
    infoHeader.colorsImportant = 0;

    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Unable to create BMP file.\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&fileHeader), sizeof(BMPFileHeader));
    outFile.write(reinterpret_cast<const char*>(&infoHeader), sizeof(BMPInfoHeader));
    outFile.write(reinterpret_cast<const char*>(pixels.data()), width * height * sizeof(Pixel));
    outFile.close();

    std::cout << "Image generated successfully!\n";
}

void drawCircle(std::vector<Pixel>& pixels, int width, int x, int y, int radius, Pixel color) {
    for (int i = x - radius; i <= x + radius; ++i) {
        for (int j = y - radius; j <= y + radius; ++j) {
            if (sqrt((i - x) * (i - x) + (j - y) * (j - y)) <= radius) {
                if (i >= 0 && i < width && j >= 0 && j < pixels.size() / width) {
                    pixels[j * width + i] = color;
                }
            }
        }
    }
}

void drawLine(std::vector<Pixel>& pixels, int width, int x1, int y1, int x2, int y2, Pixel color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < pixels.size() / width) {
            pixels[y1 * width + x1] = color;
        }
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}