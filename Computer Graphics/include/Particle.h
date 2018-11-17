#pragma once
#include "Quad.h"
#include <GL/glut.h>
#include "vec3.h"
#include <vector>

class Particle
{
public:
	Quad q;
	cgmath::vec3 positionsP;
	cgmath::vec3 velocity;
	float ttl;
	float alpha;
	double a;

	void init();
	void update();
	void draw(GLuint shaderID);
private:

};
