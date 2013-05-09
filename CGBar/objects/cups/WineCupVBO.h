#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"


class WineCupVBO : public Primitivas
{
public:
	WineCupVBO(double alt, int vertex, int layers, unsigned int id_textura);
	void drawWineCup_top(double radius, double alt,  int vertex, int layers);
	void draw();
};

