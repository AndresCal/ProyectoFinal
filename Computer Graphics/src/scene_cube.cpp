#include "scene_cube.h"

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

scene_cube::~scene_cube()
{
	glDeleteBuffers(1, &positionsVBO);
	glDeleteBuffers(1, &texCoordsVBO);
	glDeleteBuffers(1, &normalsVBO);
	glDeleteBuffers(1, &indicesBuffer);

	glDeleteTextures(1, &texID);

	glDeleteVertexArrays(1, &vao);
}

void scene_cube::init()
{
	aspect = 1.0f;

	// Load Buffers
	std::vector<cgmath::vec3> positions;
	std::vector<cgmath::vec2> texCoords;
	std::vector<cgmath::vec3> normals;
	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23 };

	float x = 3.0f;
	float y = 3.0f;
	float z = 3.0f;

	// Cara frontal
	positions.push_back(cgmath::vec3(-x, -y, z));
	positions.push_back(cgmath::vec3(x, -y, z));
	positions.push_back(cgmath::vec3(x, y, z));
	positions.push_back(cgmath::vec3(-x, y, z));
	// Cara derecha
	positions.push_back(cgmath::vec3(x, -y, z));
	positions.push_back(cgmath::vec3(x, -y, -z));
	positions.push_back(cgmath::vec3(x, y, -z));
	positions.push_back(cgmath::vec3(x, y, z));
	// Cara trasera
	positions.push_back(cgmath::vec3(x, -y, -z));
	positions.push_back(cgmath::vec3(-x, -y, -z));
	positions.push_back(cgmath::vec3(-x, y, -z));
	positions.push_back(cgmath::vec3(x, y, -z));
	// Cara izquierda
	positions.push_back(cgmath::vec3(-x, -y, -z));
	positions.push_back(cgmath::vec3(-x, -y, z));
	positions.push_back(cgmath::vec3(-x, y, z));
	positions.push_back(cgmath::vec3(-x, y, -z));
	// Cara superior
	positions.push_back(cgmath::vec3(-x, y, z));
	positions.push_back(cgmath::vec3(x, y, z));
	positions.push_back(cgmath::vec3(x, y, -z));
	positions.push_back(cgmath::vec3(-x, y, -z));
	// Cara inferior
	positions.push_back(cgmath::vec3(-x, -y, -z));
	positions.push_back(cgmath::vec3(x, -y, -z));
	positions.push_back(cgmath::vec3(x, -y, z));
	positions.push_back(cgmath::vec3(-x, -y, z));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
	texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
	texCoords.push_back(cgmath::vec2(0.0f, 1.0f));

	normals.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));

	normals.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));

	normals.push_back(cgmath::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(cgmath::vec3(0.0f, 0.0f, -1.0f));

	normals.push_back(cgmath::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(cgmath::vec3(-1.0f, 0.0f, 0.0f));

	normals.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));

	normals.push_back(cgmath::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(cgmath::vec3(0.0f, -1.0f, 0.0f));

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &texCoordsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, texCoordsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * texCoords.size(), texCoords.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &normalsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec3) * normals.size(), normals.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);

	// Load Texture
	ILuint imageID;

	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage("textures/crate.png");

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
	glBindTexture(GL_TEXTURE_2D, 0);

	ilBindImage(0);
	ilDeleteImages(1, &imageID);

	// Load Shaders
	ifile shader_file;
	shader_file.read("shaders/PhongTexture.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);

	shader_file.read("shaders/PhongTexture.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glBindAttribLocation(shader_program, 0, "VertexPosition");
	glBindAttribLocation(shader_program, 1, "VertexTexCoord");
	glBindAttribLocation(shader_program, 2, "VertexNormal");
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	// Set shader uniforms
	glUseProgram(shader_program);
	
	GLuint lightpos_location = glGetUniformLocation(shader_program, "LightPosition");
	glUniform3f(lightpos_location, -10.0f, 10.0f, 10.0f);

	GLuint lightcolor_location = glGetUniformLocation(shader_program, "LightColor");
	glUniform3f(lightcolor_location, 1.0f, 1.0f, 1.0f);

	GLuint campos_location = glGetUniformLocation(shader_program, "CameraPosition");
	glUniform3f(campos_location, 0.0f, 0.0f, 10.0f);

	GLint tex_location = glGetUniformLocation(shader_program, "DiffuseTexture");
	glUniform1i(tex_location, 0);
	
	glUseProgram(0);
}

void scene_cube::awake()
{
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
}

void scene_cube::sleep()
{
}

void scene_cube::mainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);

	float t = time::elapsed_time().count();

	float angleX = cgmath::radians(t * 30.0f);
	float angleY = cgmath::radians(t * 60.0f);
	float angleZ = cgmath::radians(t * 30.0f);

	// Model Matrix
	cgmath::vec4 rotxx(1.0f, 0.0f, 0.0f, 0.0f);
	cgmath::vec4 rotxy(0.0f, cos(angleX), sin(angleX), 0.0f);
	cgmath::vec4 rotxz(0.0f, -sin(angleX), cos(angleX), 0.0f);
	cgmath::vec4 rotxw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 rotx(rotxx, rotxy, rotxz, rotxw);

	cgmath::vec4 rotyx(cos(angleY), 0.0f, -sin(angleY), 0.0f);
	cgmath::vec4 rotyy(0.0f, 1.0f, 0.0f, 0.0f);
	cgmath::vec4 rotyz(sin(angleY), 0.0f, cos(angleY), 0.0f);
	cgmath::vec4 rotyw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 roty(rotyx, rotyy, rotyz, rotyw);

	cgmath::vec4 rotzx(cos(angleZ), sin(angleZ), 0.0f, 0.0f);
	cgmath::vec4 rotzy(-sin(angleZ), cos(angleZ), 0.0f, 0.0f);
	cgmath::vec4 rotzz(0.0f, 0.0f, 1.0f, 0.0f);
	cgmath::vec4 rotzw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 rotz(rotzx, rotzy, rotzz, rotzw);

	cgmath::mat4 model_matrix = rotx * roty * rotz;

	// Normal Matrix
	cgmath::mat3 normal_matrix = cgmath::mat3::transpose(cgmath::mat3::inverse(cgmath::mat3(model_matrix)));

	// View Matrix
	cgmath::mat4 view_matrix(1.0f);
	view_matrix[3][2] = 10.0f;
	view_matrix = cgmath::mat4::inverse(view_matrix);

	// Projection Matrix
	float far = 1000.0f;
	float near = 1.0f;
	float half_fov = cgmath::radians(30.0f);

	cgmath::mat4 proj_matrix;
	proj_matrix[0][0] = 1.0f / (aspect * tan(half_fov));
	proj_matrix[1][1] = 1.0f / tan(half_fov);
	proj_matrix[2][2] = -((far + near) / (far - near));
	proj_matrix[2][3] = -1.0f;
	proj_matrix[3][2] = -((2 * far * near) / (far - near));

	// MVP Matrix

	cgmath::mat4 mvp = proj_matrix * view_matrix * model_matrix;

	GLuint mvp_location = glGetUniformLocation(shader_program, "mvpMatrix");
	glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvp[0][0]);

	GLuint model_location = glGetUniformLocation(shader_program, "modelMatrix");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &model_matrix[0][0]);

	GLuint normal_location = glGetUniformLocation(shader_program, "normalMatrix");
	glUniformMatrix3fv(normal_location, 1, GL_FALSE, &normal_matrix[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texID);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(0);
}

void scene_cube::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	aspect = static_cast<float>(width) / static_cast<float>(height);
}
