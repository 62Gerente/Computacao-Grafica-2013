#pragma once

#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/plane/PlaneVBO.h"
#include "../../primitives/cube/CubeVBO.h"

class WallsVBO
{
private:
	double ratio;
	unsigned int id_textura ;


	CubeVBO* c1;
	CubeVBO* c2;
	CubeVBO* c3;
	CubeVBO* c4;
	CubeVBO* c5;
	CubeVBO* c6;
	CubeVBO* c7;
	CubeVBO* c8;
	CubeVBO* c9;
	CubeVBO* c10;
	CubeVBO* c11;
	CubeVBO* c12;
	CubeVBO* c13;
	CubeVBO* c14;
	CubeVBO* c15;
	CubeVBO* c16;
	CubeVBO* c17;
	CubeVBO* c18;
	CubeVBO* c19;
public:
	WallsVBO(double argRatio, unsigned int aId_textura);
	void draw();
	void drawWallsX();
	void drawWallsZ();
};

