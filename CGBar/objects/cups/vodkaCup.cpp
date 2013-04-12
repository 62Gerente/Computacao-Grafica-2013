#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"


void drawVodka_top (float altura, float raio, int nLados, int nCamadas);

void drawVodkaCup(double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    glTranslatef(0, (3*alt)/10, 0);
    glRotatef(180, 1, 0, 0);
    drawVodka_top((3*alt)/5, alt/9, nlados, ncamadas);
    glPopMatrix();
    
    
    drawCylinder(alt/9, alt/40, nlados, ncamadas);
}

void drawVodka_top (float altura, float raio, int nLados, int nCamadas) {
    
    float incAngulo = (2*M_PI)/(float)nLados;
    float incAltura = altura/(float)nCamadas ;
	
	float y = altura/2 ;
    
	for(float i = 0; i <= nCamadas ; i++) {
 
		float alpha = 0 ;
        
        for(int j=0; j < nLados; j++) {
            
            float A[] = {raio*sinf(alpha), y, raio*cosf(alpha)}, B[] = {raio*sinf(alpha+incAngulo), y, raio*cosf(alpha+incAngulo)} ;
            
            if(i < nCamadas) {
                float C[] = {raio*sinf(alpha), y-incAltura, raio*cosf(alpha)}, D[] = {raio*sinf(alpha+incAngulo), y-incAltura, raio*cosf(alpha+incAngulo)} ;
                
                glBegin(GL_TRIANGLES) ;
                glVertex3fv(A) ;
                glVertex3fv(C) ;
                glVertex3fv(D) ;
                
                glVertex3fv(B) ;
                glVertex3fv(A) ;
                glVertex3fv(D) ;
                glEnd() ;
            }
			alpha += incAngulo ;
        }
		y -= incAltura ;
    }
}