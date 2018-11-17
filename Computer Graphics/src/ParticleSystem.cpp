#include "ParticleSystem.h"
#include "Particle.h"


//Coleccion de particulas

void ParticleSystem::init()
{
	p.init();
}

//Vamos a tener un for desde 0 a size-1
//
void ParticleSystem::update()
{
	p.update();
}

void ParticleSystem::draw(GLuint shaderID)
{
	p.draw(shaderID);
}
