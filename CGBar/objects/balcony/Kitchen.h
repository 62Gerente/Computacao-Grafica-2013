#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class  Kitchen
{
public:
	Kitchen(unsigned int text_base, unsigned int text_topo);
	void draw();
private:
	ParallelepipedVBO* base_g;
	ParallelepipedVBO* topo_g;
	ParallelepipedVBO* borda;
};