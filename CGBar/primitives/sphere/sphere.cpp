#include <GLUT/glut.h>
#include <math.h>
#include "sphere.h"

void drawSphere(double r, int nlados, int ncamadas) {
    
    int i, j;
    double passoH = (2*M_PI) / nlados;
    double passoV = (M_PI) / ncamadas;
    double altura = r* sin((M_PI/2)-passoV);
    double alturaCima = r;
    
    for(i = 0; i < nlados; i++) {
        
        double actualX = r*sin(i*passoH);
        double actualZ = r*cos(i*passoH);
        double nextX = r*sin((i+1)*passoH);
        double nextZ = r*cos((i+1)*passoH);
        double actX, actZ, nexX, nexZ, cimaActX, cimaActZ, cimaNexX, cimaNexZ;
        
        for(j= 1; j < ncamadas+2; j++){
            
            
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
            altura = r* sin((M_PI/2)-(passoV*j));
            
        }
        
        altura = r* sin((M_PI/2)-passoV);
        alturaCima = r;
        
        actualX = nextX;
        actualZ = nextZ;
        
    }
}
