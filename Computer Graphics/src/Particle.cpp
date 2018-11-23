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



void Particle::init(cgmath::vec3 positions, cgmath::vec3 velocity, cgmath::vec3 a, float ttl, float alpha)
{
	q.init(); //Mandar a llamar init en particula 
	 myPositions = positions;
	 myVelocity = velocity;
	 myA = a;
	 myTtl = ttl;
	 myAlpha = alpha;
}

void Particle::update()
{
	myVelocity = myVelocity + myA * time::delta_time().count(); //Velocidad
	myPositions = myPositions + myVelocity * time::delta_time().count(); //Posicion
	myTtl = myTtl - time::delta_time().count();

}

void Particle::draw(GLuint shaderID)
{
	// Model Matrix solo traslación

	cgmath::vec4 rotzx(1.0f, 0.0f, 0.0f, 0.0f);
	cgmath::vec4 rotzy(0.0f, 1.0f, 0.0f, 0.0f);
	cgmath::vec4 rotzz(0.0f, 0.0f, 1.0f, 0.0f);
	cgmath::vec4 rotzw(myPositions.x, myPositions.y, myPositions.z, 1.0f);
	cgmath::mat4 model_matrix(rotzx, rotzy, rotzz, rotzw);

	GLuint model_location = glGetUniformLocation(shaderID, "mModelo");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &model_matrix[0][0]);

	q.Draw();
}
