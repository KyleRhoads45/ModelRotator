#ifndef VECTOR2
#define VECTOR2

#include <iostream>

struct Vector2 {

    Vector2() = default;
    Vector2(float x, float y);

    float x = 0.0f;
    float y = 0.0f;

};

std::ostream& operator<<(std::ostream& os, const Vector2& vector2);

#endif