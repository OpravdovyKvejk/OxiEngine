#version 460 core

uniform sampler2D diffuse;

in vec2 texcoord;
out vec4 outColor;

void main(void)
{
    outColor = texture2D(diffuse, texcoord);
}
