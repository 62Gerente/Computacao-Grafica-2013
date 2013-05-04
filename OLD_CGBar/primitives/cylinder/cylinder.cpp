#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void drawCylinder (float raio, float altura, int nLados, int nCamadas) {
    
    float incAngulo = (2*M_PI)/(float)nLados;
    float incAltura = altura/(float)nCamadas ;
	
	float y = altura/2 ;    

	for(float i = 0; i <= nCamadas ; i++) { 

        float centro[] = {0, y, 0} ;

		float alpha = 0 ;

        for(int j=0; j < nLados; j++) {

            float A[] = {raio*sinf(alpha), y, raio*cosf(alpha)}, B[] = {raio*sinf(alpha+incAngulo), y, raio*cosf(alpha+incAngulo)} ;            
			
				if(i == nCamadas) {               
					glBegin(GL_TRIANGLES) ;
						glVertex3fv(A) ;
						glVertex3fv(centro) ;
						glVertex3fv(B) ;
					glEnd() ;
				}
				if(i == 0) {				          
					glBegin(GL_TRIANGLES) ;
						glVertex3fv(B) ;
						glVertex3fv(centro) ;
						glVertex3fv(A) ;
					glEnd() ;
				}       

            if(i < nCamadas) {
                float C[] = {raio*sinf(alpha), y-incAltura, raio*cosf(alpha)}, D[] = {raio*sinf(alpha+incAngulo), y-incAltura, raio*cosf(alpha+incAngulo)} ;
                
                glBegin(GL_TRIANGLES) ;                 
                    glVertex3fv(A) ;
                    glVertex3fv(C) ;
                    glVertex3fv(D) ;
                    
                    glVertex3fv(B) ;
                    glVertex3fv(A) ;
                    glVertex3fv(D) ;
                glEnd() ;
            }
			alpha += incAngulo ;
        }
		y -= incAltura ;
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

