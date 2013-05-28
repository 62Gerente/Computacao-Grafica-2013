#include "ShotCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

ShotCupVBO::ShotCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura) : Primitivas(id_textura)
{
	alt = argAlt;
	vertex = argVertex++;
	layers = argLayers++;
	id_textura = argId_textura;
	rad= alt/6;
	desenha = argVertex*0.77;
	height=alt*2; 
	radius=alt/6;

	cylinder = new CylinderVBO(alt/7-alt/200, alt/30, vertex, layers, id_textura);
	
    drawShot_top();
}

void ShotCupVBO::drawShot_top()
{

	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex = 6*((vertex+layers)*layers);
	int arraySize = (3*((vertex+layers)*layers))*sizeof(float);
	int textSize = (2*((vertex+layers)*layers))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) (layers-1));
    
	float r_inc=radius/((float)(layers-1));
    
	float fr_inc=radius/((float)(vertex-1));
	float alt_dec=height/((float)(vertex-1));
    
	int pos = 0;
	int textura_pos = 0 ;

	for(int i=0; i<layers;i++){
        
        
		float fr=0.0;
		float alt=height;
		for(int f=0; f<vertex;f++){
            
			fr=fr_inc*((float)f);
			alt=alt_dec*((float)((vertex-1)-f));
			
				aVertex[pos] = fr*sinf(ang);
				aNormal[pos] = sinf(ang);
				pos++;
				aVertex[pos] = alt;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = fr*cosf(ang);
				aNormal[pos] = cosf(ang);
				pos++;

			aTexture[textura_pos++] = (float)i/(float)layers ;
			aTexture[textura_pos++] = (float)f/(float)vertex ;
			
		}
		ang+=ang_inc;
	}


	ang=0.0f;
	for(int i=0; i<layers;i++){
        
        
		float fr=0.0;
		float alt=height;
		for(int f=0; f<vertex;f++){
            
			fr=fr_inc*((float)f);
			alt=alt_dec*((float)((vertex-1)-f));
			
				aVertex[pos] = fr*sinf(ang);
				aNormal[pos] = -sinf(ang);
				pos++;
				aVertex[pos] = alt;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = fr*cosf(ang);
				aNormal[pos] = -cosf(ang);
				pos++;

			aTexture[textura_pos++] = (float)i/(float)layers ;
			aTexture[textura_pos++] = (float)f/(float)vertex ;
			
		}
		ang+=ang_inc;
	}


	pos = 0;

	for(int i=0; i<layers-1;i++){

		for(int f=vertex-2; f>desenha;f--){
			
					aIndex[pos] = f+(vertex*i);
					pos++;
					aIndex[pos] = (f+1)+(vertex*i);
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1));
					pos++;

					aIndex[pos] = f+(vertex*i);
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1));
					pos++;
					aIndex[pos] = f+(vertex*(i+1));
					pos++;
            
		}
	}

	for(int i=0; i<layers-1;i++){

		for(int f=vertex-2; f>desenha;f--){
			
					aIndex[pos] = f+(vertex*i) + layers*vertex;
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1)) + layers*vertex;
					pos++;
					aIndex[pos] = (f+1)+(vertex*i) + layers*vertex;
					pos++;


					aIndex[pos] = f+(vertex*i) + layers*vertex;
					pos++;
					aIndex[pos] = f+(vertex*(i+1)) + layers*vertex;
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1)) + layers*vertex;
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


void ShotCupVBO::draw(){

	glPushMatrix();
    glTranslatef(0, alt/2-alt/5, 0);
    glRotatef(180, 1, 0, 0);

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


