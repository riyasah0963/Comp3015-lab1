#version 460 core

layout(location = 0) in vec3 position;

out vec3 TexCoords;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
    TexCoords = position;
    gl_Position = Projection * View * Model * vec4(position, 1.0);
}