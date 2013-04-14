#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"

void drawCand_aux3(double r, double alt,  int nlados, int ncamadas) {
       
        int i, j;
        double passoH = (2*M_PI) / nlados;
        double passoV = (2*r) / (ncamadas+ncamadas*0.25);
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
                glVertex3f(actX, altura, actZ);
                glVertex3f(cimaActX, alturaCima, cimaActZ);
                glVertex3f(nexX, altura, nexZ);
                glEnd();
                
                glBegin(GL_TRIANGLES);
                glVertex3f(cimaActX, alturaCima, cimaActZ);
                glVertex3f(cimaNexX, alturaCima, cimaNexZ);
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
    }


void drawCandeeiro_3(double alt, int nlados, int ncamadas){
	glPushMatrix();
	glTranslatef(0, alt, 0);
    drawCylinder(alt/9, alt/200, nlados, ncamadas/3);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, alt/1.33, 0);
    drawCylinder(alt/90, alt/2, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glTranslatef(alt/2, 0, 0);
    drawCylinder(alt/90, alt/1, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0, alt/2.1, 0);
    drawCylinder(alt/90, alt/20, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(alt/2.15, alt/2.1, 0);
    drawCylinder(alt/90, alt/20, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(-alt/2.15, alt/2.1, 0);
    drawCylinder(alt/90, alt/20, nlados, ncamadas/3);
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0, alt/2.75, 0);
	drawCand_aux(alt/10, alt, nlados, ncamadas/3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-alt/2.15, alt/2.75, 0);
	drawCand_aux(alt/10, alt, nlados, ncamadas/3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(alt/2.15, alt/2.75, 0);
	drawCand_aux(alt/10, alt, nlados, ncamadas/3);
	glPopMatrix();
}
