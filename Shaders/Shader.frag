// Fragment Shader (Shader.frag)
#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform float opacity;

out vec4 FragColor;

void main()
{
    vec4 texColor = texture(texture1, TexCoord);
    vec4 texColor = texture(texture1, TexCoord);
}