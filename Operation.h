#pragma once

#include <list>
#include "Node.h"

namespace Raymarch {

class Operation : public Node {
public:
    virtual float SDF(const glm::vec3& point) const = 0;
    void addNode(Node* node);

protected:
    std::list<Node*> nodes;
};

class IntersectSDF : public Operation {
public:
    virtual float SDF(const glm::vec3& point) const override final;
};

class UnionSDF : public Operation {
public:
    virtual float SDF(const glm::vec3& point) const override final;
};

} 
