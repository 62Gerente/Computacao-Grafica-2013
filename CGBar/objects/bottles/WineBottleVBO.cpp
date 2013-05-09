#include "WineBottleVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

double al;
int vrt,layer;

WineBottleVBO::WineBottleVBO(double alt,  int vertex, int layers, unsigned int id_textura) : Primitivas(id_textura)
{
	al = alt;
	vrt = vertex;
	layer =layers;
}

void WineBottleVBO::drawWineBottle_body (float altura, float raio, int vertex, int layers){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	float incAngulo = (2*M_PI)/(float)(vertex-1);
    float incAltura = altura/(float)(layers-1) ;
	
	float y = altura/2 ;
	int pos = 0;

	nrIndex = 12*(vertex*layers);
	int arraySize = (6*(vertex*(layers+1)))*sizeof(float);
	int textSize = (4*(vertex*layers+2))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	for(float i = 0; i < layers ; i++) { 
		float alpha = 0 ;

        for(int j=0; j < vertex; j++) {
				aVertex[pos] = raio*sinf(alpha);
				aNormal[pos] = sinf(alpha);
				pos++;
				aVertex[pos] = y;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = raio*cosf(alpha);
				aNormal[pos] = cosf(alpha);
				pos++;

			alpha += incAngulo ;
        }
		y -= incAltura;
    }

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = altura/2;
	aNormal[pos] = 1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;

	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++;
	aVertex[pos] = -altura/2;
	aNormal[pos] = -1;
	pos++;
	aVertex[pos] = 0;
	aNormal[pos] = 0;
	pos++; 

	float alpha = 0 ;

    for(int j=0; j < vertex; j++) {
		aVertex[pos] = raio*sinf(alpha);
		aNormal[pos] = 0;
		pos++;
		aVertex[pos] = altura/2;
		aNormal[pos] = 1;
		pos++;
		aVertex[pos] = raio*cosf(alpha);
		aNormal[pos] = 0;
		pos++;

		alpha += incAngulo ;
	}
	
	alpha = 0 ;

	for(int j=0; j < vertex; j++){
		aVertex[pos] = raio*sinf(alpha);
		aNormal[pos] = 0;
		pos++;
		aVertex[pos] = -altura/2;
		aNormal[pos] = -1;
		pos++;
		aVertex[pos] = raio*cosf(alpha);
		aNormal[pos] = 0;
		pos++;
           

		alpha += incAngulo ;
    }

	pos = 0 ;  

	for(float i = 0; i < layers-1 ; i++) { 
        for(int j=0; j < vertex-1; j++) {			          
					aIndex[pos] = j+(vertex*i);
					pos++;
					aIndex[pos] = j+(vertex*(i+1));
					pos++;
					aIndex[pos] = (j+1)+(vertex*(i+1));
					pos++;

					aIndex[pos] = j+(vertex*i);
					pos++;
					aIndex[pos] = (j+1)+(vertex*(i+1));
					pos++;
					aIndex[pos] = (j+1)+(vertex*i);
					pos++;
        }
    }


    for(int j=0; j < vertex-1; j++) {			          
					aIndex[pos] = layers*vertex+j+2+vertex;
					pos++;
					aIndex[pos] = layers*vertex+1;
					pos++;
					aIndex[pos] = layers*vertex+3+j+vertex;
					pos++;
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


void WineBottleVBO::draw(){

	glPushMatrix();
    glTranslatef(0, ((2*al)/9), 0);
    drawWineBottle_body((2*al)/3 - al/10, al/8, vrt, layer);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glDrawElements(GL_TRIANGLES, nrIndex ,GL_UNSIGNED_INT, aIndex);
    glPopMatrix();
    
	glPushMatrix();
    glTranslatef(0, (2*al)/3 - al/7, 0);
    SphereVBO* sphere = new SphereVBO (al/8, vrt, layer, 0); 
	sphere->draw();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0, (2*al)/3 + al/14, 0);
    CylinderVBO* cylinder = new CylinderVBO(al/26, al/5, vrt/2, layer/2, 0);
	cylinder->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, (2*al)/3 + al/6, 0);
	CylinderVBO* cyl = new CylinderVBO(al/23, al/50, vrt/2, layer/3, 0);
	cyl->draw();
    glPopMatrix();

	
}
