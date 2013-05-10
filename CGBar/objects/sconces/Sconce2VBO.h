#pragma once

#include "../../primitives/cube/CubeVBO.h"

class Sconce2VBO
{
private:
	float height;
	float width;
	int vertex;
	int layers;
	unsigned int id_textura1 ;
	unsigned int id_textura2 ;

	CubeVBO* c1;
	CubeVBO* c2;
public:
	Sconce2VBO(float height, float width, int vertex, int layers, unsigned int id_textura1, unsigned int id_textura2);
	void draw();
};

