#include <stdio.h>
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"
#include "Matrix4.h"
#include "Vector4.h"

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
    std::cout << view << std::endl;

    Matrix4 model;
    model.Translate(Vector4(0.0f, 5.0f, 0.0f, 1.0f));
    std::cout << model << std::endl;

    Vector4 pos(10.0f, 10.0f, 10.0f, 1.0f);
    Vector4 rtl = pos * model * view;
    Vector4 ltr = view * (model * pos);

    std::cout << "right to left: " << rtl << std::endl;
    std::cout << "left to right: " << ltr << std::endl;

    while (!glfwWindowShouldClose(window)) {
        glad_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}