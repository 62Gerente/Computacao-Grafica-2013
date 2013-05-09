#pragma once

#include "../../Primitivas.h"
#include "../../primitives/cylinder/CylinderVBO.h"


class WineCupVBO : public Primitivas
{
public:
	WineCupVBO(double alt, double radius, int vertex, int layers);
	WineCupVBO(double alt, int vertex, int layers);
	void drawWineCup_top(double radius, double alt,  int vertex, int layers);
	void draw();
};

