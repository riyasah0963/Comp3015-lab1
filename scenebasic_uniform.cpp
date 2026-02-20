#include "scenebasic_uniform.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using glm::vec3;
using glm::vec4;
using glm::mat4;

SceneBasic_Uniform::SceneBasic_Uniform()
    : angle(0.0f), tPrev(0.0f)
{
    // DO NOT create Plane or ObjMesh here
}

void SceneBasic_Uniform::compileAndLinkShader()
{
    try {
        prog.compileShader("shaders/basic_uniform.vert");
        prog.compileShader("shaders/basic_uniform.frag");
        prog.link();
        prog.use();
    }
    catch (...) {
        std::cerr << "Shader compile/link error.\n";
        exit(EXIT_FAILURE);
    }
}

void SceneBasic_Uniform::initScene()
{
    compileAndLinkShader();

    // ?? SAFE: OpenGL context exists now
    plane = std::make_unique<Plane>(20.0f, 20.0f, 1, 1);
    pig = ObjMesh::load("media/pig_triangulated.obj");

    glEnable(GL_DEPTH_TEST);

    view = glm::lookAt(
        vec3(0.0f, 5.0f, 8.0f),
        vec3(0.0f, 0.0f, 0.0f),
        vec3(0.0f, 1.0f, 0.0f)
    );

    projection = glm::perspective(
        glm::radians(60.0f),
        800.0f / 600.0f,
        0.3f,
        100.0f
    );

    // Spotlight setup
    prog.setUniform("Light.Position", vec4(0.0f, 5.0f, 5.0f, 1.0f));
    prog.setUniform("Light.Direction", vec3(0.0f, -1.0f, -1.0f));
    prog.setUniform("Light.Cutoff", cos(glm::radians(20.0f)));

    prog.setUniform("Light.La", vec3(0.2f));
    prog.setUniform("Light.Ld", vec3(1.0f));
    prog.setUniform("Light.Ls", vec3(1.0f));
}

void SceneBasic_Uniform::update(float t)
{
    float delta = t - tPrev;
    tPrev = t;
    angle += delta;

    vec3 dir = vec3(sin(angle), -1.0f, cos(angle));
    prog.setUniform("Light.Direction", dir);
}

void SceneBasic_Uniform::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ===== Plane =====
    prog.setUniform("Material.Ka", vec3(0.2f));
    prog.setUniform("Material.Kd", vec3(0.7f));
    prog.setUniform("Material.Ks", vec3(0.1f));
    prog.setUniform("Material.Shininess", 10.0f);

    model = mat4(1.0f);
    setMatrices();
    plane->render();

    // ===== Pig =====
    prog.setUniform("Material.Ka", vec3(0.1f, 0.1f, 0.3f));
    prog.setUniform("Material.Kd", vec3(0.0f, 0.5f, 1.0f));
    prog.setUniform("Material.Ks", vec3(1.0f));
    prog.setUniform("Material.Shininess", 100.0f);

    model = glm::translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, vec3(0.5f));

    setMatrices();
    pig->render();
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

    projection = glm::perspective(
        glm::radians(60.0f),
        static_cast<float>(w) / h,
        0.3f,
        100.0f
    );
}