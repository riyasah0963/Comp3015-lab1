#include "scenebasic_uniform.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using glm::vec3;
using glm::vec4;
using glm::mat4;

SceneBasic_Uniform::SceneBasic_Uniform()
{
}

void SceneBasic_Uniform::compileAndLinkShader()
{
    try {
        prog.compileShader("shaders/basic_uniform.vert");
        prog.compileShader("shaders/basic_uniform.frag");
        prog.link();
        prog.use();
    }
    catch (GLSLProgramException& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void SceneBasic_Uniform::initScene()
{
    compileAndLinkShader();
    glEnable(GL_DEPTH_TEST);

    mesh = ObjMesh::load("media/pig_triangulated.obj");

    view = glm::lookAt(vec3(0.0f, 2.0f, 6.0f),
        vec3(0.0f, 0.5f, 0.0f),
        vec3(0.0f, 1.0f, 0.0f));

    projection = glm::perspective(glm::radians(60.0f),
        800.0f / 600.0f,
        0.3f,
        100.0f);

    // ===== LIGHT =====
    prog.setUniform("Light.Position", vec4(2.0f, 4.0f, 2.0f, 1.0f));
    prog.setUniform("Light.Direction", vec3(-0.5f, -1.0f, -0.3f));
    prog.setUniform("Light.Cutoff", glm::cos(glm::radians(20.0f)));

    prog.setUniform("Light.La", vec3(0.2f));
    prog.setUniform("Light.Ld", vec3(1.0f));
    prog.setUniform("Light.Ls", vec3(1.0f));

    // ===== MATERIAL =====
    prog.setUniform("Material.Ka", vec3(0.1f, 0.1f, 0.3f));
    prog.setUniform("Material.Kd", vec3(0.2f, 0.4f, 1.0f));
    prog.setUniform("Material.Ks", vec3(1.0f));
    prog.setUniform("Material.Shininess", 100.0f);
}

void SceneBasic_Uniform::update(float t)
{
}

void SceneBasic_Uniform::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model = mat4(1.0f);
    model = glm::rotate(model,
        glm::radians(20.0f),
        vec3(0.0f, 1.0f, 0.0f));

    setMatrices();
    mesh->render();
}

void SceneBasic_Uniform::setMatrices()
{
    mat4 mv = view * model;

    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("NormalMatrix",
        glm::mat3(glm::transpose(glm::inverse(mv))));
    prog.setUniform("MVP", projection * mv);
}

void SceneBasic_Uniform::resize(int w, int h)
{
    glViewport(0, 0, w, h);

    projection = glm::perspective(glm::radians(60.0f),
        (float)w / h,
        0.3f,
        100.0f);
}