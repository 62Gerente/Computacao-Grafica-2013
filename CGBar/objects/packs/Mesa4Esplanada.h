#pragma once

#include "../../objects/chair/chairVBO.h"
#include "../../objects/cups/BeerCupVBO.h"
#include "../../objects/cups/CocktailCupVBO.h"
#include "../../objects/table/tableVBO.h"

class Mesa4Esplanada
{
private:
	CocktailCupVBO *cc;
	BeerCupVBO *beerc;
	TableTwoVBO *tt;
	TableOneVBO *to;
	ChairClassicaTwoVBO *cct;
public:
	Mesa4Esplanada(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr, unsigned int text_mesa);
	void draw4LugaresEspRectFino();
	void draw4LugaresEspQuaFino();
};

