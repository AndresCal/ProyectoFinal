#pragma once
#include "Particle.h"
#include <vector>
#include <random>


class ParticleSystem
{
public:

	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution{ 0.0,1.0 };

	Particle p;
	std::vector<Particle> particles;

	cgmath::vec3 myMinPosition, myMaxPosition;
	cgmath::vec3 myMinVelocidad, myMaxVelocidad;
	cgmath::vec3 myA;
	float myMinTtl, myMaxTtl;
	float myMinAlpha, myMaxAlpha;

	void init(cgmath::vec3 minPosition, cgmath::vec3 maxPosition, cgmath::vec3 minVelocidad, cgmath::vec3 maxVelocidad,
		float minTtl, float maxTtl, float minAlpha, float maxAlpha, cgmath::vec3 a);

	void update(cgmath::vec3 camPosition);
	void draw(GLuint shaderID);

};
