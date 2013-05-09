#include "WineBottleVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>



WineBottleVBO::WineBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura)
{
	al = alt;
	vrt = vertex;
	layer =layers;
}


void WineBottleVBO::draw(){

	SphereVBO* sphere = new SphereVBO (al/8, vrt, layer, 0); 
	CylinderVBO* cylinder = new CylinderVBO( al/26, al/5,vrt/2, layer/2, 0);
	CylinderVBO* cyl = new CylinderVBO(al/23, al/50, vrt/2, layer/3, 0);
	CylinderVBO* cylinder1 = new CylinderVBO( al/8, (2*al)/3 - al/10, vrt, layer, 0);

	glPushMatrix();
    glTranslatef(0, ((2*al)/9), 0);
    cylinder1->draw();
    glPopMatrix();
    
	glPushMatrix();
    glTranslatef(0, (2*al)/3 - al/7, 0);
	sphere->draw();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0, (2*al)/3 + al/14, 0);
	cylinder->draw();
    glPopMatrix();

    glPushMatrix();
   glTranslatef(0, (2*al)/3 + al/6, 0);
	cyl->draw();
    glPopMatrix();

	
}
