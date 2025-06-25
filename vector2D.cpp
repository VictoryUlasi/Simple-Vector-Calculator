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

Vector2D Vector2D::operator*(int scalar) const
{
    Vector2D resultant(scalar * x, scalar * y);

    return resultant;
}

int Vector2D::dotProduct(const Vector2D &other) const
{
    int resultantScalar = (x * other.x) + (y * other.y);

    return resultantScalar;
}