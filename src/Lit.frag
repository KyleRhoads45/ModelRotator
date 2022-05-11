#version 460 core

in vec3 normal;
in vec3 fragPos;

out vec4 FragColor;

void main() {
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 lightDir = -vec3(-0.2, -1.0, -0.3);

    float ambientStrength = 1.2;
    vec3 ambientColor = lightColor * ambientStrength;

    vec3 fragNormal = normalize(normal);
    float diffuseStrength = max(dot(fragNormal, lightDir), 0.0);
    vec3 diffuseColor = lightColor * diffuseStrength;

    vec3 objColor = vec3(0.5, 0.5, 0.5);

    vec3 finalColor = (ambientColor + diffuseColor) * objColor;
    FragColor = vec4(finalColor, 1.0);
}