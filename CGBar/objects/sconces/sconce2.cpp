#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "primitives/cylinder/cylinder.h"  
#include "primitives/sphere/sphere.h"
#include "primitives/cube/cube.h"

void drawSconce2(double alt , double comp, int nlados, int ncamadas){

		glPushMatrix();
		glTranslatef(0,alt/2 + comp/2,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(alt,comp,0.06);
		glColor3ub(88,88,88);
        drawCube(alt/6, ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/2 + comp/2- 0.03,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(alt,comp,0.09);
		glColor3ub(255,255,255);
        drawCube(alt/8, ncamadas);
        glPopMatrix();
	 }