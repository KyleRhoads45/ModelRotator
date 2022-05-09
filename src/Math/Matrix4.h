#ifndef MATRIX4
#define MATRIX4

#include <iostream>
struct Vector4;
#define MATRIX4_SIZE 16

struct Matrix4 {

    Matrix4();
    Matrix4(float newData[]);

    void Perspective();
    void Translate(const Vector4& pos);
    void Rotate(float deg);
    float MultiplyRowByCol(const Matrix4& rowMat, int rowIndex, const Matrix4& colMat, int colIndex);

    Vector4 operator*(const Vector4& vec4);
    Matrix4 operator*(const Matrix4& mat4);

    float* dataPtr;
    float data[MATRIX4_SIZE];

};

std::ostream& operator<<(std::ostream& os, const Matrix4& mat4);

#endif