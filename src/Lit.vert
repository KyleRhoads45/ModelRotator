#version 460 core

layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 normal;
out vec2 texCoord;
out vec3 fragPos;

void main() {
	normal = mat3(transpose(inverse(model))) * iNormal;
	texCoord = iTexCoord;
	fragPos = vec3(model * vec4(iPos, 1.0));
	gl_Position = projection * view * model * vec4(iPos, 1.0f);
}
