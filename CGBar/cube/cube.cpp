#include <GL/glut.h>
#include <cores.h>
#include "cube.h"

void drawCube (float dim, int layers) {

	float div = dim/(float)layers;    
	float h = dim/2.0f ;
    
	glBegin(GL_TRIANGLES);

	/* face +y */        
    for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
            glVertex3f((-dim/2) + i*div , h, dim/2 - j*div); // C
            glVertex3f((-dim/2) + (i+1)*div, h, (dim/2) - (j+1)*div); // B
            glVertex3f((-dim/2) + i*div , h, dim/2 - (j+1)*div); // D
           
			glVertex3f((-dim/2) + i*div , h, dim/2 - j*div); // C
            glVertex3f((-dim/2) + (i+1)*div , h, dim/2 - j*div); // A
            glVertex3f((-dim/2) + (i+1)*div, h, (dim/2) - (j+1)*div); // B
        }
    }       

	/* face -y */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
            glVertex3f((-dim/2) + i*div , -h, dim/2 - j*div); // C
			glVertex3f((-dim/2) + i*div , -h, dim/2 - (j+1)*div); // D
            glVertex3f((-dim/2) + (i+1)*div, -h, (dim/2) - (j+1)*div); // B            
           
			glVertex3f((-dim/2) + (i+1)*div , -h, dim/2 - j*div); // A
			glVertex3f((-dim/2) + i*div , -h, dim/2 - j*div); // C            
            glVertex3f((-dim/2) + (i+1)*div, -h, (dim/2) - (j+1)*div); // B
        }
    } 

	/* face +z */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + i*div, h); // B			
            glVertex3f((-dim/2) + j*div, (-dim/2) + (i+1)*div, h); // C
			glVertex3f((-dim/2) + j*div, (-dim/2) + i*div, h); // A
           
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + i*div, h); // B
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + (i+1)*div, h); // D			            			
			glVertex3f((-dim/2) + j*div, (-dim/2) + (i+1)*div, h); // C  			
        }
    } 

	/* face -z */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + i*div, -h); // B			
			glVertex3f((-dim/2) + j*div, (-dim/2) + i*div, -h); // A
            glVertex3f((-dim/2) + j*div, (-dim/2) + (i+1)*div, -h); // C			
           
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + i*div, -h); // B
			glVertex3f((-dim/2) + j*div, (-dim/2) + (i+1)*div, -h); // C
			glVertex3f((-dim/2) + (j+1)*div, (-dim/2) + (i+1)*div, -h); // D			            						  			
        }
    } 

	/* face +x */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			glVertex3f(h, (-dim/2) + i*div, (-dim/2) + j*div); // A
			glVertex3f(h, (-dim/2) + (i+1)*div, (-dim/2) + j*div); // C
			glVertex3f(h, (-dim/2) + (i+1)*div, (-dim/2) + (j+1)*div); // D            
           
			glVertex3f(h, (-dim/2) + i*div, (-dim/2) + j*div); // A
			glVertex3f(h, (-dim/2) + (i+1)*div, (-dim/2) + (j+1)*div); // D            
			glVertex3f(h, (-dim/2) + i*div, (-dim/2) + (j+1)*div); // B
        }
    } 

	/* face -x */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            						
			glVertex3f(-h, (-dim/2) + (i+1)*div, (-dim/2) + j*div); // C
			glVertex3f(-h, (-dim/2) + i*div, (-dim/2) + (j+1)*div); // B
			glVertex3f(-h, (-dim/2) + (i+1)*div, (-dim/2) + (j+1)*div); // D            
           
			glVertex3f(-h, (-dim/2) + (i+1)*div, (-dim/2) + j*div); // C
			glVertex3f(-h, (-dim/2) + i*div, (-dim/2) + j*div); // A
			glVertex3f(-h, (-dim/2) + i*div, (-dim/2) + (j+1)*div); // B
        }
    } 
	glEnd();
}



