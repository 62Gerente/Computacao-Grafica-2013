#include <GLUT/glut.h>
#include <math.h>
#include "sphere.h"


void drawSphere(double r, int nlados, int ncamadas) {
    
    int i, j;
    double passoH = (2*M_PI) / nlados;
    double passoV = (2*r) / ncamadas;
    double altura = r* sin(asin((r-passoV)/r));
    double alturaCima = r;
    
    for(i = 0; i < nlados; i++) {
        
        double actualX = r*sin(i*passoH);
        double actualZ = r*cos(i*passoH);
        double nextX = r*sin((i+1)*passoH);
        double nextZ = r*cos((i+1)*passoH);
        double actX, actZ, nexX, nexZ, cimaActX, cimaActZ, cimaNexX, cimaNexZ;
        
        for(j= 0; j < ncamadas+2; j++){
            
            
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
            
            if(j!= ncamadas + 2){
                glBegin(GL_TRIANGLES);
                glVertex3f(actX, altura, actZ);
                glVertex3f(cimaActX, alturaCima, cimaActZ);
                glVertex3f(nexX, altura, nexZ);
                glEnd();
            }
            
            if(j!= 0){
                glBegin(GL_TRIANGLES);
                glVertex3f(cimaActX, alturaCima, cimaActZ);
                glVertex3f(cimaNexX, alturaCima, cimaNexZ);
                glVertex3f(nexX, altura, nexZ);
                glEnd();
            }
            
            alturaCima = altura;
            altura = r* (r-(passoV*j))/r;
            
        }
        
        
        altura = r* (r-passoV)/r;
        alturaCima = r;
        
        actualX = nextX;
        actualZ = nextZ;
        
    }
}