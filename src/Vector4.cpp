#include <stdio.h>
#include "Vector4.h"

Vector4::Vector4(float x, float y, float z) 
: x(x), y(y), z(z), w(1.0f) { }

void Vector4::Print() {
    printf("(%.2f, %.2f, %.2f)\n", x, y, z);
}