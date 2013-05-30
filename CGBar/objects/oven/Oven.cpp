#include "Oven.h"

#include <GLUT/glut.h>

Oven::Oven(unsigned int text_c, unsigned int text_porta, unsigned int text_bocas){
	p_c = new ParallelepipedVBO(1.1,0.95,1.6,10,text_c,text_c,text_c,text_c,text_c,text_c);
	p_p = new ParallelepipedVBO(0.7,0.1,1.3,10,text_porta,text_porta,text_porta,text_porta,text_porta,text_porta);

	c1 = new CylinderVBO(0.17,0.1,20,20,text_bocas);
	c2 = new CylinderVBO(0.13,0.1,20,20,text_bocas);
}

void Oven::draw(){	
	glPushMatrix();
	glTranslatef(0,0.55,0);
	p_c->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.55,-0.45);
	p_p->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.35,1.09,0.17);
	c1->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.35,1.09,0.17);
	c2->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.35,1.09,-0.23);
	c1->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.35,1.09,-0.23);
	c2->draw();
	glPopMatrix();
}
