#include "Balcony.h"
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

Balcony::Balcony(unsigned int text_base, unsigned int text_topo)
{
	base_g = new ParallelepipedVBO(1,0.7,6,10,text_base,text_base,text_base,text_base,text_base,text_base);
	base_p = new ParallelepipedVBO(1,0.8,1,10,text_base,text_base,text_base,text_base,text_base,text_base);
	topo_g = new ParallelepipedVBO(0.1,0.9,6,10,text_topo,text_topo,text_topo,text_topo,text_topo,text_topo);
	topo_p = new ParallelepipedVBO(0.1,0.9,3,10,text_topo,text_topo,text_topo,text_topo,text_topo,text_topo);
	borda = new ParallelepipedVBO(0.2,0.1,4.4,10,text_topo,text_topo,text_topo,text_topo,text_topo,text_topo);
}

void Balcony::draw(){
// Principal
				glPushMatrix();
				glTranslatef(0,0.5,0);
				base_g->draw();
				glPopMatrix();

//Pequeno
				glPushMatrix();
				glTranslatef(2.6f,0.5,2.0f);
				glRotatef(90,0,1,0);
				base_p->draw();
				glPopMatrix();

//Cobertura Principal
				glPushMatrix();
				glTranslatef(0,1.05,-0.1f);
				topo_g->draw();
				glPopMatrix();

//Borda Principal
				glPushMatrix();
				glTranslatef(-0.8f,1.10,0.3f);
				borda->draw();
				glPopMatrix();

//Cobertura Pequeno
				glPushMatrix();
				glTranslatef(2.65f,1.04,0.95f);
				glRotatef(90,0,1,0);
				topo_p->draw();
				glPopMatrix();
}