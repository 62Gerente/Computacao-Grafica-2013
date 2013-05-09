#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class  CocktailCupVBO : public Primitivas
{
public:
	CocktailCupVBO(double alt ,  int vertex, int layers, unsigned int id_textura);
	void drawCocktailCup_top (double r, double alt, int vertex, int layers);
	void draw();
private:
	double a;
	int v,l;
};

