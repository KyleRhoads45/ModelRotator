#include "Mat4.h"

Mat4::Mat4() {
    for (int i = 0; i < MAT4_SIZE; i++) {
        data[i] = (i % 5 == 0) ? 1.0f : 0.0f;
    }
}

void Mat4::Translate(Vector4 pos) {
    data[12] = pos.x;
    data[13] = pos.y;
    data[14] = pos.z;
}

Vector4 Mat4::operator * (const Vector4 vector4) {
    Vector4 resultVector;

    resultVector.x += data[0] * vector4.x;
    resultVector.y += data[1] * vector4.x;
    resultVector.z += data[2] * vector4.x;
    resultVector.w += data[3] * vector4.x;

    resultVector.x += data[4] * vector4.y;
    resultVector.y += data[5] * vector4.y;
    resultVector.z += data[6] * vector4.y;
    resultVector.w += data[7] * vector4.y;

    resultVector.x += data[8] * vector4.z;
    resultVector.y += data[9] * vector4.z;
    resultVector.z += data[10] * vector4.z;
    resultVector.w += data[11] * vector4.z;

    resultVector.x += data[12] * vector4.w;
    resultVector.y += data[13] * vector4.w;
    resultVector.z += data[14] * vector4.w;
    resultVector.w += data[15] * vector4.w;

    return resultVector;
}