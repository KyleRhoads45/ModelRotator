#ifndef VECTOR3
#define VECTOR3

#include <iostream>

struct Vector3 {

    Vector3(float x, float y, float z);

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);

#endif