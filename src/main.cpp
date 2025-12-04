#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <iostream>
#include "imgui.h"
#include "Application.h"
#define ASSET_DIRECTORY "../assets/"

// Settings

const unsigned int SCR_WIDTH = 800;

const unsigned int SCR_HEIGHT = 600;

//for postprocessing
float rectangleVertices[] =
{
    // Coords    // texCoords
    -1.0f,  1.0f,  0.0f, 1.0f,
    -1.0f, -1.0f,  0.0f, 0.0f,
     1.0f, -1.0f,  1.0f, 0.0f,

    -1.0f,  1.0f,  0.0f, 1.0f,
     1.0f, -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f,  1.0f, 1.0f
};
std::chrono::system_clock::time_point lastFrameTime = std::chrono::high_resolution_clock::now();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void configureImGuiStyle();

int main() {

    // create window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ARAP-Visualizer", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    // Create Frame Buffer Object for the scene to render to
    GLuint sceneFBO;
    glGenFramebuffers(1, &sceneFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, sceneFBO);
    // Create Framebuffer Texture for the scene
    GLuint sceneTexture;
    glGenTextures(1, &sceneTexture);
    glBindTexture(GL_TEXTURE_2D, sceneTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    // glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, msaa_samples, GL_RGB, WindowWidth, WindowHeight,GL_TRUE);
    //not needed with multisampling just leave it here incase
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    GLenum Error = glGetError();
    std::cout << "Error: " << Error << std::endl;
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, sceneTexture, 0);

    Application App(window);


    while (!glfwWindowShouldClose(window)) {
        // Input
        glfwPollEvents();

        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
        lastFrameTime = currentTime;
        App.update(deltaTime);

        glBindFramebuffer(GL_FRAMEBUFFER, sceneFBO);
        glClearColor(0, 0, 0, 0.0f);
        glEnable(GL_DEPTH_TEST);
        App.draw();


        glDrawArrays(GL_TRIANGLES, 0, 6);
        glfwSwapBuffers(window);
    }
    App.end();
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
void configureImGuiStyle()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    io.Fonts->AddFontFromFileTTF(ASSET_DIRECTORY "pacmanfont.ttf", 40.0f);
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(1, 1, 1, 0.7f);
    style.FrameBorderSize = 2.0f;
    style.FramePadding = ImVec2(50.0f, 25.0f);
}