#include "Vector4.h"
#include "Matrix4.h"

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

std::ostream& operator<<(std::ostream& os, const Vector4& vector4) {
    os << "(" << vector4.x << ", " << vector4.y << ", " << vector4.z << ", " << vector4.w << ")"; 
    return os;
}