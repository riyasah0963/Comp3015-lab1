#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "scene.h"
#include "glslprogram.h"
#include "helper/skybox.h"

class SceneBasic_Uniform : public Scene
{
private:
    GLSLProgram prog;
    SkyBox skybox;

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

public:
    SceneBasic_Uniform();

    void initScene() override;
    void update(float t) override;
    void render() override;
    void resize(int w, int h) override;
};