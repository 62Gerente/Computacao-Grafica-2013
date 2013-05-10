#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"
#include "../../primitives/plane/PlaneVBO.h"

class ComputerVBO
{
private:
	float height;
	int vertex;
	int layers;
	unsigned int id_textura ;

	ParallelepipedVBO* p1;
	ParallelepipedVBO* p2;
	ParallelepipedVBO* p3;
	ParallelepipedVBO* p4;
	ParallelepipedVBO* p5;
	ParallelepipedVBO* p6;
	ParallelepipedVBO* p7;
	ParallelepipedVBO* p8;
	PlaneVBO* p9;
public:
	ComputerVBO(float height, int vertex, int layers, unsigned int id_texturae,unsigned int id_texturam,unsigned int id_texturac,
			  unsigned int id_texturat);
	void draw();
};

