#include "FrameCoimbra.h"

#include <GLUT/glut.h>

FrameCoimbra::FrameCoimbra(unsigned int text_borda, unsigned int text_quadro){
	p_q = new ParallelepipedVBO(1.0,0.05,0.7,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_quadro);
	p_bc = new ParallelepipedVBO(0.1,0.1,0.7,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_borda);
	p_bd = new ParallelepipedVBO(1.1,0.05,0.1,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_borda);
}

void FrameCoimbra::draw(){	
	p_q->draw();

	glPushMatrix();
	glTranslatef(0,0.5,0);
	p_bc->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-0.5,0);
	p_bc->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4,0,0);
	p_bd->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4,0,0);
	p_bd->draw();
	glPopMatrix();
}

