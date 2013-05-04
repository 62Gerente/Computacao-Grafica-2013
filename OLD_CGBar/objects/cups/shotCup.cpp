#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"


void drawShot_top(float altura, float raio, int div,int fat,float perc);

void drawShotCup(double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    glTranslatef(0, alt/2-alt/5, 0);
    glRotatef(180, 1, 0, 0);
    drawShot_top(alt*2, alt/6, nlados, ncamadas,0.80);
    glPopMatrix();
    
    
    drawCylinder(alt/7, alt/30, nlados, ncamadas);
}

void drawShot_top(float altura, float raio, int div,int fat, float perc){
    
	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
    
	float fr_inc=raio/((float)fat);
	float alt_dec=altura/((float)fat);
    
	glBegin(GL_TRIANGLES);
    
	for(int i=0; i<div;i++){
        
        
		float fr=0.0;
		float alt=altura;
		for(int f=fat; f>fat*perc;f--){
            
			fr=fr_inc*((float)f);
			alt=alt_dec*((float)(fat-f));
			
			
			
			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang),alt-alt_dec,(fr+fr_inc)*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));
            
			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));
			glVertex3f(fr*sin(ang+ang_inc), alt, fr*cos(ang+ang_inc));
		}
        
		ang+=ang_inc;
	}
	glEnd();
}