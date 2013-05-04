#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"


void drawWineBottle_body (float altura, float raio, int nLados, int nCamadas);
void drawWineBottle_top(double r, double alt,  int nlados, int ncamadas);

void drawWineBottle(double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    glTranslatef(0, ((2*alt)/9), 0);
    drawWineBottle_body((2*alt)/3 - alt/10, alt/8, nlados, ncamadas);
    glPopMatrix();
    
    drawWineBottle_top(alt/8, alt, nlados, ncamadas);

    glPushMatrix();
    glTranslatef(0, (2*alt)/3 + alt/14, 0);
    drawCylinder(alt/26, alt/5, nlados/2, ncamadas/2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, (2*alt)/3 + alt/6, 0);
    drawCylinder(alt/23, alt/50, nlados/2, ncamadas/3);
    glPopMatrix();

}

void drawWineBottle_top(double r, double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    
    glTranslatef(0, (2*alt)/3 - alt/7, 0);
    
    int i, j;
    double passoH = (2*M_PI) / nlados;
    double passoV = (2*r) / (ncamadas+ncamadas*0.5);
    double altura = r* sin(asin((r-passoV)/r));
    double alturaCima = r;
    
    for(i = 0; i < nlados; i++) {
        
        double actualX = r*sin(i*passoH);
        double actualZ = r*cos(i*passoH);
        double nextX = r*sin((i+1)*passoH);
        double nextZ = r*cos((i+1)*passoH);
        double actX, actZ, nexX, nexZ, cimaActX, cimaActZ, cimaNexX, cimaNexZ;
        
        for(j= 1; j < ncamadas; j++){
            
            
            double aux = cos(asin(altura/r));
            actX = actualX * aux;
            actZ = actualZ * aux;
            nexX = nextX * aux;
            nexZ = nextZ * aux;
            
            aux = cos(asin(alturaCima/r));
            cimaActX = actualX * aux;
            cimaActZ = actualZ * aux;
            cimaNexX = nextX * aux;
            cimaNexZ = nextZ * aux;
            
            glBegin(GL_TRIANGLES);
            glVertex3f(cimaActX, alturaCima, cimaActZ);
            glVertex3f(actX, altura, actZ);

            glVertex3f(nexX, altura, nexZ);
            glEnd();
            
            glBegin(GL_TRIANGLES);
            glVertex3f(cimaNexX, alturaCima, cimaNexZ);
            glVertex3f(cimaActX, alturaCima, cimaActZ);

            glVertex3f(nexX, altura, nexZ);
            glEnd();
            
            alturaCima = altura;
            altura = r* (r-(passoV*j))/r;
            
        }
        
        
        altura = r* (r-passoV)/r;
        alturaCima = r;
        
        actualX = nextX;
        actualZ = nextZ;
        
    }
    glPopMatrix();
}

void drawWineBottle_body (float altura, float raio, int nLados, int nCamadas) {
    
    float incAngulo = (2*M_PI)/(float)nLados;
    float incAltura = altura/(float)nCamadas ;
	
	float y = altura/2 ;
    
	for(float i = 0; i <= nCamadas ; i++) {
        
        float centro[] = {0, y, 0} ;
        
		float alpha = 0 ;
        
        for(int j=0; j < nLados; j++) {
            
            float A[] = {raio*sinf(alpha), y, raio*cosf(alpha)}, B[] = {raio*sinf(alpha+incAngulo), y, raio*cosf(alpha+incAngulo)} ;
            
            if(i == nCamadas) {
                glBegin(GL_TRIANGLES) ;
                glVertex3fv(centro) ;
                glVertex3fv(B) ;
                glVertex3fv(A) ;
                glEnd() ;
            }
            
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