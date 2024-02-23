#include "vector_operations.h"

//Overloading Point operators
Point operator+(const Point& a, const Vector& b){
    return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point& a, const Vector& b){
    return Point(a.x - b.x, a.y - b.y);
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
Vector operator-(const Point& a, const Point& b){
    return Vector(a.x - b.x, a.y - b.y);
}
//Overloading Vector operators
Vector operator+(const Vector& a, const Vector& b){
    return Vector(a.x + b.x, a.y + b.y);
}
Vector operator-(const Vector& a, const Vector& b){
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator*(const Vector& a, double c){
    return Vector(a.x * c, a.y * c);
}
Vector operator*(double c, Vector& a){
    return a * c;
}
Vector operator/(const Vector& a, double c){
    if(c != 0.0)
        return Vector(a.x / c, a.y / c);
    else{
        double x = std::numeric_limits<double>::max();
        if (a.x < 0)
            x *= -1;
        double y = std::numeric_limits<double>::max();
        if (a.y < 0)
            y *= -1;
        return Vector(x, y);
    }
}
Vector& Vector::operator-() {
    x = -x;
    y = -y;
    return *this;
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
    if (c == 0) {
        double _x = std::numeric_limits<double>::max();
        if (x < 0)
            _x *= -1;
        double _y = std::numeric_limits<double>::max();
        if (y < 0)
            _y *= -1;
        x = _x;
        y = _y;
    } else {
        x /= c;
        y /= c;
    }
    return *this;
}


Point::operator Vector() const {
    return Vector(x, y);
}
Vector::operator Point() const {
    return Point(x, y);
}
