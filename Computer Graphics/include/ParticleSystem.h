#pragma once
#include "Particle.h"
#include <random>


class ParticleSystem
{
public:

	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution{ 0.0,1.0 };

	Particle p;
	std::vector<Particle> particles;

	void init(cgmath::vec3 minPosition, cgmath::vec3 maxPosition, cgmath::vec3 minVelocidad, cgmath::vec3 maxVelocidad,
		float minTtl, float maxTtl, float minAlpha, float maxAlpha);

	void update();
	void draw(GLuint shaderID, cgmath::vec3 camPosition);

};
