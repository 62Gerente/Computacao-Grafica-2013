#include "SphereVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

SphereVBO::SphereVBO(float radius, int vertex, int layers)
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

	double divH = (2*M_PI) / vertex;
    double divV = (M_PI) / layers;
	float angv, angh;

	int pos = 0;


	for(int i=0; i<=layers;i++){
		angv=divV*i;

		for(int j=0; j<=vertex;j++){
			angh=divH*j;

			aVertex[pos]=radius*sin(angv)*sin(angh);
			aNormal[pos]=sin(angv)*sin(angh);
			pos++;

			aVertex[pos]=radius*cos(angv);
			aNormal[pos]=cos(angv);
			pos++;

			aVertex[pos]=radius*sin(angv)*cos(angh);
			aNormal[pos]=sin(angv)*cos(angh);
			pos++;
		}

	}

	pos=0;

	for(int i=0; i<layers;i++){

		for(int j=0; j<vertex;j++){
			aIndex[pos]=j+(i*(layers+1)); 
			pos++;
			aIndex[pos]=(j+1)+(i*(layers+1));
			pos++;
			aIndex[pos]=j+((i+1)*(layers+1)); 
			pos++;
			
			aIndex[pos]=(j+1)+(i*(layers+1));
			pos++;
			aIndex[pos]=(j+1)+((i+1)*(layers+1)); 
			pos++;
			aIndex[pos]=j+((i+1)*(layers+1)); 
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