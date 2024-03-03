#ifndef GRAPHGHETTI_VECTOR_OPERATIONS_H
#define GRAPHGHETTI_VECTOR_OPERATIONS_H

#include "cmath"
#include <climits>

struct Point;

struct Vector{
    int x;
    int y;

    explicit Vector(int x = 0, int y = 0) : x(x), y(y) {}

    explicit operator Point() const;

    [[nodiscard]] double length() const{
        return std::sqrt(x*x + y*y);
    }

    Vector& operator-();
    Vector& operator+=(const Vector& a);
    Vector& operator-=(const Vector& a);
    Vector& operator*=(double c);
    Vector& operator/=(double c);
};

struct Point{
    int x;
    int y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}

    explicit operator Vector() const;

    Point& operator+=(const Vector& a);
    Point& operator-=(const Vector& a);
};

// Linear Space operations
Point operator+(const Point& a, const Vector& b);
Point operator-(const Point& a, const Vector& b);
Vector operator-(const Point& a, const Point& b);

// Vector operations
Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(const Vector& a, double c);
Vector operator*(double c, const Vector& a);
Vector operator/(const Vector& a, double c);

#endif //GRAPHGHETTI_VECTOR_OPERATIONS_H
