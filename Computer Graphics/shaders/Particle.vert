#version 330

in vec3 VertexPosition;
in vec2 VertexTexCoord;

out vec2 InterpolatedTexCoord;

uniform mat4 mModelo;
uniform mat4 mVista;
uniform mat4 mProyeccion;

void main()
{
	InterpolatedTexCoord = VertexTexCoord;
	gl_Position = mProyeccion * mVista * mModelo * vec4(VertexPosition, 1.0f); //proyecion vista modelo
}