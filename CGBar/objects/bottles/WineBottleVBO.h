#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"

class  WineBottleVBO 
{
public:
	WineBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura);
	void draw();
private:
	double al;
	int vrt,layer;
};

