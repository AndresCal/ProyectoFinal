#pragma once
#include "Particle.h"


class ParticleSystem
{
public:
	Particle p;
	std::vector<Particle> particles;

	void init();
	void update();
	void draw(GLuint shaderID);

};
