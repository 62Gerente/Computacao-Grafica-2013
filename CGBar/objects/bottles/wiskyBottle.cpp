#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"
#include "../paralelepipedo/paralelepipedo.h"


void drawWiskyBottle_body (float altura, float raio, int nLados, int nCamadas);
void drawWiskyBottle_top(double r, double alt,  int nlados, int ncamadas);

void drawWiskyBottle(double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    glRotatef(45, 0, 1, 0);
    glTranslatef(0, ((2*alt)/9), 0);
    drawParalelepipedo((2*alt)/3 - alt/10, alt/5-alt/40,alt/5-alt/40, nlados);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, (2*alt)/3 - alt/6, 0);
    drawWiskyBottle_top(alt/8, alt/6, nlados, 4);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, (2*alt)/3 , 0);
    drawCylinder(alt/26, alt/5, nlados/2, ncamadas/2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, (2*alt)/3 + alt/12, 0);
    drawCylinder(alt/23, alt/50, nlados/2, ncamadas/3);
    glPopMatrix();
    
}

void drawWiskyBottle_top(double raio, double altura,  int fat, int div) {
    
	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
    
	float r_inc=raio/((float)div);
    
	float fr_inc=raio/((float)fat);
	float alt_dec=altura/((float)fat);
    
	glBegin(GL_TRIANGLES);
    
	for(int i=0; i<div;i++){
        
        
		float fr=0.0;
		float alt=altura;
		for(int f=0; f<fat;f++){
            
			fr=fr_inc*((float)f);
			alt=alt_dec*((float)(fat-f));
			
			
			
			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang),alt-alt_dec,(fr+fr_inc)*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));
            
			glVertex3f(fr*sin(ang), alt, fr*cos(ang));
			glVertex3f((fr+fr_inc)*sin(ang+ang_inc),alt-alt_dec,(fr+fr_inc)*cos(ang+ang_inc));
			glVertex3f(fr*sin(ang+ang_inc), alt, fr*cos(ang+ang_inc));
            
            
            
		}
        
		float r=0;
		for(int ri=0;ri<div;ri++){
			
			r=r_inc*((float)ri);
            
			glVertex3f(r*sin(ang),0.0f, r*cos(ang));
			glVertex3f((r+r_inc)*sin(ang+ang_inc),0.0f, (r+r_inc)*cos(ang+ang_inc));
			glVertex3f((r+r_inc)*sin(ang),0.0f, (r+r_inc)*cos(ang));
            
			glVertex3f(r*sin(ang),0.0f, r*cos(ang));
			glVertex3f(r*sin(ang+ang_inc),0.0f, r*cos(ang+ang_inc));
			glVertex3f((r+r_inc)*sin(ang+ang_inc),0.0f, (r+r_inc)*cos(ang+ang_inc));
            
			
            
		}
        
		ang+=ang_inc;
	}
	glEnd();
}