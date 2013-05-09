#include "CocktailCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>



CocktailCupVBO::CocktailCupVBO(double alt ,  int vertex, int layers, unsigned int id_textura) : Primitivas(id_textura)
{
	a = alt;
	v = vertex;
	l =layers;
}

void CocktailCupVBO::drawCocktailCup_top (double r, double alt, int vertex, int layers){
	glPushMatrix();
    glTranslatef(0, (alt/2)-(2*r/3), 0);
    glRotatef(90, 1, 0, 0);
	glutSolidCone(r, alt/5, vertex, layers);
    glPopMatrix();
}

void CocktailCupVBO::draw(){

	drawCocktailCup_top(a/6, a, v, l);

    glPushMatrix();
    glTranslatef(0,a/2/4, 0);
	CylinderVBO* cylinder = new CylinderVBO(a/80, a/5, v, l/3, 0);
	cylinder->draw();
    glPopMatrix();
    
   
    glPushMatrix();
    glRotatef(-90,1,0,0);
    glutSolidCone(a/20, a/25, v, l);
    glPopMatrix();

	glPushMatrix();
	CylinderVBO* cyl = new CylinderVBO(a/9, a/200, v, l, 0);
	cyl->draw();
    glPopMatrix();
    

}