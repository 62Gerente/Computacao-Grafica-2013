#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"

class  WineBottleVBO : public Primitivas
{
public:
	WineBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura);
	void drawWineBottle_body (float altura, float raio, int vertex, int layers);
	void draw();
};

