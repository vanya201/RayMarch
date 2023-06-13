
#pragma once
#include <glm/glm.hpp>

namespace Raymarch {

class Node {
public:
    virtual float SDF(const glm::vec3& point) const = 0;
};

class Sphera : public Node {

public:
    Sphera() = default;
    Sphera(double r, glm::vec3 center);

    virtual float SDF(const glm::vec3& point) const override final;

    void setCenter(glm::vec3 center);
    void setRadius(double r);

private:
    double r = 1;
    glm::vec3 center = glm::vec3(0.0f, 0.0f, 3.0f);
};

class Plane : public Node {

public:
    Plane() = default;
    virtual float SDF(const glm::vec3& point) const override final;

private:
    glm::vec3 normal = glm::vec3(0, 1, 0);
    float distance = 1.0;
};

};