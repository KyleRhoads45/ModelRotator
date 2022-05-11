#ifndef VERTEX
#define VERTEX

#include "Math/KyleMath.h"

struct Vertex {

    Vertex() = default;
    Vertex(const Vector4& position, const Vector3& normal);

    Vector4 position;
    Vector3 normal;

};


#endif