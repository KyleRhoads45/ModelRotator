#include "Shader.h"
#include "GLAD/glad.h"
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vertFile, const std::string& fragFile) {
    std::string vertCodeBuffer = LoadShaderFile(vertFile);
    std::string fragCodeBuffer = LoadShaderFile(fragFile);

    //Compile shaders
    unsigned int vertex, fragment;
    const char* vCode = vertCodeBuffer.c_str();
    const char* fCode = fragCodeBuffer.c_str();

    //Vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vCode, NULL);
    glCompileShader(vertex);
    CheckCompileErrors(vertex, "Vertex");

    //Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fCode, NULL);
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
}

void Shader::Bind() {
    glUseProgram(shaderId);
}

void Shader::SetUniformMat4(const std::string& name, const Matrix4& mat4) {
    glUniformMatrix4fv(glGetUniformLocation(shaderId, name.c_str()), 1, GL_FALSE, mat4.data);
}

std::string Shader::LoadShaderFile(const std::string& filePath) {
    std::fstream file(filePath);
    std::string codeString;

    if (file.fail()) {
        std::cout << "Failed to open " << filePath << std::endl;
        return codeString;
    }

    std::stringstream stream;
    stream << file.rdbuf();
    codeString = stream.str();

    file.close();
    return codeString;
}

void Shader::CheckCompileErrors(const unsigned int shader, const std::string& type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error within " << type << std::endl;
            std::cout << infoLog << std::endl;
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error within " << type << std::endl;
            std::cout << infoLog << std::endl;
        }
    }
}