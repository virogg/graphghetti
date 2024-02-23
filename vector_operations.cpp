#include "vector_operations.h"

//Overloading Point operators
Point operator+(const Point& a, const Vector& b){
    return {a.x + b.x, a.y + b.y};
}
Point operator-(const Point& a, const Vector& b){
    return {a.x - b.x, a.y - b.y};
}
Point& Point::operator+=(const Vector& a){
    x += a.x;
    y += a.y;
    return *this;
}
Point& Point::operator-=(const Vector& a){
    x -= a.x;
    y -= a.y;
    return *this;
}
//Overloading Vector operators
Vector operator+(const Vector& a, const Vector& b){
    return {a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector& a, const Vector& b){
    return {a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector& a, double c){
    return {a.x * c, a.y * c};
}
Vector operator*(double c, Vector& a){
    return a * c;
}
Vector operator/(const Vector& a, double c){
    return {a.x / c, a.y / c};
}
Vector& Vector::operator+=(const Vector &a) {
    x += a.x;
    y += a.y;
    return *this;
}
Vector& Vector::operator-=(const Vector &a) {
    x -= a.x;
    y -= a.y;
    return *this;
}
Vector& Vector::operator*=(double c) {
    x *= c;
    y *= c;
    return *this;
}
Vector& Vector::operator/=(double c) {
    x /= c;
    y /= c;
    return *this;
}