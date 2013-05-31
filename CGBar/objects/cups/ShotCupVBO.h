#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

extern float cinzentoAlphaCopo[] ;

class  ShotCupVBO : public Primitivas
{
public:
	ShotCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura);
	void drawShot_top();
	void draw();

	CylinderVBO* cylinder;
private:
	double alt, radius, height, rad;
	int vertex,layers;
	unsigned int id_textura;
	int desenha;
};


