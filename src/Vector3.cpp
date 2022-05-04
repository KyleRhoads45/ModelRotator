#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

std::ostream& operator<<(std::ostream& os, const Vector3& vector3) {
    os << "(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")"; 
    return os;
}