
#include "Render.h"
#include <algorithm>
#include <limits>
#include <glm/glm.hpp>


namespace Raymarch {

Render::Render() = default;

void Render::setLight(Light* light) {
    this->light = light;
}

void Render::setScena(Scena* scena) {
    this->scena = scena;
}

void Render::setCamera(Camera* camera) {
    this->camera = camera;
}

void Render::render(GLFWwindow* myWindow) {
   
        glfwMakeContextCurrent(myWindow);
        glOrtho(-1, 1, -1, 1, -1, 1);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        glm::vec3 color;

        for (float x = -1; x < 1; x += 0.005) {
            for (float y = -1; y < 1; y += 0.005) {
                glm::vec3 ray = glm::normalize(camera->getNewRay(glm::vec3(glm::vec2(x, y), startPoint)));
                float distance = rayMarch(ray);
                
                if (distance > 0 && distance < 100) {
                    color = light->getLight(ray, glm::vec3(1.0f, 1.0f, 1.0f));
                    glColor3f(color.x, color.y, color.z);
                    glVertex2f(x, y);
                }
            }
        }

        glEnd();
        glfwSwapBuffers(myWindow);
}

float Render::rayMarch(glm::vec3 ray) {

    float maxDistance = 100.0;
    float minDistance = 0.1;
    glm::vec3 raypoint = camera->getPointRay(ray);
    float dist = scena->distanceToObject(raypoint);

    while (dist < maxDistance && dist > minDistance) {

        ray = dist * glm::normalize(ray) + ray;
        raypoint = camera->getPointRay(ray);
        dist = scena->distanceToObject(raypoint);
    }

    return glm::length(ray);
}

} 