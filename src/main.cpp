#include <iostream>
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "Math/KyleMath.h"
#include "Mesh.h"

int main(void) {
    GLFWwindow* window;

    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    } 

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(960, 540, "Model Rotator", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        return -1;
    }

    Matrix4 view;
    view.Translate(Vector4(10.0f, 0.0f, 0.0f, 1.0f));

    Matrix4 proj;
    proj.Translate(Vector4(12.0f, 5.0f, 2.0f, 1.0f));

    Vector4 pos(2.0f, 3.0f, 4.0f, 1.0f);

    Mesh boxMesh("box.obj");

    for (int i = 0; i < 8; i++) {
        std::cout << boxMesh.verts[i].position << std::endl;
    }

    while (!glfwWindowShouldClose(window)) {
        glad_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
        for (int i = 0; i < 8; i++) {
            std::cout << boxMesh.verts[i].position << std::endl;
        }
    }

    glfwTerminate();
    return 0;
}