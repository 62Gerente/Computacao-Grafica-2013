#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  VodkaCupVBO : public Primitivas
{
public:
	VodkaCupVBO(double alt,  int vertex, int layers);
	void drawVodka_top (float altura, float raio, int nLados, int nCamadas);
	void draw();
};

