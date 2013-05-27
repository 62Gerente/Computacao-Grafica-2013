#pragma once

#include "../../objects/bottles/WineBottleVBO.h"
#include "../../objects/bottles/WiskyBottleVBO.h"
#include "../../objects/chair/chairVBO.h"
#include "../../objects/cups/VodkaCupVBO.h"
#include "../../objects/cups/WineCupVBO.h"
#include "../../objects/cups/ShotCupVBO.h"
#include "Mesa2Cadeiras.h"

class Mesa4Cadeiras
{
private:
	ChairClassicaOneVBO *cco;
	WineBottleVBO *wineb;
	WiskyBottleVBO *wiskyb;
	WineCupVBO *winec;
	ShotCupVBO *shotc;
	VodkaCupVBO *vodkac;
	Mesa2Cadeiras *mesa2c;
public:
	Mesa4Cadeiras(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr);
	void draw4LugaresWine();
	void draw4LugaresWisky();
	void draw4LugaresShot();
};

