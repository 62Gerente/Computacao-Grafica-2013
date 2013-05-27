#pragma once

#include "../../objects/table/tableVBO.h"
#include "../../objects/bottles/WineBottleVBO.h"
#include "../../objects/bottles/WiskyBottleVBO.h"
#include "../../objects/chair/chairVBO.h"
#include "../../objects/cups/VodkaCupVBO.h"
#include "../../objects/cups/WineCupVBO.h"
#include "../../objects/cups/ShotCupVBO.h"

class Mesa2Cadeiras
{
private:
	ChairClassicaOneVBO *cco;
	WineBottleVBO *wineb;
	WiskyBottleVBO *wiskyb;
	TableCircularVBO *mcirc;
	WineCupVBO *winec;
	VodkaCupVBO *vodkac;
	ShotCupVBO *shotc;

public:
	Mesa2Cadeiras(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr, unsigned int text_mesa);
	void draw2LugaresWine();
	void draw2LugaresWisky();
	void draw2LugaresShot();
};

