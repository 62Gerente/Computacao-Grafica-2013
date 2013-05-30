#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class BigFrame
{
private:
	ParallelepipedVBO* p_bd;
	ParallelepipedVBO* p_be;
	ParallelepipedVBO* p_bc;
	ParallelepipedVBO* p_bb;
	ParallelepipedVBO* p_q;
public:
	BigFrame(unsigned int text_borda, unsigned int text_quadro);
	void draw();
};

