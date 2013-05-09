#include "ConeVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

ConeVBO::ConeVBO(float height, float radius, int vertex, int layers, unsigned int id_textura) : Primitivas(id_textura)
{
	layers++;
	vertex++;

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
		}
		ang+=ang_inc;
	}

	ang = 0.0f;

	for(int i=0; i<layers;i++){
        
		float fr=0.0;
		float alt=height;
		float r=0;

		for(int ri=0;ri<layers;ri++){
			
			r=r_inc*((float)ri);

				aVertex[pos] = r*sinf(ang);
				aNormal[pos] = sinf(ang);
				pos++;
				aVertex[pos] = 0;
				aNormal[pos] = -1;
				pos++;
				aVertex[pos] = r*cosf(ang);
				aNormal[pos] = cosf(ang);
				pos++;
            
		}
		ang+=ang_inc;
	}

	ang=0.0f;
	pos = 0;

	for(int i=0; i<layers-1;i++){

		for(int f=0; f<vertex-1;f++){
			
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

	int inc = layers*vertex;
	ang = 0.0f;

	for(int i=0; i<layers-1;i++){
		for(int ri=0;ri<layers-1;ri++){

					aIndex[pos] = ri+(vertex*i) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(vertex*(i+1)) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(vertex*i) +inc;
					pos++;

					aIndex[pos] = ri+(vertex*i) +inc;
					pos++;
					aIndex[pos] = ri+(vertex*(i+1)) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(vertex*(i+1)) +inc;
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