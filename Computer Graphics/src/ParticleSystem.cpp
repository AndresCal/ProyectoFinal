#include "ParticleSystem.h"
#include "Particle.h"
#include <algorithm>


//Coleccion de particulas



void ParticleSystem::init(cgmath::vec3 minPosition, cgmath::vec3 maxPosition, cgmath::vec3 minVelocidad, cgmath::vec3 maxVelocidad,
	float minTtl, float maxTtl, float minAlpha, float maxAlpha, cgmath::vec3 a)
{	
	myMinPosition = minPosition;
	myMaxPosition = maxPosition;
	myMinVelocidad = minVelocidad;
	myMaxVelocidad = maxVelocidad;
	myA = a;
	myMinTtl = minTtl;
	myMaxTtl = maxTtl;
	myMinAlpha = minAlpha;
	myMaxAlpha = maxAlpha;

	for (int i = 0; i <= 300; i++)
	{
		float randomX = distribution(generator) * (myMaxPosition.x - myMinPosition.x) + myMinPosition.x;
		float randomY = distribution(generator) * (myMaxPosition.y - myMinPosition.y) + myMinPosition.y;
		cgmath::vec3 positions(randomX, randomY, 0);

		float randomXV = distribution(generator) * (myMaxVelocidad.x - myMinVelocidad.x) + myMinVelocidad.x;
		float randomYV = distribution(generator) * (myMaxVelocidad.y - myMinVelocidad.y) + myMinVelocidad.y;
		cgmath::vec3 velocity(randomXV, randomYV, 0);

		float ttl = distribution(generator) * (myMaxTtl - myMinTtl) + myMinTtl;
	
		float alpha = distribution(generator) * (myMaxAlpha - myMinAlpha) + myMinAlpha;

		particles.push_back(Particle());
		particles[i].init(positions, velocity, myA, ttl, alpha);

	}
}

void ParticleSystem::update(cgmath::vec3 camPositionn)
{
	for (int i = 0; i <= 300; i++)
	{
		float randomX = distribution(generator) * (myMaxPosition.x - myMinPosition.x) + myMinPosition.x;
		float randomY = distribution(generator) * (myMaxPosition.y - myMinPosition.y) + myMinPosition.y;
		cgmath::vec3 positions(randomX, randomY, 0);

		float randomXV = distribution(generator) * (myMaxVelocidad.x - myMinVelocidad.x) + myMinVelocidad.x;
		float randomYV = distribution(generator) * (myMaxVelocidad.y - myMinVelocidad.y) + myMinVelocidad.y;
		cgmath::vec3 velocity(randomXV, randomYV, 0);

		float ttl = distribution(generator) * (myMaxTtl - myMinTtl) + myMinTtl;

		float alpha = distribution(generator) * (myMaxAlpha - myMinAlpha) + myMinAlpha;

		if (particles[i].myTtl <= 0) {
			particles[i].init(positions, velocity, myA, ttl, alpha);
		}
		particles[i].update();
		particles[i].camPosition = camPositionn;

	}
	//p.update();
}

bool myfunction(Particle i, Particle j)
{
	cgmath::vec3 distancia = i.camPosition - i.myPositions;
	cgmath::vec3 distancia2 = j.camPosition - j.myPositions;
	return distancia.magnitude() < distancia2.magnitude();
}

void ParticleSystem::draw(GLuint shaderID)
{

	std::sort(particles.begin(), particles.end(), myfunction);
	for (int i = 0; i <= 300; i++)
	{
		particles[i].draw(shaderID);
	}
	//p.draw(shaderID);
}
