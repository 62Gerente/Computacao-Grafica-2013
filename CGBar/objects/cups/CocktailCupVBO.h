#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/cone/ConeVBO.h"


class  CocktailCupVBO : public Primitivas
{
public:
	CocktailCupVBO(double alt ,  int vertex, int layers, unsigned int id_textura);
	void drawCocktailCup_top ();
	void draw();

	CylinderVBO* cylinder;
    ConeVBO* cone ;
    CylinderVBO* cyl;
private:
	double alt, rad, altura;
	int vertex,layers;
	unsigned int argId_textura;
};

