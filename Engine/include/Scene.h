#pragma once

#include <glm\vec2.hpp>
#include <map>

class Camera;
class Program;
class Renderer;
class Water;

class Scene {
public:
    Scene();
    virtual ~Scene();

    bool init(const glm::uvec2& winSize);

    void processInput(int key, int action, int mods);
    void draw(Renderer* renderer);

private:
    std::map<std::string, Program*> _programs;
    Camera*                         _camera;
    Water*                          _waterPlane;
};