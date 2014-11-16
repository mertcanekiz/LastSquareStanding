#include "Vector2f.h"

Vector2f::Vector2f() : Vector2f(0, 0) { }

Vector2f::Vector2f(float x, float y) : x(x), y(y) { }

void Vector2f::add(float x, float y)
{
    this->x += x;
    this->y += y;
}

void Vector2f::add(Vector2f v)
{
    this->x += v.getX();
    this->y += v.getY();
}
