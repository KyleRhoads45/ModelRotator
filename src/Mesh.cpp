#include "Mesh.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Mesh::Mesh(const char* modelFilePath) {
    std::string word;
    std::vector<Vertex> tempVerts;

    std::fstream file(modelFilePath, std::fstream::in);
    while (file >> word) {
        if (word == "v") {
            Vertex vert;
            file >> vert.position.x;
            file >> vert.position.y;
            file >> vert.position.z;
            tempVerts.push_back(vert);
        }
    }
    file.close();

    verts = new Vertex[tempVerts.size()];
    for (size_t i = 0; i < tempVerts.size(); i++) {
        verts[i] = tempVerts[i];
    }
}

Mesh::~Mesh() {
    delete[] verts;
}