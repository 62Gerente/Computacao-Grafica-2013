#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"

extern float cinzentoAlphaGarrafa[] ;


class  WineBottleVBO 
{
public:
	WineBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura);
	void draw();

	SphereVBO* sphere; 
	CylinderVBO* cylinder;
	CylinderVBO* cyl;
	CylinderVBO* cylinder1;
private:
	double al;
	int vrt,layer;
	unsigned int id_textura;	
};

