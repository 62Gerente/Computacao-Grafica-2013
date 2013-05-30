#pragma once

#include "../../primitives/cube/CubeVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class FloorVBO
{
private:
	double ratio;
	unsigned int id_textura ;

	CubeVBO* cubeg1;
	CubeVBO* cubeg2;
	CylinderVBO* cylinderg3;
	CubeVBO* cubeg4;
	CubeVBO* cubeg5;
	CubeVBO* cubecb;
	CubeVBO* cubep1;
	CubeVBO* cubep2;
public:
	FloorVBO(double argRatio, unsigned int aId_textura, unsigned int aId_textura_cb, unsigned int aId_textura_c);
	void draw();
	void draw(unsigned int id_texturag1,unsigned int id_texturag2,unsigned int id_texturag3,
			  unsigned int id_texturag4,unsigned int id_texturag5,unsigned int id_texturacb,
			  unsigned int id_texturap1,unsigned int id_texturap2);
};

