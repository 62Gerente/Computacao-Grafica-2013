#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  BeerCupVBO : public Primitivas
{
public:
	BeerCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura);
	void drawBeer_top();
	void drawBeer_base();
	void draw();
private:
	double alt, radius, height, rad, altura, raio;
	int vertex,layers;
	unsigned int id_textura;
	int desenha, desenhabase;
	int *aIndex2;
	unsigned int buffers2[3];
	int nrIndex2;
};


