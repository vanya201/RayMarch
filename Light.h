#pragma once

#include <glm/glm.hpp>
#include "Scena.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Raymarch {

class Light {
public:
    Light() = default;

    void setScena(Scena* scena);
    glm::vec3 getLight(glm::vec3 ray, glm::vec3 color);
    void rotate(glm::vec3 axis, float angle);

private:
    glm::vec3 getNormal(glm::vec3 ray);

    Scena* scena;
    glm::vec3 pos = glm::vec3(60, 60, -4);
};

} 
