#pragma once
#include "Quad.h"
#include <GL/glut.h>
#include "vec3.h"
#include <vector>

class Particle
{
public:
	Quad q;
	cgmath::vec3 myPositions;
	cgmath::vec3 myVelocity;
	cgmath::vec3 myA;
	float myTtl;
	float myAlpha;


	void init(cgmath::vec3 positions, cgmath::vec3 velocity, cgmath::vec3 a, float ttl, float alpha);
	void update();
	void draw(GLuint shaderID);
private:

};
