#include <GLUT/glut.h>
#include <math.h>

void drawPlane(float width, float length, float anglex, float angley, float anglez){
    glPushMatrix();
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    glRotatef(anglez, 0, 0, 1);
    
    glBegin(GL_TRIANGLES);
    
    glVertex3f(width/2,0,length/2) ;
    glVertex3f(width/2,0,-length/2) ;
    glVertex3f(-width/2,0,-length/2) ;
    
    glVertex3f(-width/2,0,-length/2) ;
    glVertex3f(-width/2,0,length/2) ;
    glVertex3f(width/2,0,length/2) ;
    
    glEnd();
    glPopMatrix();
    
}