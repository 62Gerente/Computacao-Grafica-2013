#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class  Balcony
{
public:
	Balcony(unsigned int text_base, unsigned int text_topo);
	void draw();
private:
	ParallelepipedVBO* base_g;
	ParallelepipedVBO* base_p;
	ParallelepipedVBO* topo_g;
	ParallelepipedVBO* topo_p;
	ParallelepipedVBO* borda;
};


