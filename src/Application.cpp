//
// Created by Arpad on 12/4/2025.
//

#include "Application.h"

#include <cassert>
#include <math.h>


static float toRad(float deg) { return deg * M_PI / 180.0f; }

Application::Application(GLFWwindow *pWin) : pWindow(pWin), Cam(pWin) {
    int width, height;
    glfwGetWindowSize(pWindow, &width, &height);
}

void Application::start() {
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as closer
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_STENCIL_TEST);
    time = 0;
}


void Application::update(float deltaTime) {
    time += deltaTime;

    updateGameObjects(deltaTime);
    currentView = Cam.getViewMatrix();
}

void Application::updateGameObjects(float deltaTime) {

}

void Application::draw() {
    // 1. clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // 2. setup shaders and draw models
    for (ModelList::iterator it = Models.begin(); it != Models.end(); ++it) {
        (*it)->draw(Cam);
    }

    GLenum Error = glGetError();
    assert(Error == 0);
}

void Application::end() {
    for (ModelList::iterator it = Models.begin(); it != Models.end(); ++it)
        delete *it;

    Models.clear();
}
