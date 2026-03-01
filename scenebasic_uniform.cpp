#include "scenebasic_uniform.h"
#include <glm/gtc/matrix_transform.hpp>

SceneBasic_Uniform::SceneBasic_Uniform()
    : skybox(100.0f)   // big cube
{
}

void SceneBasic_Uniform::initScene()
{
    glEnable(GL_DEPTH_TEST);

    prog.compileShader("shaders/basic_uniform.vert");
    prog.compileShader("shaders/basic_uniform.frag");
    prog.link();
    prog.use();

    view = glm::lookAt(glm::vec3(0, 0, 5),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0));

    projection = glm::perspective(glm::radians(60.0f),
        800.0f / 600.0f,
        0.1f,
        500.0f);
}

void SceneBasic_Uniform::update(float t)
{
    model = glm::rotate(glm::mat4(1.0f), t, glm::vec3(0, 1, 0));
}

void SceneBasic_Uniform::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    prog.use();

    // -------- SKYBOX FIRST --------
    glDepthMask(GL_FALSE);

    glm::mat4 skyView = glm::mat4(glm::mat3(view)); // remove translation

    prog.setUniform("Model", glm::mat4(1.0f));
    prog.setUniform("View", skyView);
    prog.setUniform("Projection", projection);

    skybox.render();

    glDepthMask(GL_TRUE);

    // -------- OBJECT --------
    prog.setUniform("Model", model);
    prog.setUniform("View", view);
    prog.setUniform("Projection", projection);

    // draw your object here
}