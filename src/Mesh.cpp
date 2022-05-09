#include "Mesh.h"
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Mesh::Mesh(const char* modelFilePath) {
    unsigned int curIndex = 0;
    std::vector<Vertex> tempVerts;
    std::vector<unsigned int> tempIndicies;

    std::vector<Vector3> positions;
    std::vector<Vector3> normals;
    std::vector<Vector2> textureCoords;

    std::string word;
    std::fstream file(modelFilePath, std::fstream::in);
    while (file >> word) {
        if (word == "v") {
            Vector3 pos;
            file >> pos.x >> pos.y >> pos.z;
            positions.push_back(pos);
            continue;
        }
        if (word == "vt") {
            Vector2 texCoord;
            file >> texCoord.x >> texCoord.y; 
            textureCoords.push_back(texCoord);
            continue;
        }
        if (word == "vn") {
            Vector3 normal;
            file >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
            continue;
        }
        if (word == "f") {
            std::string vertString;
            for (int i = 0; i < 4; i++) {
                file >> vertString;
                int posIndex, texCoordIndex, normalIndex;
                sscanf(vertString.c_str(), "%d/%d/%d", &posIndex, &texCoordIndex, &normalIndex);
                tempVerts.push_back(Vertex(positions[posIndex - 1], normals[normalIndex - 1], textureCoords[texCoordIndex - 1]));
            }

            tempIndicies.push_back(curIndex);
            tempIndicies.push_back(curIndex + 1);
            tempIndicies.push_back(curIndex + 2);

            tempIndicies.push_back(curIndex);
            tempIndicies.push_back(curIndex + 2);
            tempIndicies.push_back(curIndex + 3);

            curIndex += 4; 
        }
    }
    file.close();

    vertCount = tempVerts.size();
    verts = new Vertex[vertCount];
    for (int i = 0; i < vertCount; i++) {
        verts[i] = tempVerts[i];
    }

    indexCount = tempIndicies.size();
    indicies = new unsigned int[indexCount];
    for (int i = 0; i < indexCount; i++) {
        indicies[i] = tempIndicies[i];
    }
}

Mesh::~Mesh() {
    delete[] verts;
}