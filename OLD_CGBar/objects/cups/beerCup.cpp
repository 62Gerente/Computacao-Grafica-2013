#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"

void drawBeer_top(float altura, float raio, int div,int fat,float perc);
void drawBeer_base(float altura, float raio, int div,int fat,float perc);

void drawBeerCup(double alt ,  int nlados, int ncamadas) {
    glPushMatrix();
    glTranslatef(0, alt - alt/3.5, 0);
    glRotatef(180, 1, 0, 0);
    drawBeer_top(alt*2, alt/9, nlados, ncamadas,0.65);
    glPopMatrix();
    
    drawBeer_base(alt/6, alt/9, nlados, ncamadas, 0.5);
}

void drawBeer_top(float altura, float raio, int div,int fat, float perc){
    
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

void drawBeer_base(float altura, float raio, int div,int fat,float perc){
    
	float ang=0.0f;
	float ang_inc=2*M_PI/((float) div);
    
	float r_inc=raio/((float)div);
    
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