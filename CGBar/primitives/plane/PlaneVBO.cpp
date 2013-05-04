#include "PlaneVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

PlaneVBO::PlaneVBO(float x, float z, int layers)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	float divx = x/layers;
    float divz = z/layers;

	nrIndex = 6*(layers*layers);
	int arraySize = 3*(layers*layers)*sizeof(float);
	int textSize = 2*(layers*layers)*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	int pos = 0;

	int posTex=0;

	float texIncV=1/(float)layers;
	float texIncH=1/(float)layers;

	for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
			aVertex[pos] = (-x/2) + i*divx;
			aNormal[pos] = 0;
			pos++;

			aVertex[pos] = 0;
			aNormal[pos] = 1;
			pos++;

			aVertex[pos] = z/2 - j*divz;
			aNormal[pos] = 0;
			pos++;

			aTexture[posTex] = i*texIncV;
			posTex++;
			aTexture[posTex] = j*texIncH;
			posTex++;
        }
    }

	pos = 0;

	for(int i=0; i<layers-1; i++){
        for(int j=0; j<layers-1; j++){
			aIndex[pos] = j+(layers*i);
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1));
			pos++;			
			aIndex[pos] = (j+1)+(layers*i);
			pos++;

			aIndex[pos] = j+(layers*i);
			pos++;
			aIndex[pos] = j+(layers*(i+1));
			pos++;
			aIndex[pos] = (j+1)+(layers*(i+1));
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

void PlaneVBO::draw(){

	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, nrIndex ,GL_UNSIGNED_INT, aIndex);

}