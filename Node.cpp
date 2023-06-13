
#include "Node.h"

namespace Raymarch {

Sphera::Sphera(double r, glm::vec3 center) : r(r), center(center) {}

float Sphera::SDF(const glm::vec3& point) const {
    return glm::length(point - center) - r;
}

void Sphera::setCenter(glm::vec3 center) {
    this->center = center;
}

void Sphera::setRadius(double r) {
    this->r = r;
}

float Plane::SDF(const glm::vec3& point) const {
    return glm::dot(point, normal) + distance;
}

};
