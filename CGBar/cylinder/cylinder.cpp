#include <GLUT/glut.h>
#include <math.h>

void drawCylinder (float raio, float altura, int nLados, int nCamadas) {
    
    float angulo = (2*PI)/(float)nLados, i=0 ;
    float h = altura/(float)nCamadas ;

    for(float j=altura/2; j >= -altura/2 ; j-=h) {          
        float centro[] = {0, j, 0} ;

        for(float i=0; i < 2*PI; i+= angulo) {

            float A[] = {raio*sin(i), j, raio*cos(i)}, B[] = {raio*sin(i+angulo), j, raio*cos(i+angulo)} ;
        
            if(j-h <= -altura/(float)2) {               
                glBegin(GL_TRIANGLES) ;
                    glVertex3fv(A) ;
                    glVertex3fv(centro) ;
                    glVertex3fv(B) ;
                glEnd() ;
            }
            else {              
                glBegin(GL_TRIANGLES) ;
                    glVertex3fv(B) ;
                    glVertex3fv(centro) ;
                    glVertex3fv(A) ;
                glEnd() ;
            }
        

            if(j-h >= -altura/2) {
                float C[] = {raio*sin(i), j-h, raio*cos(i)}, D[] = {raio*sin(i+angulo), j-h, raio*cos(i+angulo)} ;
                
                glBegin(GL_TRIANGLES) ;                 
                    glVertex3fv(A) ;
                    glVertex3fv(C) ;
                    glVertex3fv(D) ;
                    
                    glVertex3fv(B) ;
                    glVertex3fv(A) ;
                    glVertex3fv(D) ;
                glEnd() ;
            }

        }
    }
}    


/* void drawCylinder(float radius, float height, int vertex){
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
} */