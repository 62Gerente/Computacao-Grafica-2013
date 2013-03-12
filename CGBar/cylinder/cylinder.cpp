#include <GLUT/glut.h>
#include <math.h>

void drawCylinder(float radius, float height, int vertex){
    int i;
    float twoPi = 2.0f * M_PI;
    float angact = 0.0f;
    float ang = twoPi/((float)vertex);
    
    glBegin(GL_TRIANGLES);
    
    for(i=0;i<vertex;i++){
        glVertex3f(0,-(height/2),0);
        glVertex3f(radius*sin(angact), -(height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        
        glVertex3f(0,(height/2),0);
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), (height/2), radius*cos(angact + ang));
        
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact), -(height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        glVertex3f(radius*sin(angact + ang), (height/2), radius*cos(angact + ang));
        
        angact+=ang;
    }
    
    glEnd();
}