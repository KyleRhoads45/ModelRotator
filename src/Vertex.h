#ifndef VERTEX
#define VERTEX

#include "Math/KyleMath.h"

struct Vertex {

    Vertex() = default;
    Vertex(const Vector3& position, const Vector3& normal, const Vector2& texCoord);

    Vector3 position;
    Vector3 normal;
    Vector2 texCoord;

};


#endif