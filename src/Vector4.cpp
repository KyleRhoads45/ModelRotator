#include "Vector4.h"
#include "Matrix4.h"

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

Vector4 Vector4::operator*(const Matrix4& mat4) {
    Vector4 resultVector;

    resultVector.x += mat4.data[0] * x;
    resultVector.y += mat4.data[1] * x;
    resultVector.z += mat4.data[2] * x;
    resultVector.w += mat4.data[3] * x;

    resultVector.x += mat4.data[4] * y;
    resultVector.y += mat4.data[5] * y;
    resultVector.z += mat4.data[6] * y;
    resultVector.w += mat4.data[7] * y;

    resultVector.x += mat4.data[8] * z;
    resultVector.y += mat4.data[9] * z;
    resultVector.z += mat4.data[10] * z;
    resultVector.w += mat4.data[11] * z;

    resultVector.x += mat4.data[12] * w;
    resultVector.y += mat4.data[13] * w;
    resultVector.z += mat4.data[14] * w;
    resultVector.w += mat4.data[15] * w;

    return resultVector;
}

std::ostream& operator<<(std::ostream& os, const Vector4& vector4) {
    os << "(" << vector4.x << ", " << vector4.y << ", " << vector4.z << ", " << vector4.w << ")"; 
    return os;
}