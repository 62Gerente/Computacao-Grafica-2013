#include "Fridge.h"

#include <GLUT/glut.h>

Fridge::Fridge(unsigned int text){
	p_c = new ParallelepipedVBO(2,0.8,1.3,10,text,text,text,text,text,text);
	p_pg = new ParallelepipedVBO(1.2,0.1,1.1,10,text,text,text,text,text,text);
	p_pp = new ParallelepipedVBO(0.6,0.1,1.1,10,text,text,text,text,text,text);
}

void Fridge::draw(){	
	glPushMatrix();
	glTranslatef(0,1,0);
	p_c->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.65,-0.43);
	p_pg->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.3+1.35,-0.43);
	p_pp->draw();
	glPopMatrix();
}
