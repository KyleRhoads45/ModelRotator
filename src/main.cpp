#include <iostream>
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "Math/KyleMath.h"
#include "Mesh.h"
#include "Shader.h"

int main(void) {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    } 

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Model Rotator (340,000 verts)", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    Mesh mesh("spider.obj");
    Shader shader("Lit.vert", "Lit.frag");
    shader.Bind();

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh.indicies.size(), mesh.indicies.data(), GL_STATIC_DRAW);

    std::vector<Vertex> rotatedVerts = mesh.verts;

    Matrix4 proj = Matrix4::Perspective();
    Matrix4 model = Matrix4::Translate(Matrix4(1.0f), Vector4(0.0f, -0.3f, -4.5f, 1.0f));

    float rot = 0.0f;
    while (!glfwWindowShouldClose(window)) {

        glad_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

        Matrix4 rotModel = Matrix4::RotateYAxis(model, rot);
        for (size_t i = 0; i < mesh.verts.size(); i++) {
            Vector4 pos = mesh.verts[i].position;
            Vector4 normal = (Vector4)mesh.verts[i].normal; 

            rotatedVerts[i].position = proj * rotModel * pos;
            rotatedVerts[i].normal = (Vector3)(proj * rotModel * normal);
        }
        rot += 0.5f;

        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh.verts.size(), rotatedVerts.data(), GL_STATIC_DRAW);
        glDrawElements(GL_TRIANGLES, mesh.indicies.size(), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}