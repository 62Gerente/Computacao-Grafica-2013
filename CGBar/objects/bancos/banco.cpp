#include <GLUT/glut.h>
#include "../../primitives/cylinder/cylinder.h"

void drawBanco(double alt, int nlados, int ncamadas){
	glPushMatrix();
	glTranslatef(0, (alt/2), 0);
    drawCylinder(alt/4, alt/10, nlados,ncamadas);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(alt/5,alt/7, 0);
    drawCylinder(alt/80, alt/1.5, nlados, ncamadas/3);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-alt/5,alt/7, 0);
    drawCylinder(alt/80, alt/1.5, nlados, ncamadas/3);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0 ,alt/9, alt/5);
    drawCylinder(alt/80, alt/1.5, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0 ,alt/9, -alt/5);
    drawCylinder(alt/80, alt/1.5, nlados, ncamadas/3);
    glPopMatrix();
}