#version 460 core

layout (location = 0) in vec4 iPos;
layout (location = 1) in vec3 iNormal;

out vec3 normal;
out vec3 fragPos;

void main() {
	normal = iNormal;
	fragPos = vec3(iPos);
	gl_Position = iPos;
}
