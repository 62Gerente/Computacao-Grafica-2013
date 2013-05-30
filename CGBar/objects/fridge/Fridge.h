#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class Fridge
{
private:
	ParallelepipedVBO* p_c;
	ParallelepipedVBO* p_pg;
	ParallelepipedVBO* p_pp;
public:
	Fridge(unsigned int text);
	void draw();
};