#ifndef MESH
#define MESH

#include "Vertex.h"

struct Mesh {

    Mesh() = delete;
    Mesh(const char* modelFilePath);
    ~Mesh();

    Vertex* verts;

};

#endif