#pragma once

class Vector2D
{
public:
    int x, y;

    Vector2D();
    Vector2D(int x, int y);

    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
    Vector2D operator*(int scalar) const;
    int dotProduct(const Vector2D &other) const;
};

class Vector3D
{
public:
    int x, y, z;

    Vector3D();
    Vector3D(int x, int y, int z);

    Vector3D operator+(const Vector3D &other) const;
    Vector3D operator-(const Vector3D &other) const;
    Vector3D operator*(int scalar) const;
    int dotProduct(const Vector3D &other) const;
    Vector3D crossProduct(const Vector3D &other) const;
};