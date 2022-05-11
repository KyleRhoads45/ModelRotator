#include "Vector3.h"
#include "Vector4.h"

Vector3::Vector3(float x, float y, float z) 
: x(x), y(y), z(z) { }

Vector3::Vector3(const Vector4& vector4) 
: x(vector4.x), y(vector4.y), z(vector4.z) { }

std::ostream& operator<<(std::ostream& os, const Vector3& vector3) {
    os << "(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")"; 
    return os;
}