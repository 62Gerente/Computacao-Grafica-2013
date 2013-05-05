#include "CylinderVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

CylinderVBO::CylinderVBO(float radius, float height, int vertex, int layers)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex = 6*(vertex*layers) + 3*2;
	int arraySize = 3*(vertex*layers+2)*sizeof(float);
	int textSize = 2*(vertex*layers+2)*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	int pos = 0;

	int posTex=0;

	float texIncV=1/(float)layers;
	float texIncH=1/(float)vertex;

	float incAngle = (2*M_PI)/(float)(vertex-1);
    float incHeight = height/(float)(layers-1);
	
	float y = height/2 ;    

	for(float i = 0; i < layers ; i++) { 
		float alpha = 0 ;

        for(int j=0; j < vertex; j++) {

				aVertex[pos] = radius*sinf(alpha);
				aNormal[pos] = cosf(alpha);
				pos++;
				aVertex[pos] = y;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = radius*cosf(alpha);
				aNormal[pos] = sinf(alpha);
				pos++;
            
				aTexture[posTex] = i*texIncV;
				posTex++;
				aTexture[posTex] = j*texIncH;
				posTex++;

			alpha += incAngle ;
        }
		y -= incHeight ;
    }

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = height/2;
	aNormal[pos] = 1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = -height/2;
	aNormal[pos] = -1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;

	pos = 0 ;
	y = height/2 ;    

	for(float i = 0; i < layers ; i++) { 
		float alpha = 0 ;

        for(int j=0; j < vertex-1; j++) {
			if(i == 0) {				          
					aIndex[pos] = j+(layers*i);
					pos++;
					aIndex[pos] = (j+1)+(layers*i);
					pos++;
					aIndex[pos] = layers*vertex;
					pos++;
			}       
            if(i < layers-1) {
					aIndex[pos] = j+(layers*i);
					pos++;
					aIndex[pos] = j+(layers*(i+1));
					pos++;
					aIndex[pos] = (j+1)+(layers*(i+1));
					pos++;

					aIndex[pos] = j+(layers*i);
					pos++;
					aIndex[pos] = (j+1)+(layers*(i+1));
					pos++;
					aIndex[pos] = (j+1)+(layers*i);
					pos++;
            }
			if(i == layers-1) {     
					aIndex[pos] = j+(layers*i);
					pos++;
					aIndex[pos] = layers*vertex+1;
					pos++;
					aIndex[pos] = (j+1)+(layers*i);
					pos++;
				}
			alpha += incAngle ;
        }
		y -= incHeight ;
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