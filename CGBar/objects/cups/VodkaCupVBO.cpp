#include "VodkaCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <IL/il.h>
#define _USE_MATH_DEFINES
#include <math.h>


VodkaCupVBO::VodkaCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura) : Primitivas(id_textura)
{
	alt = argAlt;
	vertex = argVertex;
	layer = argLayers;
	id_textura = argId_textura;

	cylinder = new CylinderVBO(alt/9 -alt/200, alt/40, vertex, layer, id_textura);
}


void VodkaCupVBO::drawVodka_top (float altura, float raio, int vertex, int layers){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	float incAngulo = (2*M_PI)/(float)(vertex-1);
    float incAltura = altura/(float)(layers-1) ;
	
	float y = altura/2 ;
	int pos = 0;
	int textura_pos = 0;

	nrIndex = 12*(vertex*layers);
	int arraySize = (6*(vertex*(layers+1)))*sizeof(float);
	int textSize = (5*(vertex*layers+2))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	for(float i = 0; i <= layers ; i++) {
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

			aTexture[textura_pos++] = (float)j/(float)vertex ;
			aTexture[textura_pos++] = ((float)i/(float)layers) ;
			
        }
		y -= incAltura ;
    }

	raio -= (raio/500);
	y = altura/2 ;

	for(float i = 0; i <= layers ; i++) {
        float alpha = 0 ;
        
        for(int j=0; j < vertex; j++) {

	    		aVertex[pos] = raio*sinf(alpha);
				aNormal[pos] = -sinf(alpha);
				pos++;
				aVertex[pos] = y;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = raio*cosf(alpha);
				aNormal[pos] = -cosf(alpha);
				pos++;

			alpha += incAngulo ;

			aTexture[textura_pos++] = (float)j/(float)vertex ;
			aTexture[textura_pos++] = ((float)i/(float)layers) ;
        }
		y -= incAltura ;
    }

	pos=0;

	for(float i = 0; i < layers-1 ; i++) { 
        for(int j=0; j < vertex-1; j++) {			          
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
    }



	for(float i = 0; i < layers-1 ; i++) { 
        for(int j=0; j < vertex-1; j++) {			          
					aIndex[pos] = j+(layers*i) + layers*vertex;
					pos++;
					aIndex[pos] = (j+1)+(layers*(i+1)) + layers*vertex;
					pos++;
					aIndex[pos] = j+(layers*(i+1)) + layers*vertex;
					pos++;


					aIndex[pos] = j+(layers*i) + layers*vertex;
					pos++;
					aIndex[pos] = (j+1)+(layers*i) + layers*vertex;
					pos++;
					aIndex[pos] = (j+1)+(layers*(i+1)) + layers*vertex;
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

void VodkaCupVBO::draw(){
	glPushMatrix();
    glTranslatef(0, (3*alt)/10, 0);
	drawVodka_top((3*alt)/5, alt/9, vertex, layer);

	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glBindTexture(GL_TEXTURE_2D, id_textura) ;
	glDrawElements(GL_TRIANGLES, nrIndex ,GL_UNSIGNED_INT, aIndex);		
	/* Unbind da textura */
	glBindTexture(GL_TEXTURE_2D, 0) ;
    glPopMatrix();


	
	cylinder->draw();
}

