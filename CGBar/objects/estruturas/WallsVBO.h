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

	CubeVBO* cx1;
	CubeVBO* cx2;
	CubeVBO* cx3;
	CubeVBO* cx4;
	CubeVBO* cx5;
	CubeVBO* cx6;
	CubeVBO* cx7;
	CubeVBO* cx8;
	CubeVBO* cx9;
	CubeVBO* cx10;
	CubeVBO* cx11;
	CubeVBO* cx12;
	CubeVBO* cx13;
	CubeVBO* cx14;
	CubeVBO* cx15;
	CubeVBO* cx16;
public:
	WallsVBO(double argRatio, unsigned int aId_textura);
	void draw();
	void drawWallsX();
	void drawWallsZ();
};

