#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f
{

public:
    Vector2f();
    Vector2f(float, float);

    void add(float, float);
    void add(Vector2f);

    inline float getX() const { return x; }
    inline float getY() const { return y; }
    inline void setX(float x) { this->x = x; }
    inline void setY(float y) { this->y = y; }

private:
    float x, y;

};

#endif
