#ifndef SHADER
#define SHADER

#include "Math/KyleMath.h"
#include <string>

class Shader {
    
public:

    Shader() = delete;
    Shader(const std::string& vertFile, const std::string& fragFile);

    void Bind();
    void EnableTextureUnit(int texUnit);
    void SetUniformMat4(const std::string& name, const Matrix4& mat4);

private:

    char* LoadShaderFile(const std::string& filePath);
    void CheckCompileErrors(const unsigned int shader, const std::string& type);

    unsigned int shaderId; 

};

#endif