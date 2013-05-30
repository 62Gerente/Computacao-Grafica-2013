#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class Oven
{
private:
	ParallelepipedVBO* p_c;
	ParallelepipedVBO* p_p;
	CylinderVBO* c1;
	CylinderVBO* c2;
	CylinderVBO* c3;
	CylinderVBO* c4;
public:
	Oven(unsigned int text_c, unsigned int text_porta, unsigned int text_bocas);
	void draw();
};