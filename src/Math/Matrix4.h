#ifndef MATRIX4
#define MATRIX4

#include <iostream>
#define MATRIX4_SIZE 16

struct Vector4;

struct Matrix4 {

    Matrix4();
    Matrix4(float newData[]);

    Vector4 operator*(const Vector4& vec4);
    Matrix4 operator*(const Matrix4& mat4);

    static Matrix4 Translate(const Matrix4& mat4, const Vector4& translation);
    static Matrix4 RotateYAxis(const Matrix4& mat4, const float degrees);

    static Matrix4 Perspective();
    static Matrix4 Multiply(const Matrix4& mat1, const Matrix4& mat2);
    static float MultiplyRowByCol(const Matrix4& rowMat, const int rowIndex, const Matrix4& colMat, const int colIndex);

    float data[MATRIX4_SIZE];

};

std::ostream& operator<<(std::ostream& os, const Matrix4& mat4);

#endif