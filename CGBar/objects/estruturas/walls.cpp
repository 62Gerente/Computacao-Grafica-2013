#include <GLUT/glut.h>
#include "walls.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../../primitives/cube/cube.h"

void drawWallsZ(double proporcaoP){
    glPushMatrix();
    glScaled(proporcaoP, proporcaoP, proporcaoP);
    double proporcao = 3;
    double espessura = 0.01*proporcao;
    double altura = 2;

    //Sala principal
    //paralelas
    glPushMatrix();
    glTranslatef(-5, altura/2, -4);
    glScaled(5/proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 30);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, 5.25);
    glScaled(2/proporcao, altura/12, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, 5.25);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.2/3, altura/2, 5.25);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, 5);
    glScaled(2/proporcao, altura/12, espessura);
    drawCube(proporcao, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, 5);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5.2/3, altura/2, 5);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 2);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, -4);
    glScaled(2/proporcao, altura/12, espessura);
    drawCube(proporcao, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, -4);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5.2/3, altura/2, -4);
    glScaled(1.5/proporcao, altura/3, espessura);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    //Entrada escadas
    //paralelas
    glPushMatrix();
    glTranslatef(-5, altura/2, 5);
    glScaled(5/proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, altura/2, 5.25);
    glScaled(5/proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, altura/2, 10.25);
    glScaled(10/proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 50);
    glPopMatrix();
    
    //Entrada    
    //paralelas
    
    glPushMatrix();
    glTranslatef(5 + 0.25, altura/2, 0);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, altura/2, 5);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    
    //Casa de Banho
    //paralelas
    glPushMatrix();
    glTranslatef(5, altura/2, -0.75);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5, altura/2, -3.25);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    
    //Passagens
    glPushMatrix();
    glTranslatef(2.625, altura/2, 1.25);
    glScaled(0.05, altura/proporcao, espessura);
    drawCube(proporcao, 2);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2.625, altura/2, 3.75);
    glScaled(0.05, altura/proporcao, espessura);
    drawCube(proporcao, 2);
    glPopMatrix();
    
    glPopMatrix();
}
void drawWallsX(double proporcaoP){

    glPushMatrix();
    glScaled(proporcaoP, proporcaoP, proporcaoP);
    
    double proporcao = 3;
    double espessura = 0.01*proporcao;
    double altura = 2;
    
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 0);
    glScaled(espessura, altura/proporcao, 3.3333333);
    drawCube(proporcao, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    drawCube(proporcao, 15);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.75, altura/2, 2.5);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    drawCube(proporcao, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.5, altura/2, -2);
    glScaled(espessura, altura/proporcao, 0.8);
    drawCube(proporcao, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    drawCube(proporcao, 2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    drawCube(proporcao, 2);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    drawCube(proporcao, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    drawCube(proporcao, 10);
    glPopMatrix();

    //
    glPushMatrix();
    glTranslatef(2.75, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    drawCube(proporcao, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    drawCube(proporcao, 10);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, -2);
    glScaled(espessura, altura/12, 2/proporcao + 0.25);
    drawCube(proporcao, 5);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, altura/2, -0.5);
    glScaled(espessura, altura/3, 1/proporcao);
    drawCube(proporcao, 20);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, -6);
    glScaled(espessura, altura/3, 5.5/proporcao);
    drawCube(proporcao, 20);
    glPopMatrix();
    
    glPopMatrix();
}
