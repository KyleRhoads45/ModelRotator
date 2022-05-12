#include <iostream>
#include <omp.h>
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "math/KyleMath.h"
#include "Mesh.h"
#include "Shader.h"
#include "Timer.h"

GLFWwindow* InitOpenGL() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        exit(-1);
    } 

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Model Rotator (340,000 verts)", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        exit(-1);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    return window;
}

void InitRenderBuffer(const Mesh& mesh) {
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
}

bool RotateMesh(const Mesh& mesh) {
    static float curRotation = 0.0f;
    static int vertCount = mesh.verts.size();
    static std::vector<Vertex> rotatedVerts = mesh.verts;

    static Matrix4 proj = Matrix4::Perspective();
    static Matrix4 model = Matrix4::Translate(Matrix4(1.0f), Vector4(0.0f, -0.3f, -5.0f, 1.0f));
    Matrix4 rotModel = Matrix4::RotateYAxis(model, curRotation);

    #ifdef OPEN_MP
    #pragma omp parallel for shared(proj, rotModel, mesh, rotatedVerts)
    #endif
    for (int i = 0; i < vertCount; i++) {
        Vector4 pos = mesh.verts[i].position;
        Vector4 normal = mesh.verts[i].normal; 

        rotatedVerts[i].position = proj * rotModel * pos;
        rotatedVerts[i].normal = proj * rotModel * normal;
    }

    curRotation += 1.0f;
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh.verts.size(), rotatedVerts.data(), GL_STATIC_DRAW);

    return (curRotation >= 360);
}

int main(void) {
    GLFWwindow* window = InitOpenGL();

    Mesh mesh("models/spider.obj");
    Shader shader("shaders/Lit.vert", "shaders/Lit.frag");

    InitRenderBuffer(mesh);

    Timer timer;
    timer.StartTimer();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glad_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

        if (RotateMesh(mesh)) break;

        glDrawElements(GL_TRIANGLES, mesh.indicies.size(), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
    }

    std::cout << "Time: " << timer.EndTimer() << " seconds\n"; 

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
