#ifndef VECTOR4
#define VECTOR4

#include <iostream>
//#include "Matrix4.h"
struct Matrix4;

struct Vector4 {

    Vector4() = default;
    Vector4(float x, float y, float z, float w);

    Vector4 operator*(const Matrix4& mat4); 

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 1.0f;

};

std::ostream& operator<<(std::ostream& os, const Vector4& vector4);

#endif