#include "Quad.h"
#include <math.h>
#include <GL/glut.h>
#include "vec3.h"
#include "vec2.h"
#include <vector>

void Quad::init()
{
	std::vector<cgmath::vec3> positionsID;// = { 1, 2, 0, 3 }; //indices para crear mi cuadrado GL_TRIANGLE_STRIP
	std::vector<cgmath::vec2> textcoordsID;
	positionsID.push_back(cgmath::vec3(0.7, 0, 0));
	positionsID.push_back(cgmath::vec3(0.7, 0.7, 0));
	positionsID.push_back(cgmath::vec3(0, 0, 0));
	positionsID.push_back(cgmath::vec3(0, 0.7, 0));

	textcoordsID.push_back(cgmath::vec2(1, 0));
	textcoordsID.push_back(cgmath::vec2(1, 1));
	textcoordsID.push_back(cgmath::vec2(0, 0));
	textcoordsID.push_back(cgmath::vec2(0, 1));

	size = positionsID.size();

	glGenVertexArrays(1, &vaoQuad); //Variable donde quiero vaciar 
	glBindVertexArray(vaoQuad);

	glGenBuffers(1, &positionsQuad); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsQuad); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec3) * positionsID.size(),  //mandamos los datos
		positionsID.data(),
		GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); //ya lo prendi
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &positionsCoords); //locreamos
	glBindBuffer(GL_ARRAY_BUFFER, positionsCoords); //el buffer que creo lo ocupo como atributo activamos
	glBufferData(GL_ARRAY_BUFFER, sizeof(cgmath::vec2) * textcoordsID.size(),  //mandamos los datos
		textcoordsID.data(),
		GL_STATIC_DRAW);
	glEnableVertexAttribArray(1); //ya lo prendi
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr); //atributi igual al de arriba, 2 por vertive, tipo de dato, normalizar?, falso, especificar
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void Quad::Draw()
{
	//dibujar
	glBindVertexArray(vaoQuad);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, size);
	glBindVertexArray(0);
}



