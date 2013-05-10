#include "WiskyBottleVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../paralelepipedo/paralelepipedo.h"
#include "../paralelepipedo/ParallelepipedVBo.h"

WiskyBottleVBO::WiskyBottleVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura)
{
	alt = argAlt;
	vertex =argVertex;
	layer =argLayers;
	id_textura = argId_textura;

	cone = new ConeVBO(alt/6,alt/8, vertex, 4, id_textura);
	cylinder1 = new CylinderVBO (alt/26, alt/5, vertex/2, layer/2, id_textura);
	cylinder2 = new CylinderVBO (alt/23, alt/50, vertex/2, layer/3, id_textura);
	parallelepiped = new ParallelepipedVBO ((2*alt)/3 - alt/10, alt/5-alt/40,alt/5-alt/40, vertex, id_textura);
}


void WiskyBottleVBO::draw(){



	glPushMatrix();
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, ((2*alt)/9), 0);
    parallelepiped->draw();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(0, (2*alt)/3 - alt/6, 0);
	cone->draw();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(0, (2*alt)/3 , 0);
    cylinder1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, (2*alt)/3 + alt/12, 0);
    cylinder2->draw();
    glPopMatrix();

}

