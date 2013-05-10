#pragma once

#include "../../primitives/plane/PlaneVBO.h"

class ParallelepipedVBO
{
private:
	float height;
	float width;
	float length;
	int layers;
	unsigned int id_textura ;

	PlaneVBO* planeposy;
	PlaneVBO* planenegy;
	PlaneVBO* planeposz;
	PlaneVBO* planenegz;
	PlaneVBO* planeposx;
	PlaneVBO* planenegx;
public:
	ParallelepipedVBO(float argHeight, float argWidth, float arglength, int argLayers, unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz);
	void draw();
};

