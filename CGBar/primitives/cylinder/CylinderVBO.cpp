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

	nrIndex = 6*(vertex*layers+2);
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

	float incAngle = (2*M_PI)/(float)vertex;
    float incHeight = height/(float)layers;
	
	float y = height/2 ;    

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = y;
	aNormal[pos] = 1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;

	for(float i = 0; i <= layers ; i++) { 
		float alpha = 0 ;

        for(int j=0; j < vertex; j++) {

			aVertex[pos] = radius*sinf(alpha);
			aNormal[pos] = sinf(alpha);
			pos++;
			aVertex[pos] = y;
			aNormal[pos] = 1;
			pos++;
			aVertex[pos] = radius*cosf(alpha);
			aNormal[pos] = cosf(alpha);
			pos++;
            
			alpha += incAngle ;
        }
		y -= incHeight ;
    }

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = y;
	aNormal[pos] = -1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
}