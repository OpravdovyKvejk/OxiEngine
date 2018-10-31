#version 460 core

in vec2 texcoord;
out vec4 outColor;

uniform sampler2D diffuse;

void main(void)
{
    if (gl_FragCoord.x > 320) //used for showcasing lighting
        outColor = texture2D(diffuse, texcoord);
    else
        outColor = vec4(1, 1, 1, 1);
}
