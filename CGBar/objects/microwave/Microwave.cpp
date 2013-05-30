#include "Microwave.h"

#include <GLUT/glut.h>

Microwave::Microwave(unsigned int text_c, unsigned int text_porta, unsigned int text_b){
	p_c = new ParallelepipedVBO(0.5,0.6,1,10,text_c,text_c,text_c,text_c,text_c,text_c);
	p_p = new ParallelepipedVBO(0.35,0.1,0.5,10,text_porta,text_porta,text_porta,text_porta,text_porta,text_porta);
	b1 = new CylinderVBO(0.06,0.1,20,20,text_b);
	b2 = new CylinderVBO(0.035,0.1,20,20,text_b);
}

void Microwave::draw(){	
	glPushMatrix();
	glTranslatef(0,0.3,0);
	p_c->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15,0.32,-0.30);
	p_p->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3,0.43,-0.30);
	glRotatef(90,1,0,0);
	b1->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.23,0.17,-0.30);
	glRotatef(90,1,0,0);
	b2->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.23,0.26,-0.30);
	glRotatef(90,1,0,0);
	b2->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.37,0.17,-0.30);
	glRotatef(90,1,0,0);
	b2->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.37,0.26,-0.30);
	glRotatef(90,1,0,0);
	b2->draw();
	glPopMatrix();
}
