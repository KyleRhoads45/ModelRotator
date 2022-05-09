#ifndef MESH
#define MESH

#include "Vertex.h"

struct Mesh {

    Mesh() = delete;
    Mesh(const char* modelFilePath);
    ~Mesh();

    Vertex* verts;
    unsigned int* indicies;

    int vertCount = 0;
    int indexCount = 0; 

};

#endif