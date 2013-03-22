#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void drawCylinder (float raio, float altura, int nLados, int nCamadas) {
    
    float angulo = (2*M_PI)/(float)nLados;
    float h = altura/(float)nCamadas ;
	float y = altura/2 ;    

	for(float j = 0; j <= nCamadas ; j++) { 

        float centro[] = {0, y, 0} ;

		float i = 0 ;

        for(int n=0; n < nLados; n++) {

            float A[] = {raio*sinf(i), y, raio*cosf(i)}, B[] = {raio*sinf(i+angulo), y, raio*cosf(i+angulo)} ;            
			
				if(j == nCamadas) {               
					glBegin(GL_TRIANGLES) ;
						glVertex3fv(A) ;
						glVertex3fv(centro) ;
						glVertex3fv(B) ;
					glEnd() ;
				}
				if(j == 0) {				          
					glBegin(GL_TRIANGLES) ;
						glVertex3fv(B) ;
						glVertex3fv(centro) ;
						glVertex3fv(A) ;
					glEnd() ;
				}       

            if(j < nCamadas) {
                float C[] = {raio*sinf(i), y-h, raio*cosf(i)}, D[] = {raio*sinf(i+angulo), y-h, raio*cosf(i+angulo)} ;
                
                glBegin(GL_TRIANGLES) ;                 
                    glVertex3fv(A) ;
                    glVertex3fv(C) ;
                    glVertex3fv(D) ;
                    
                    glVertex3fv(B) ;
                    glVertex3fv(A) ;
                    glVertex3fv(D) ;
                glEnd() ;
            }
			i = i + angulo ;
        }
		y = y - h ;
    }
}    


 void drawCylinder(float radius, float height, int vertex){
    int i;
    float twoPi = 2.0f * M_PI;
    float angact = 0.0f;
    float ang = twoPi/((float)vertex);
    
    glBegin(GL_TRIANGLES);
    
    for(i=0;i<vertex;i++){
        glVertex3f(0,-(height/2),0);
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        glVertex3f(radius*sin(angact), -(height/2), radius*cos(angact));
        
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

