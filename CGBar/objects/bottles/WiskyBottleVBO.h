#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"
#include "../../primitives/cone/ConeVBO.h"
#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class  WiskyBottleVBO 
{
public:
	WiskyBottleVBO(double argAlt,  int argVertex, int argLayers, unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz);
	void draw();

	ConeVBO* cone;
	CylinderVBO* cylinder1;
	CylinderVBO* cylinder2;
	ParallelepipedVBO* parallelepiped;
private:
	double alt;
	int vertex,layer;
	unsigned int id_textura;
};
