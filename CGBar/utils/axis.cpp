#include <GLUT/glut.h>
#include "axis.h"

void drawAxis (float dimX, float dimY, float dimZ) {	

	glBegin(GL_LINES) ;		
		
		glVertex3f(0, 0.0f, 0.0f) ;
		glVertex3f(dimX, 0.0f, 0.0f) ;
		
		glVertex3f(0.0f, 0, 0.0f) ;
		glVertex3f(0.0f, dimY, 0.0f) ;
		
		glVertex3f(0.0f, 0.0f, 0) ;
		glVertex3f(0.0f, 0.0f, dimZ) ;

	glEnd();

}

void drawAxisFull (float dimX, float dimY, float dimZ) {	

	glBegin(GL_LINES) ;		
		
		glVertex3f(-dimX, 0.0f, 0.0f) ;
		glVertex3f(dimX, 0.0f, 0.0f) ;
		
		glVertex3f(0.0f, -dimY, 0.0f) ;
		glVertex3f(0.0f, dimY, 0.0f) ;
		
		glVertex3f(0.0f, 0.0f, -dimZ) ;
		glVertex3f(0.0f, 0.0f, dimZ) ;

	glEnd();
}