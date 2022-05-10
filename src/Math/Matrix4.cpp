#include "Matrix4.h"
#include "Vector4.h"
#define _USE_MATH_DEFINES
#include <math.h>

Matrix4::Matrix4() {
    for (int i = 0; i < MATRIX4_SIZE; i++) {
        data[i] = (i % 5 == 0) ? 1.0f : 0.0f;
    }
}

Matrix4::Matrix4(float data[]) {
    for (int i = 0; i < MATRIX4_SIZE; i++) {
        this->data[i] = data[i];
    }
}

void Matrix4::Perspective() {
    data[0] = 1.357995f;
    data[5] = 2.414213f;
    data[10] = -1.002002;  
    data[11] = -1.0f;
    data[14] = -0.200200f; 
}

void Matrix4::Translate(const Vector4& pos) {
    data[12] = pos.x;
    data[13] = pos.y;
    data[14] = pos.z;
}

void Matrix4::Rotate(float deg) {
    Matrix4 rotMat;
    float rad = deg * (M_PI / 180);
    rotMat.data[0] = cos(rad);
    rotMat.data[2] = -sin(rad);
    rotMat.data[8] = sin(rad);
    rotMat.data[10] = cos(rad);

    *this = *this * rotMat; 
}

float Matrix4::MultiplyRowByCol(const Matrix4& rowMat, int rowIndex, const Matrix4& colMat, int colIndex) {
    float result = 0.0f;
    for (int i = 0; i < 4; i++) {
        result += rowMat.data[rowIndex + (i * 4)] * colMat.data[(colIndex * 4) + i];
    }
    return result;
}

Vector4 Matrix4::operator*(const Vector4& vec4) {
    return Vector4 (
        (data[0] * vec4.x) + (data[4] * vec4.y) + (data[8]  * vec4.z) + (data[12] * vec4.w),
        (data[1] * vec4.x) + (data[5] * vec4.y) + (data[9]  * vec4.z) + (data[13] * vec4.w),
        (data[2] * vec4.x) + (data[6] * vec4.y) + (data[10] * vec4.z) + (data[14] * vec4.w),
        (data[3] * vec4.x) + (data[7] * vec4.y) + (data[11] * vec4.z) + (data[15] * vec4.w)
    );
}

Matrix4 Matrix4::operator*(const Matrix4& mat4) {
    float data[] = {
        MultiplyRowByCol(*this, 0, mat4, 0), 
        MultiplyRowByCol(*this, 1, mat4, 0),
        MultiplyRowByCol(*this, 2, mat4, 0),
        MultiplyRowByCol(*this, 3, mat4, 0),

        MultiplyRowByCol(*this, 0, mat4, 1), 
        MultiplyRowByCol(*this, 1, mat4, 1),
        MultiplyRowByCol(*this, 2, mat4, 1),
        MultiplyRowByCol(*this, 3, mat4, 1),

        MultiplyRowByCol(*this, 0, mat4, 2), 
        MultiplyRowByCol(*this, 1, mat4, 2),
        MultiplyRowByCol(*this, 2, mat4, 2),
        MultiplyRowByCol(*this, 3, mat4, 2),

        MultiplyRowByCol(*this, 0, mat4, 3), 
        MultiplyRowByCol(*this, 1, mat4, 3),
        MultiplyRowByCol(*this, 2, mat4, 3),
        MultiplyRowByCol(*this, 3, mat4, 3)
    };

    return Matrix4(data);
}

std::ostream& operator<<(std::ostream& os, const Matrix4& mat4) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            os << mat4.data[i + (j * 4)] << " ";
        }
        os << "\n";
    }
    return os;
}