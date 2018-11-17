#pragma once
#include <GL/glew.h>
#include "vec3.h"
#include "vec2.h"
#include <vector>

class Quad
{
public:
	void init();
	void Draw();

private:
	GLuint vaoQuad;
	GLuint positionsQuad;
	GLuint positionsCoords;
	int size;
};

