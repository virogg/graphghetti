#ifndef GRAPHGHETTI_VECTOR_OPERATIONS_H
#define GRAPHGHETTI_VECTOR_OPERATIONS_H

#include "cmath"

struct Point;

struct Vector{
    double x;
    double y;

    explicit Vector(double x = 0, double y = 0) : x(x), y(y) {}

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
    double x;
    double y;

    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}

    explicit operator Vector() const;

    Point& operator+=(const Vector& a);
    Point& operator-=(const Vector& a);
};
// Операции линейного пространства
Point operator+(const Point& a, const Vector& b);
Point operator-(const Point& a, const Vector& b);
Vector operator-(const Point& a, const Point& b);
// Операции над векторами
Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(const Vector& a, double c);
Vector operator*(double c, const Vector& a);
Vector operator/(const Vector& a, double c);







#endif //GRAPHGHETTI_VECTOR_OPERATIONS_H
