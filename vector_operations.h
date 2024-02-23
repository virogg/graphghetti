#ifndef GRAPHGHETTI_VECTOR_OPERATIONS_H
#define GRAPHGHETTI_VECTOR_OPERATIONS_H

#include "cmath"

struct Vector{
    double x;
    double y;

    double normalize(){
        return std::sqrt(x*x + y*y);
    }

    Vector& operator+=(const Vector& a);
    Vector& operator-=(const Vector& a);
    Vector& operator*=(double c);
    Vector& operator/=(double c);
};
struct Point{
    double x;
    double y;

    Point& operator+=(const Vector& a);
    Point& operator-=(const Vector& a);
};
// Операции линейного пространства
Point operator+(const Point& a, const Vector& b);
Point operator-(const Point& a, const Vector& b);
// Операции над векторами
Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator*(const Vector& a, double c);
Vector operator*(double c, const Vector& a);
Vector operator/(const Vector& a, double c);







#endif //GRAPHGHETTI_VECTOR_OPERATIONS_H
