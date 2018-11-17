#pragma once
#include "Particle.h"


class ParticleSystem
{
public:
	Particle p;

	void init();
	void update();
	void draw(GLuint shaderID);

};
