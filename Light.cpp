
#include "Light.h"
#include "Scena.h"

namespace Raymarch {

void Light::setScena(Scena* scena) {
    this->scena = scena;
}

glm::vec3 Light::getLight(glm::vec3 ray, glm::vec3 color) {
    return color * glm::clamp(glm::dot(getNormal(ray), glm::normalize(pos - ray)), 0.0f, 1.0f);
}

void Light::rotate(glm::vec3 axis, float angle) {
    glm::quat rotationQuaternion = glm::angleAxis(glm::radians(angle), axis);
    pos = glm::rotate(rotationQuaternion, pos);
}

glm::vec3 Light::getNormal(glm::vec3 ray) {
    float epsilon = 0.001;
    glm::vec3 raydx = ray + glm::vec3(epsilon, 0, 0);
    glm::vec3 raydy = ray + glm::vec3(0, epsilon, 0);
    glm::vec3 raydz = ray + glm::vec3(0, 0, epsilon);
    glm::vec3 normal = glm::vec3(
        scena->distanceToObject(raydx) - scena->distanceToObject(ray),
        scena->distanceToObject(raydy) - scena->distanceToObject(ray),
        scena->distanceToObject(raydz) - scena->distanceToObject(ray));
    return glm::normalize(normal);
}

} 