#pragma once

#include "../../primitives/sphere/SphereVBO.h"

class Sconce3VBO
{
private:
	float height;
	int vertex;
	int layers;
	unsigned int id_textura1 ;
	unsigned int id_textura2 ;

	SphereVBO* s1;
	SphereVBO* s2;
public:
	Sconce3VBO(float height, int vertex, int layers, unsigned int id_textura1, unsigned int id_textura2);
	void draw();
};

