#include "Vector4.h"

#ifndef MATRIX4
#define MATRIX4

#define MATRIX4_SIZE 16

class Matrix4 {

public:

    Matrix4();
    void Translate(Vector4 pos);
    Vector4 operator * (const Vector4 vector4);

private:

    float data[MATRIX4_SIZE];

};

#endif