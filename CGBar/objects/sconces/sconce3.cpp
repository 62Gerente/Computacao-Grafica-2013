#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "primitives/cylinder/cylinder.h"    
#include "primitives/sphere/sphere.h"


void drawSconce3(double alt, int nlados, int ncamadas){

		glPushMatrix();
		glTranslatef(0,alt,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(alt,alt,0.06);
		glColor3ub(88,88,88);
        drawSphere(alt/20, nlados,ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt - 0.03,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(alt,alt,0.09);
		glColor3ub(255,255,255);
        drawSphere(alt/26, nlados,ncamadas);
        glPopMatrix();
	 }