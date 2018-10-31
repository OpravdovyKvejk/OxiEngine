#version 460 core

layout (location = 0)in vec3 position;
layout (location = 1)in vec2 texCoord;

uniform mat4 transform;

out vec2 texcoord;

void main(void)
{
    texcoord = texCoord;
    gl_Position = transform * vec4(position, 1.0);
}
