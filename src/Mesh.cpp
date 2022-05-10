#include "Mesh.h"
#include <vector>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Mesh::Mesh(const char* modelFilePath) {
    int curVertIndex = 0;
    std::vector<Vertex> tempVerts;
    std::vector<unsigned int> tempIndicies;

    std::vector<Vector3> positions;
    std::vector<Vector3> normals;
    std::vector<Vector2> texCoords;

    const char* space = " ";
    const int lineLength = 100;
    char line[lineLength];

    std::fstream file(modelFilePath, std::fstream::in);
    std::stringstream fileStringStream;
    fileStringStream << file.rdbuf();
    file.close();

    while (fileStringStream.getline(line, lineLength)) {
        std::string linetype = strtok(line, space);

        if (linetype == "v") {
            Vector3 pos;
            pos.x = atof(strtok(NULL, space));
            pos.y = atof(strtok(NULL, space));
            pos.z = atof(strtok(NULL, space));
            positions.push_back(pos);
            continue;
        }

        if (linetype == "vt") {
            Vector2 texCoord;
            texCoord.x = atof(strtok(NULL, space));
            texCoord.y = atof(strtok(NULL, space));
            texCoords.push_back(texCoord);
            continue;
        }

        if (linetype == "vn") {
            Vector3 normal;
            normal.x = atof(strtok(NULL, space));
            normal.y = atof(strtok(NULL, space));
            normal.z = atof(strtok(NULL, space));
            normals.push_back(normal);
            continue;
        }

        if (linetype == "f") {
            int faceVertCount = 0;
            char* faceInstr = strtok(NULL, space); 

            while (faceInstr != NULL) {
                int posIndex, texCoordIndex, normalIndex;
                sscanf(faceInstr, "%d/%d/%d", &posIndex, &texCoordIndex, &normalIndex);

                tempVerts.push_back(Vertex(positions[posIndex - 1], normals[normalIndex - 1], texCoords[texCoordIndex - 1]));

                faceInstr = strtok(NULL, space); 
                faceVertCount++;
            }

            for (int i = 1; i < faceVertCount - 1; i++) {
                tempIndicies.push_back(curVertIndex);
                tempIndicies.push_back(curVertIndex + i);
                tempIndicies.push_back(curVertIndex + i + 1);
            }

            curVertIndex += faceVertCount;
        }
    }

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