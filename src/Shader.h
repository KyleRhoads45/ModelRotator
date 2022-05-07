#ifndef SHADER
#define SHADER

#include <string>

class Shader {
    
public:

    Shader() = delete;
    Shader(const std::string& vertFile, const std::string& fragFile);

    void Bind();
    void EnableTextureUnit(int texUnit);

private:

    char* LoadShaderFile(const std::string& filePath);
    void CheckCompileErrors(const unsigned int shader, const std::string& type);

    unsigned int shaderId; 

};

#endif