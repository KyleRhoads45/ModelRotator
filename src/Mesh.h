#ifndef MESH
#define MESH

#include "Vertex.h"
#include <vector>

struct Mesh {

    Mesh() = delete;
    Mesh(const char* modelFilePath);

    std::vector<Vertex> verts;
    std::vector<unsigned int> indicies;

};

#endif