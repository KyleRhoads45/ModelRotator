#include <stdio.h>
#include "Vector4.h"

Vector4::Vector4(float x, float y, float z, float w) 
: x(x), y(y), z(z), w(w) { }

void Vector4::Print() {
    printf("(%.2f, %.2f, %.2f)\n", x, y, z);
}