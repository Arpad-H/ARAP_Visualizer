#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    //init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ARAP-Visualizer", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // 4. Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Rendering commands
        // Set the color used to clear the screen (e.g., green-blue)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clear the color buffer with the specified color
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 5. Cleanup
    glfwTerminate();
    return 0;
}

// Process all input
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Called whenever the window size changes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Set the rendering viewport to the new window dimensions
    glViewport(0, 0, width, height);
}