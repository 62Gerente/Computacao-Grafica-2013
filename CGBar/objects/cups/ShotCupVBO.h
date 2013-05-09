#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  ShotCupVBO : public Primitivas
{
public:
	ShotCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura);
	void drawShot_top(float height, float radius, int vertex, int layers, unsigned int id_textura);
	void draw();
private:
	double alt;
	int vertex,layer;
	unsigned int id_textura;
};


