#version 460 core

in vec3 normal;
in vec2 texCoord;
in vec3 fragPos;

uniform sampler2D tex;

out vec4 FragColor;

void main() {
    vec3 lightPos = vec3(1.0, 1.0, 1.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 lightDir = normalize(lightPos - fragPos);

    //FragColor = texture(tex, texCoord);
    float ambientStrength = 0.8;
    vec3 ambientColor = lightColor * ambientStrength;

    vec3 fragNormal = normalize(normal);
    float diffuseStrength = max(dot(fragNormal, lightDir), 0.0);
    vec3 diffuseColor = lightColor * diffuseStrength;

    vec3 objColor = vec3(1.0, 0.5, 0.2);

    vec3 finalColor = (ambientColor + diffuseColor) * objColor;
    FragColor = vec4(finalColor, 1.0);
}