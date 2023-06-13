
#pragma once

#include <glm/glm.hpp>

namespace Raymarch {

class Camera {

public:
    Camera();
    Camera(glm::vec3 dir, glm::vec3 pos);

    void init();
    glm::vec3 getNewRay(glm::vec3 ray);
    glm::vec3 getPointRay(glm::vec3 ray);

private:
    glm::vec3 dir = glm::vec3(0, 0, -1);
    glm::vec3 pos = glm::vec3(0, 0, 0);
    glm::vec3 up = glm::vec3(0, 1, 0);
    glm::mat3 view;
};

} 
