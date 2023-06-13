
#include "Camera.h"


namespace Raymarch {

Camera::Camera() {
    init();
}

Camera::Camera(glm::vec3 dir, glm::vec3 pos) : dir(dir), pos(pos) {
    init();
}

void Camera::init() {
    dir = glm::normalize(dir);
    glm::vec3 normalizedDir = dir;
    glm::vec3 right = glm::cross(up, normalizedDir);
    glm::vec3 newUp = glm::cross(normalizedDir, right);

    view = glm::mat3(
        right,
        newUp,
        normalizedDir
    );
}

glm::vec3 Camera::getNewRay(glm::vec3 ray) {
    return view * ray;
}

glm::vec3 Camera::getPointRay(glm::vec3 ray) {
    return ray + pos;
}

} 
