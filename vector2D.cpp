#include <iostream>
#include <string>
#include "vector.hpp"

Vector2D::Vector2D() {};
Vector2D::Vector2D(int x, int y) : x(x), y(y) {}
Vector2D Vector2D::operator+(const Vector2D &other) const
{
    Vector2D resultant(x + other.x, y + other.y);

    return resultant;
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    Vector2D resultant(x - other.x, y - other.y);

    return resultant;
}