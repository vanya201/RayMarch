#pragma once

#include <GLFW/glfw3.h>
#include "Light.h"
#include "Scena.h"
#include "Camera.h"

namespace Raymarch {

class Render {
public:
    Render();

    void setLight(Light* light);
    void setScena(Scena* scena);
    void setCamera(Camera* camera);
    void render(GLFWwindow* myWindow);

private:
    float rayMarch(glm::vec3 ray);

    Light* light;
    Scena* scena;
    Camera* camera;
    float startPoint = -1;
};

} 
