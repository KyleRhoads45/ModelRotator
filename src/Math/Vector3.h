#ifndef VECTOR3
#define VECTOR3

#include <iostream>

struct Vector4;

struct Vector3 {

    Vector3() = default;
    Vector3(float x, float y, float z);
    Vector3(const Vector4& vector4);

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);

#endif