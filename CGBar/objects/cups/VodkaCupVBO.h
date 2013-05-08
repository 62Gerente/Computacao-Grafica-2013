#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  VodkaCupVBO : public Primitivas
{
public:
	VodkaCupVBO(double alt,  int vertex, int layers, unsigned int id_textura);
	void drawVodka_top (float altura, float raio, int nLados, int nCamadas);
	void draw();
};

