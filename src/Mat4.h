#include "Vector4.h"

#ifndef MAT4
#define MAT4

#define MAT4_SIZE 16

class Mat4 {

public:

    Mat4();
    void Translate(Vector4 pos);
    Vector4 operator * (const Vector4 vector4);

private:

    float data[MAT4_SIZE];

};

#endif