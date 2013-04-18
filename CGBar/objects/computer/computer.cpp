#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../paralelepipedo/paralelepipedo.h"

void drawComputer(float altura, int nLados, int nCamandas){
    
    /* Ecra */
    glPushMatrix() ;
	glTranslatef(0, altura/2 , 0);
    glRotatef(70, 1, 0, 0);
	drawParalelepipedo(altura/20, altura - altura/3, altura-altura/5, nLados);
	glPopMatrix() ;

    
    /* Moldura */
    glPushMatrix() ;
	glTranslatef((altura - altura/5)/2, altura/2, 0);
    glRotatef(70, 1, 0, 0);
	drawParalelepipedo(altura/10, altura - altura/3 + altura/7.5, altura/15, nLados);
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(-(altura - altura/5)/2, altura/2, 0);
    glRotatef(70, 1, 0, 0);
	drawParalelepipedo(altura/10, altura - altura/3 + altura/7.5, altura/15, nLados);
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(0, altura/7 + altura/100, altura/8);
    glRotatef(70, 1, 0, 0);
	drawParalelepipedo(altura/10, altura/15, altura - altura/5, nLados);
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(0,altura -altura/7 -altura/100, -altura/8);
    glRotatef(70, 1, 0, 0);
	drawParalelepipedo(altura/10, altura/15, altura - altura/5, nLados);
	glPopMatrix() ;
    
    /* Caixa de Moedas */
    
    glPushMatrix() ;
	glTranslatef(0,0,-altura/10);
	drawParalelepipedo(altura/5, altura/1.1, altura -altura/10, nLados);
	glPopMatrix() ;

    glPushMatrix() ;
	glTranslatef(0,0,altura/3 + altura/40);
	drawParalelepipedo(altura/5 - altura/15, altura/100, altura -altura/10 -altura/15, nLados);
	glPopMatrix() ;
    
    /*Talao*/
    
    glPushMatrix() ;
	glTranslatef(altura/2 + altura/6,0,-altura/10);
	drawParalelepipedo(altura/5, altura/5, altura/4, nLados);
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(altura/2 + altura/6, altura/6 , -altura/10 -altura/20);
    glRotatef(70, 1, 0, 0);
	drawPlane(altura/6,altura/6, nLados);
	glPopMatrix() ;
}