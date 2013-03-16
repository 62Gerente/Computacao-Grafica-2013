#include <GLUT/glut.h>
#include <math.h>

void drawPlane(float x, float z, int layers){
    float divx = x/layers;
    float divz = z/layers;
    
    glBegin(GL_TRIANGLES);
    
    for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
            glVertex3f((-x/2) + i*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx, 0, (z/2) - (j+1)*divz);
            glVertex3f((-x/2) + i*divx , 0, z/2 - (j+1)*divz);
           
            glVertex3f((-x/2) + i*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx, 0, (z/2) - (j+1)*divz);
        }
    }
    
    glEnd();
}

void drawPlane(float width, float length){    
    glBegin(GL_TRIANGLES);
    
    glVertex3f(width/2,0,length/2) ;
    glVertex3f(width/2,0,-length/2) ;
    glVertex3f(-width/2,0,-length/2) ;
    
    glVertex3f(-width/2,0,-length/2) ;
    glVertex3f(-width/2,0,length/2) ;
    glVertex3f(width/2,0,length/2) ;
    
    glEnd();
}

void drawPlaneRotated(float width, float length, float anglex, float angley, float anglez){
    glPushMatrix();
    
    glRotatef(anglex, 1, 0, 0);
    glRotatef(angley, 0, 1, 0);
    glRotatef(anglez, 0, 0, 1);
    
    drawPlane(width, length);
    
    glPopMatrix();
    
}
