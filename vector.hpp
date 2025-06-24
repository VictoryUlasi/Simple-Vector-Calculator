#pragma once

class Vector2D
{
public:
    int x, y;

    Vector2D();
    Vector2D(int x, int y);

    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
};

class Vector3D
{
};