#include "Node.h"
#include "Operation.h"
#include "Scena.h"
#include "Light.h"
#include "Camera.h"
#include "Render.h"


namespace Raymarch {

 void loop() {

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 800, "Pixel Rendering", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    }

    Render render;
    Camera camera;
    Scena scena;
    IntersectSDF inter;
    Sphera sphera;
    Light light;

    inter.addNode(&sphera);
    scena.setRootNode(&inter);
    light.setScena(&scena);
    render.setLight(&light);
    render.setScena(&scena);
    render.setCamera(&camera);
   
    while (!glfwWindowShouldClose(window)) {
        //light.rotate(glm::vec3(0, 1, 0), 20);
        render.render(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
};
