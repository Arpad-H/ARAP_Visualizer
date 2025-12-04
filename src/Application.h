//
// Created by Arpad on 12/4/2025.
//

#ifndef ARAP_VISUALIZER_APPLICATION_H
#define ARAP_VISUALIZER_APPLICATION_H

#include <stdio.h>
#include <list>
#include "camera.h"
#include <chrono>
#include <algorithm>
#include <GLFW/glfw3.h>
#include "BaseModel.h"
#include "GameObject.h"


class Application
{
public:
    typedef std::list<BaseModel*> ModelList;
    typedef std::list<GameObject*> GameObjectList;
    Application(GLFWwindow* pWin);
    void start();
    void update(float deltaTime);

    void draw();
    void drawOutlines(int pass);
    void end();

protected:
    void updateGameObjects(float deltaTime);

    Camera Cam;
    ModelList Models;

    //GameObjectList GameObjects;
    GLFWwindow* pWindow;

    float time;
    std::chrono::high_resolution_clock::time_point lastFrameTime;

    Matrix currentView;

};


#endif //ARAP_VISUALIZER_APPLICATION_H