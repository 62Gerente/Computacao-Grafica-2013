#pragma once

#include "../../primitives/cube/CubeVBO.h"

class CeilingVBO
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
public:
	CeilingVBO(double argRatio, unsigned int aId_textura);
	void draw();
	void draw(unsigned int id_texturag1,unsigned int id_texturag2,unsigned int id_texturag3,
			  unsigned int id_texturacb,
			  unsigned int id_texturap1,unsigned int id_texturap2);
};

