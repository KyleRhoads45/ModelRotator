#include "Shader.h"
#include "GLAD/glad.h"
#include <iostream>
#include <fstream>

Shader::Shader(const std::string& vertFile, const std::string& fragFile) {
    char* vertCodeBuffer = LoadShaderFile(vertFile);
    char* fragCodeBuffer = LoadShaderFile(fragFile);

    //Compile shaders
    unsigned int vertex, fragment;

    //Vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertCodeBuffer, NULL);
    glCompileShader(vertex);
    CheckCompileErrors(vertex, "Vertex");

    //Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragCodeBuffer, NULL);
    glCompileShader(fragment);
    CheckCompileErrors(fragment, "Fragment");

    //Shader Program
    shaderId = glCreateProgram();
    glAttachShader(shaderId, vertex);
    glAttachShader(shaderId, fragment);
    glLinkProgram(shaderId);
    CheckCompileErrors(shaderId, "Shader Linking");

    //Delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    delete[] vertCodeBuffer;
    delete[] fragCodeBuffer;
}

void Shader::Bind() {
    glUseProgram(shaderId);
}

void Shader::EnableTextureUnit(int texUnit) {
    glUniform1iv(glGetUniformLocation(shaderId, "tex"), 1, &texUnit);
}

char* Shader::LoadShaderFile(const std::string& filePath) {
    std::fstream file(filePath);

    if (file.fail()) {
        std::cout << "Failed to open " << filePath << std::endl;
        return 0;
    }

    file.seekg(0, file.end);
    int codeLength = file.tellg();
    file.seekg(0, file.beg);

    char* codeBuffer = new char[codeLength] { '\0' };
    file.rdbuf()->sgetn(codeBuffer, codeLength);

    file.close();
    return codeBuffer;
}

void Shader::CheckCompileErrors(const unsigned int shader, const std::string& type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error within " << type << std::endl;
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error within " << type << std::endl;
        }
    }
}