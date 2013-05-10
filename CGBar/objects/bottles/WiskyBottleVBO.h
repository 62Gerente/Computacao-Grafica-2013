#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/sphere/SphereVBO.h"
#include "../../primitives/cone/ConeVBO.h"
#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class  WiskyBottleVBO 
{
public:
	WiskyBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura);
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
