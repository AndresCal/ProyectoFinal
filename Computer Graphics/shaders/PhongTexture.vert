#version 330

in vec3 VertexPosition;
in vec2 VertexTexCoord;
in vec3 VertexNormal;

out vec3 InterpolatedNormal;
out vec3 PixelPosition;
out vec2 InterpolatedTexCoord;

uniform mat4 mvpMatrix;
uniform mat4 modelMatrix;
uniform mat3 normalMatrix;

void main()
{
	InterpolatedTexCoord = VertexTexCoord;
	InterpolatedNormal = normalMatrix * VertexNormal;
	PixelPosition = vec3(modelMatrix * vec4(VertexPosition, 1.0f));
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}