#ifndef SCENEBASIC_UNIFORM_H
#define SCENEBASIC_UNIFORM_H

#include "scene.h"
#include "glslprogram.h"
#include "plane.h"
#include "objmesh.h"

#include <glm/glm.hpp>
#include <memory>

class SceneBasic_Uniform : public Scene
{
private:
    GLSLProgram prog;

    // ?? DO NOT construct OpenGL objects before context
    std::unique_ptr<Plane> plane;
    std::unique_ptr<ObjMesh> pig;

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    float angle;
    float tPrev;

    void compileAndLinkShader();
    void setMatrices();

public:
    SceneBasic_Uniform();
    ~SceneBasic_Uniform() = default;

    void initScene() override;
    void update(float t) override;
    void render() override;
    void resize(int w, int h) override;
};

#endif