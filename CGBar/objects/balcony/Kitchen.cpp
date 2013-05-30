#include "Kitchen.h"
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

Kitchen::Kitchen(unsigned int text_base, unsigned int text_topo)
{
	base_g = new ParallelepipedVBO(1,0.7,7,10,text_base,text_base,text_base,text_base,text_base,text_base);
	topo_g = new ParallelepipedVBO(0.1,0.9,7,10,text_topo,text_topo,text_topo,text_topo,text_topo,text_topo);
	borda = new ParallelepipedVBO(0.2,0.1,7,10,text_topo,text_topo,text_topo,text_topo,text_topo,text_topo);
}

void Kitchen::draw(){
// Principal
				glPushMatrix();
				glTranslatef(0,0.5,0);
				base_g->draw();
				glPopMatrix();

//Cobertura Principal
				glPushMatrix();
				glTranslatef(0,1.05,-0.1f);
				topo_g->draw();
				glPopMatrix();

//Borda Principal
				glPushMatrix();
				glTranslatef(0,1.10,0.3f);
				borda->draw();
				glPopMatrix();
}