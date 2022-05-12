#ifndef SHADER
#define SHADER

#include "math/KyleMath.h"
#include <string>

class Shader {
    
public:

    Shader() = delete;
    Shader(const std::string& vertFile, const std::string& fragFile);

    void Bind();
    void SetUniformMat4(const std::string& name, const Matrix4& mat4);

private:

    std::string LoadShaderFile(const std::string& filePath);
    void CheckCompileErrors(const unsigned int shader, const std::string& type);

    unsigned int shaderId; 

};

#endif