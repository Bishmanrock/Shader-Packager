// Fragment Shader (Shader.frag)
#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform float opacity;

void main()
{
    //vec4 texColor = texture(texture1, TexCoord);
    //FragColor = texColor * vec4(ourColor, opacity);

    FragColor = texture(texture1, TexCoord);

    //vec4 texColor = texture(texture1, TexCoord);
    //vec3 modulatedColor = texColor.rgb * ourColor; // ourColor is white, so texColor is unchanged
    //FragColor = vec4(modulatedColor, texColor.a); // Use texColor's alpha for transparency
}