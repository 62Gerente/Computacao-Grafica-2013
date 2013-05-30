#pragma once

#include "../../objects/paralelepipedo/ParallelepipedVBO.h"

class FrameCoimbra
{
private:
	ParallelepipedVBO* p_bd;
	ParallelepipedVBO* p_be;
	ParallelepipedVBO* p_bc;
	ParallelepipedVBO* p_bb;
	ParallelepipedVBO* p_q;
public:
	FrameCoimbra(unsigned int text_borda, unsigned int text_quadro);
	void draw();
};

