#ifndef MATRIX4
#define MATRIX4

#include "Vector4.h"
#define MATRIX4_SIZE 16

struct Matrix4 {

    Matrix4();
    void Translate(const Vector4& pos);
    Vector4 operator*(const Vector4& vector4);

    float data[MATRIX4_SIZE];

};

std::ostream& operator<<(std::ostream& os, const Matrix4& mat4);

#endif