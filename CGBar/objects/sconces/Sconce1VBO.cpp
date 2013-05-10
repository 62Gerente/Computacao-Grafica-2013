#include "Sconce1VBO.h"

#include <GLUT/glut.h>

Sconce1VBO::Sconce1VBO(	double altarg, int nladosarg, int ncamadasarg, unsigned int id_textura1arg, unsigned int id_textura2arg, unsigned int id_textura3arg)
{
	alt = altarg;	
	nlados = nladosarg;	
	ncamadas = ncamadasarg;	
	id_textura1 = id_textura1arg;	
	id_textura2 = id_textura2arg;	
	id_textura3 = id_textura3arg;	

	base = new CylinderVBO(alt/20, alt/18, nlados, ncamadas/3, id_textura1arg) ;
	suporte = new CylinderVBO(alt/120, alt/8, nlados, ncamadas, id_textura2arg);
	esfera = new SphereVBO(alt/40, nlados,ncamadas, id_textura1arg);
	apoio1 = new CylinderVBO(alt/120, alt/5, nlados, ncamadas, id_textura2arg);
	apoio2 = new CylinderVBO(alt/120, alt/5, nlados, ncamadas, id_textura2arg);
	apoio3 = new CylinderVBO(alt/120, alt/5, nlados, ncamadas, id_textura2arg);
	apoio4 = new CylinderVBO(alt/120, alt/5, nlados, ncamadas, id_textura2arg);
	abajur = new CylinderVBO(alt/5, alt/8, nlados, ncamadas, id_textura3arg);
}

void Sconce1VBO::draw() {

		glPushMatrix();
		glTranslatef(0,alt/4, 0);
        base->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/6, 0);
        suporte->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/10, 0);
        esfera->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(alt/10,alt/10, 0);
		glRotatef(90,0,0,1);
        apoio1->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(-alt/10,alt/10, 0);
		glRotatef(90,0,0,1);
        apoio2->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/10, alt/10);
		glRotatef(90,1,0,0);
        apoio3->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/10, -alt/10);
		glRotatef(90,1,0,0);
        apoio4->draw();
        glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0,alt/22, 0);
        abajur->draw();
        glPopMatrix();

}
