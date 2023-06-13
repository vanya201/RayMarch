#pragma once

#include "Node.h"

namespace Raymarch {

class Scena {

public:
    Scena();

    void setRootNode(Node* rootNode);
    float distanceToObject(const glm::vec3& point);

private:
    Node* rootNode;
};

}
