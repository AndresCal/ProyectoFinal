#include "scene_fuego.h"
#include "cgmath.h"
#include "ifile.h"
#include "mat3.h"
#include "mat4.h"
#include "time.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <IL/il.h>
#include <vector>
#include "ParticleSystem.h"
#include "Particle.h"	




void scene_fuego::init()
{
	//Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	aspect = 1.0f;

	//Para que no haya problema en mi camara
	camPosition.z = 10;

	//Posicion
	minPosition.x = -0.5;
	maxPosition.x = 0.5;
	minPosition.y = -6.0;
	maxPosition.y = -6.5;
	//Velocidad
	minVelocidad.x = 0.0;
	maxVelocidad.x = 1.0;
	minVelocidad.y = 0.0;
	maxVelocidad.y = 0.5;
	//Ttl
	minTtl = 5;
	maxTtl = 15;

	a.y = .981;

	//Alpha
	minAlpha = 0;
	maxAlpha = 1;

	//Inicalizar Sistema de Particulas
	particleSystem.init(minPosition, maxPosition, minVelocidad, maxVelocidad,
		minTtl, maxTtl, minAlpha, maxAlpha, a);



	// Load Texture
	ILuint imageID;

	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage("textures/fuego.png");

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
		0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
	glBindTexture(GL_TEXTURE_2D, 0);

	ilBindImage(0);
	ilDeleteImages(1, &imageID);

	// Load Shaders
	ifile shader_file;
	shader_file.read("shaders/Particle.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);

	shader_file.read("shaders/Particle.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertex_shader);
	glAttachShader(shaderID, fragment_shader);

	//glBindAttribLocation
	glBindAttribLocation(shaderID, 0, "VertexPosition");
	glLinkProgram(shaderID);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	// Set shader uniforms
	glUseProgram(shaderID);

	GLint tex_location = glGetUniformLocation(shaderID, "DiffuseTexture");
	glUniform1i(tex_location, 0);

	glUseProgram(0);

}

void scene_fuego::awake()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void scene_fuego::sleep()
{
}

void scene_fuego::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaderID);
	// View Matrix
	cgmath::mat4 view_matrix(1.0f);
	//view_matrix[3][2] = 10.0f;
	view_matrix[3][0] = camPosition.x;
	view_matrix[3][1] = camPosition.y;
	view_matrix[3][2] = camPosition.z;
	view_matrix = cgmath::mat4::inverse(view_matrix);

	// Projection Matrix
	float farr = 1000.0f;
	float nearr = 1.0f;
	float half_fov = cgmath::radians(30.0f);

	cgmath::mat4 proj_matrix;
	proj_matrix[0][0] = 1.0f / (aspect * tan(half_fov));
	proj_matrix[1][1] = 1.0f / tan(half_fov);
	proj_matrix[2][2] = -((farr + nearr) / (farr - nearr));
	proj_matrix[2][3] = -1.0f;
	proj_matrix[3][2] = -((2 * farr * nearr) / (farr - nearr));

	// MVP Matrix
	GLuint model_location = glGetUniformLocation(shaderID, "mVista");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &view_matrix[0][0]);

	GLuint normal_location = glGetUniformLocation(shaderID, "mProyeccion");
	glUniformMatrix4fv(normal_location, 1, GL_FALSE, &proj_matrix[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texID);

	//Llamdas a particle System
	particleSystem.update(camPosition);
	particleSystem.draw(shaderID);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);


	glUseProgram(0);
}

void scene_fuego::resize(int width, int height)
{
	glViewport(0, 0, width, height);
	aspect = static_cast<float>(width) / static_cast<float>(height);
}
