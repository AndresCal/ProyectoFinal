#include "ParticleSystem.h"
#include "Particle.h"


//Coleccion de particulas



void ParticleSystem::init(cgmath::vec3 minPosition, cgmath::vec3 maxPosition, cgmath::vec3 minVelocidad, cgmath::vec3 maxVelocidad,
	float minTtl, float maxTtl, float minAlpha, float maxAlpha)
{	
	for (int i = 0; i <= 1000; i++)
	{
		float randomX = distribution(generator) * (maxPosition.x - minPosition.x) + minPosition.x;
		float randomY = distribution(generator) * (maxPosition.y - minPosition.y) + minPosition.y;
		cgmath::vec3 positions(randomX, randomY, 0);

		float randomXV = distribution(generator) * (maxVelocidad.x - minVelocidad.x) + minVelocidad.x;
		float randomYV = distribution(generator) * (maxVelocidad.y - minVelocidad.y) + minVelocidad.y;
		cgmath::vec3 velocity(randomXV, randomYV, 0);

		cgmath::vec3 a(0, -0.981, 0);

		float ttl = distribution(generator) * (maxTtl - minTtl) + minTtl;
		float alpha = distribution(generator) * (maxAlpha - minAlpha) + minAlpha;

		particles.push_back(Particle());
		particles[i].init(positions, velocity, a, ttl, alpha);

	}
	
}

void ParticleSystem::update()
{
	for (int i = 0; i <= 1000; i++)
	{
		particles[i].update();
	}
	//p.update();


}

bool myfunction(Particle i, Particle j)
{



	return (i < j);
}

void ParticleSystem::draw(GLuint shaderID, cgmath::vec3 camPosition)
{

	std::sort(particles.begin() + 4, particles.end(), myfunction);
	
	for (int i = 0; i <= 100; i++)
	{
		particles[i].draw(shaderID);
	}
	//p.draw(shaderID);
}
