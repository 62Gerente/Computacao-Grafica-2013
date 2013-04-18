#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "primitives/cylinder/cylinder.h"    
#include "primitives/sphere/sphere.h"


void drawSconce(double alt ,  int nlados, int ncamadas) {

        
		glPushMatrix();
		glTranslatef(0,alt/2, 0);
        drawCylinder(alt/20, alt/18, nlados, ncamadas/3);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/2.3, 0);
        drawCylinder(alt/120, alt/8, nlados, ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/2.8, 0);
        drawSphere(alt/40, nlados,ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(alt/10,alt/2.8, 0);
		glRotatef(90,0,0,1);
        drawCylinder(alt/120, alt/5, nlados, ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(-alt/10,alt/2.8, 0);
		glRotatef(90,0,0,1);
        drawCylinder(alt/120, alt/5, nlados, ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/2.8, alt/10);
		glRotatef(90,1,0,0);
        drawCylinder(alt/120, alt/5, nlados, ncamadas);
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,alt/2.8, -alt/10);
		glRotatef(90,1,0,0);
        drawCylinder(alt/120, alt/5, nlados, ncamadas);
        glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0,alt/3.3, 0);
        drawCylinder(alt/5, alt/8, nlados, ncamadas);
        glPopMatrix();
    }