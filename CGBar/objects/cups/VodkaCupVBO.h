#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  VodkaCupVBO : public Primitivas
{
public:
	VodkaCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura);
	void drawVodka_top (float altura, float raio, int nLados, int nCamadas);
	void draw();

	CylinderVBO* cylinder;
private:
	double alt;
	int vertex,layer;
	unsigned int id_textura;
};


