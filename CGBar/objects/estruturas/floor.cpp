#include <GLUT/glut.h>
#include "floor.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../../primitives/cube/cube.h"

void drawFloor(double proporcao){
    glPushMatrix();
    glTranslatef(0, 0, -2.5);
    glScaled(1, 0.02, 3);
    drawCube(5, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, 0, 7.5 + 0.25);
    glScaled(2, 0.02, 1);
    drawCube(5, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, 0, -5);
    drawCylinder(5, 0.1, 10, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    glScaled(1, 0.02, 2);
    drawCube(5, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, 0, 2.5);
    glScaled(1, 0.02, 1);
    drawCube(5, 1);
    glPopMatrix();
     
    //Casa de Banho
    glPushMatrix();
    glTranslatef(5, 0, -2);
    glScaled(1, 0.02, 0.5);
    drawCube(5, 1);
    glPopMatrix();
    
    //Passagens
    
    glPushMatrix();
    glTranslatef(2.5+0.125, 0, 2.5);
    glScaled(0.05, 0.02, 0.5);
    drawCube(5, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 5+0.125);
    glScaled(0.5, 0.02, 0.05);
    drawCube(5, 1);
    glPopMatrix();
}