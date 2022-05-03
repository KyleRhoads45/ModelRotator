#ifndef VECTOR4
#define VECTOR4

struct Vector4 {

    Vector4() = default;
    Vector4(float x, float y, float z);

    void Print();

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 1.0f;

};

#endif