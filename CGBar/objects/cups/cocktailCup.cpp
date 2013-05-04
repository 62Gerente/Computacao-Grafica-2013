#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../primitives/cylinder/cylinder.h"

void drawCocktailCup_top(double r, double alt, int nlados, int ncamadas);


void drawCocktailCup(double alt ,  int nlados, int ncamadas) {
    
    drawCocktailCup_top(alt/6, alt, nlados, ncamadas);
    
    glPushMatrix();
    glTranslatef(0,alt/2/4, 0);
    drawCylinder(alt/80, alt/5, nlados, ncamadas/3);
    glPopMatrix();
    
    glPushMatrix();
    drawCylinder(alt/9, alt/200, nlados, ncamadas);
    glPopMatrix();
    
    glPushMatrix();
    
    glRotatef(-90,1,0,0);
    glutSolidCone(alt/20, alt/25, nlados, ncamadas);
    glPopMatrix();
}


void drawCocktailCup_top(double r, double alt,  int nlados, int ncamadas) {
    glPushMatrix();
    
    glTranslatef(0, (alt/2)-(2*r/3), 0);
    glRotatef(90, 1, 0, 0);
    
    glutSolidCone(r, alt/5, nlados, ncamadas);
    
    glPopMatrix();
}