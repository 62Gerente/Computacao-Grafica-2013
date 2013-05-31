#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/cone/ConeVBO.h"

extern float cinzentoAlphaCopo[] ;

class WineCupVBO : public Primitivas
{
public:
	WineCupVBO(double alt, int vertex, int layers, unsigned int id_textura);
	void drawWineCup_top(double radius, double alt,  int vertex, int layers);
	void draw();

	ConeVBO* cone;
	CylinderVBO* cylinder;
	CylinderVBO* cylinder1;
	ConeVBO* cone1;
private:
	double altura, rad;
    int vert,lay,desenha;
    unsigned int id_text ;
};

