#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"
#include "../../primitives/cone/ConeVBO.h"

class  WiskyBottleVBO 
{
public:
	WiskyBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura);
	void draw();
private:
	double alt;
	int vertex,layer;
	unsigned int id_textura;
};
