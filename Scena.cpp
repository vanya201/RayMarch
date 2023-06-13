#include "Scena.h"

namespace Raymarch {

Scena::Scena() = default;

void Scena::setRootNode(Node* rootNode) {
    this->rootNode = rootNode;
}

float Scena::distanceToObject(const glm::vec3& point) {
    return rootNode->SDF(point);
}

} 