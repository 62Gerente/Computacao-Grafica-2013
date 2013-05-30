#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

class Microwave
{
private:
	ParallelepipedVBO* p_c;
	ParallelepipedVBO* p_p;
	CylinderVBO* b1;
	CylinderVBO* b2;
public:
	Microwave(unsigned int text_c, unsigned int text_porta, unsigned int text_b);
	void draw();
};