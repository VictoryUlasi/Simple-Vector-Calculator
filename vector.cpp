#include <iostream>
#include <string>
#include "vector.hpp"

// 2D VECTORS
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

// 3D VECTORS
Vector3D::Vector3D() {};
Vector3D::Vector3D(int x, int y, int z) : x(x), y(y), z(z) {}

Vector3D Vector3D::operator+(const Vector3D &other) const
{
    Vector3D resultant(x + other.x, y + other.y, z + other.z);

    return resultant;
}
Vector3D Vector3D::operator-(const Vector3D &other) const
{
    Vector3D resultant(x - other.x, y - other.y, z - other.z);

    return resultant;
}
Vector3D Vector3D::operator*(int scalar) const
{
    Vector3D resultant(scalar * x, scalar * y, scalar * z);

    return resultant;
}
int Vector3D::dotProduct(const Vector3D &other) const
{
    int resultantScalar = (x * other.x) + (y * other.y) + (z * other.z);

    return resultantScalar;
}
Vector3D Vector3D::crossProduct(const Vector3D &other) const
{
    Vector3D resultant(((y * other.z) - (z * other.y)), ((z * other.x) - (x * other.z)), ((x * other.y) - (y * other.x)));

    return resultant;
}