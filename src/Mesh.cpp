#include "Mesh.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Mesh::Mesh(const char* modelFilePath) {
    std::string word;
    std::vector<Vertex> tempVerts;

    int curTexCoordIndex = 0;

    std::fstream file(modelFilePath, std::fstream::in);
    while (file >> word) {
        if (word == "v") {
            Vertex vert;
            file >> vert.position.x;
            file >> vert.position.y;
            file >> vert.position.z;
            tempVerts.push_back(vert);
        }

        if (word == "vt") {
            Vertex& vert = tempVerts[curTexCoordIndex];
            file >> vert.texCoord.x;
            file >> vert.texCoord.y;

            std::cout << vert.texCoord << std::endl;
            curTexCoordIndex++;
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