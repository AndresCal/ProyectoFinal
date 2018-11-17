#include "Quad.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "cgmath.h"
#include <vector>
#include <GL/glut.h>
#include "Particle.h"
#include "time.h"
#include "math.h"



void Particle::init()
{
	//Inicializar las particulas. 
	positionsP.x = 1.0;
	positionsP.y = 1.0;
	positionsP.z = 0.0;

	velocity.x = 1.0;
	velocity.y = 1.0;
	velocity.z = 0.0;

	alpha = 0;
	ttl = 20;
	a = 9.8;
}

void Particle::update()
{
	velocity = velocity * a * time::delta_time().count(); //Velocidad
	positionsP = positionsP + velocity * time::delta_time().count(); //Posicion
	ttl = ttl - time::delta_time().count();

}

void Particle::draw(GLuint shaderID)
{
	// Model Matrix solo traslación

	cgmath::vec4 rotzx(1.0f, 0.0f, 0.0f, 0.0f);
	cgmath::vec4 rotzy(0.0f, 1.0f, 0.0f, 0.0f);
	cgmath::vec4 rotzz(0.0f, 0.0f, 1.0f, 0.0f);
	cgmath::vec4 rotzw(positionsP.x, positionsP.y, positionsP.z, 1.0f);
	cgmath::mat4 model_matrix(rotzx, rotzy, rotzz, rotzw);

	GLuint model_location = glGetUniformLocation(shaderID, "mModelo");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &model_matrix[0][0]);

	q.Draw();
}
