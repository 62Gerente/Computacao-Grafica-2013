#include "BigFrame.h"

#include <GLUT/glut.h>

BigFrame::BigFrame(unsigned int text_borda, unsigned int text_quadro){
	p_q = new ParallelepipedVBO(1.2,0.05,3,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_quadro);
	p_bc = new ParallelepipedVBO(0.1,0.1,3,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_borda);
	p_bd = new ParallelepipedVBO(1.3,0.05,0.1,10,text_borda,text_borda,text_borda,text_borda,text_borda,text_borda);
}

void BigFrame::draw(){	
	p_q->draw();

	glPushMatrix();
	glTranslatef(0,0.6,0);
	p_bc->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-0.6,0);
	p_bc->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,0,0);
	p_bd->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5,0,0);
	p_bd->draw();
	glPopMatrix();
}

