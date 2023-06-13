#include "Operation.h"

namespace Raymarch {


void Operation::addNode(Node* node) {
   nodes.push_back(node);
}

float IntersectSDF::SDF(const glm::vec3& point) const {
    float minDist = std::numeric_limits<float>::infinity();
    for (const auto& node : nodes) {
        float dist = node->SDF(point);
        minDist = std::min(minDist, dist);
    }
    return minDist;
}

float UnionSDF::SDF(const glm::vec3& point) const {
    float maxDist = -std::numeric_limits<float>::infinity();
    for (const auto& node : nodes) {
        float dist = node->SDF(point);
        maxDist = std::max(maxDist, dist);
    }
    return maxDist;
}

} 
