#include "CubeVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

CubeVBO::CubeVBO(float dim, int layers, unsigned int id_textura) : Primitivas(id_textura)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex = 6*(layers*layers*6);
	int arraySize = 3*(layers*layers*6)*sizeof(float);
	int textSize = 2*(layers*layers*6)*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	float div = dim/(float)(layers-1);    
	float h = dim/2.0f ;

	int pos = 0;

	/* Textura */
	int pos_textura = 0 ;	   

		/* face +y */        
    for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;			
			pos++;

			aVertex[pos] = h;
			aNormal[pos] = 1;
			pos++;

			aVertex[pos] = dim/2 - j*div;
			aNormal[pos] = 0;			
			pos++;
			
			aTexture[pos_textura++] = (((-dim/2) + i*div) - (-dim/2))/dim ;
			aTexture[pos_textura++] = 1-((((-dim/2) + j*div) - (-dim/2))/dim) ;
        }
    }       

	/* face -y */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;			
			pos++;

			aVertex[pos] = -h;
			aNormal[pos] = -1;
			pos++;

			aVertex[pos] = dim/2 - j*div;
			aNormal[pos] = 0;			
			pos++;

			aTexture[pos_textura++] = (((-dim/2) + i*div) - (-dim/2))/dim ;
			aTexture[pos_textura++] = (((-dim/2) + j*div) - (-dim/2))/dim ;
        }
    } 

	/* face +z */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			aVertex[pos] = (-dim/2) + j*div;
			aNormal[pos] = 0;			
			pos++;

			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;
			pos++;

			aVertex[pos] = h;
			aNormal[pos] = 1;			
			pos++;		

			aTexture[pos_textura++] = (((-dim/2) + j*div) - (-dim/2))/dim ;
			aTexture[pos_textura++] = 1-((((-dim/2) + i*div) - (-dim/2))/dim) ;
        }
    } 

	/* face -z */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			aVertex[pos] = (-dim/2) + j*div;
			aNormal[pos] = 0;			
			pos++;

			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;
			pos++;

			aVertex[pos] = -h;
			aNormal[pos] = -1;			
			pos++;		

			aTexture[pos_textura++] = 1-((((-dim/2) + j*div) - (-dim/2))/dim) ;
			aTexture[pos_textura++] = 1-((((-dim/2) + i*div) - (-dim/2))/dim) ;
        }
    } 

	/* face +x */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            			
			aVertex[pos] = h;
			aNormal[pos] = 1;			
			pos++;

			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;
			pos++;

			aVertex[pos] = (-dim/2) + j*div;
			aNormal[pos] = 0;			
			pos++;	

			aTexture[pos_textura++] = 1-((((-dim/2) + j*div) - (-dim/2))/dim) ;
			aTexture[pos_textura++] = 1-((((-dim/2) + i*div) - (-dim/2))/dim) ;
        }
    } 

	/* face -x */
	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){            						
			aVertex[pos] = -h;
			aNormal[pos] = -1;			
			pos++;

			aVertex[pos] = (-dim/2) + i*div;
			aNormal[pos] = 0;
			pos++;

			aVertex[pos] = (-dim/2) + j*div;
			aNormal[pos] = 0;			
			pos++;		

			aTexture[pos_textura++] = (((-dim/2) + j*div) - (-dim/2))/dim ;
			aTexture[pos_textura++] = 1-((((-dim/2) + i*div) - (-dim/2))/dim) ;
        }
    } 

	pos = 0;
	int actface = 0;

		/* face +y */        
    for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){
			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;			
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;

			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;
        }
    }       

	actface += layers*layers;

	/* face -y */
	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){
			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;			

			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;
        }
    } 

	actface += layers*layers;

	/* face +z */
	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){            			
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;			
			aIndex[pos] = j+(layers*i) + actface;
			pos++;

			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;
        }
    } 

	actface += layers*layers;

	/* face -z */
	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){            				
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;			

			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;
        }
    } 

	actface += layers*layers;

	/* face +x */
	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){  
			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;	
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;		

			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;	
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
        }
    } 

	actface += layers*layers;

	/* face -x */
	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){            						
			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;	
			aIndex[pos] = j+(layers*(i+1)) + actface;
			pos++;		

			aIndex[pos] = j+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*i) + actface;
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1)) + actface;
			pos++;	
        }
    } 

	glGenBuffers(3, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, aVertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, aNormal, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, textSize, aTexture, GL_STATIC_DRAW);

	free(aVertex);
	free(aNormal);
	free(aTexture);
}
