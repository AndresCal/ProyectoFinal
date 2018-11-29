#version 330

in vec2 InterpolatedTexCoord;

out vec4 FragColor;

uniform sampler2D DiffuseTexture;

void main()
{	
	vec4 color = texture2D(DiffuseTexture, InterpolatedTexCoord);
	if (color.a < 0.1) discard;

	FragColor = color;
}