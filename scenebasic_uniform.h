#ifndef SCENEBASIC_UNIFORM_H
#define SCENEBASIC_UNIFORM_H

#include "scene.h"
#include "glslprogram.h"
#include "objmesh.h"

#include <glm/glm.hpp>
#include <memory>

class SceneBasic_Uniform : public Scene
{
private:
    GLSLProgram prog;
    std::unique_ptr<ObjMesh> mesh;

    void compileAndLinkShader();
    void setMatrices();

public:
    SceneBasic_Uniform();     // constructor

    void initScene() override;
    void update(float t) override;
    void render() override;
    void resize(int w, int h) override;
};

#endif