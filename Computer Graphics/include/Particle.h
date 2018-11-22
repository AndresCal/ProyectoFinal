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
	cgmath::vec3 a;
	float ttl;
	float alpha;


	void init();
	void update();
	void draw(GLuint shaderID);
private:

};
