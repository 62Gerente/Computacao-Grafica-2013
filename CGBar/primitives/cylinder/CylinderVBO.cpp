#include "CylinderVBO.h"

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#include <math.h>

CylinderVBO::CylinderVBO(float radius, float height, int vertex, int layers, unsigned int id_textura) : Primitivas(id_textura)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex = 6*(vertex*layers + 2*vertex*layers);
	int arraySize = (3*(vertex*layers+ 2*vertex*layers))*sizeof(float);
	int textSize = (2*(vertex*layers+  2*vertex*layers))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	int pos = 0;
	int textura_pos = 0;

	float incAngle = (2*M_PI)/(float)(vertex-1);
    float incHeight = height/(float)(layers-1);
	
	float y = height/2 ;    

	for(float i = 0; i < layers ; i++) { 
		float alpha = 0 ;

        for(int j=0; j < vertex; j++) {
				aVertex[pos] = radius*sinf(alpha);
				aNormal[pos] = sinf(alpha);
				pos++;
				aVertex[pos] = y;
				aNormal[pos] = 0;
				pos++;
				aVertex[pos] = radius*cosf(alpha);
				aNormal[pos] = cosf(alpha);
				pos++;

				aTexture[textura_pos++] = (float)j/(float)vertex ;
				aTexture[textura_pos++] = ((float)i/(float)layers) ;

			alpha += incAngle ;
        }
		y -= incHeight ;
    }

	float ang = 0.0f;
	float r_inc = radius/((float)(layers-1));
	for(int i=0; i<vertex;i++){
        
		float fr=0.0;
		//float alt=height;
		float r=0;

		for(int ri=0;ri<layers;ri++){
			
			r=r_inc*((float)ri);

				aVertex[pos] = r*sinf(ang);
				aNormal[pos] = sinf(ang);
				pos++;
				aVertex[pos] = -height/2 ;
				aNormal[pos] = -1;
				pos++;
				aVertex[pos] = r*cosf(ang);
				aNormal[pos] = cosf(ang);
				pos++;

				aTexture[textura_pos++] = 1-(sinf(ang)*((r/radius)*0.5) + 0.5) ;
				aTexture[textura_pos++] = cosf(ang)*((r/radius)*0.5) + 0.5 ;
            
		}
		ang+= incAngle;
	}

	ang = 0.0f;
	for(int i=0; i<vertex;i++){
        
		float fr=0.0;
		//float alt=height;
		float r=0;

		for(int ri=0;ri<layers;ri++){
			
			r=r_inc*((float)ri);

				aVertex[pos] = r*sinf(ang);
				aNormal[pos] = sinf(ang);
				pos++;
				aVertex[pos] = height/2 ;
				aNormal[pos] = 1;
				pos++;
				aVertex[pos] = r*cosf(ang);
				aNormal[pos] = cosf(ang);
				pos++;

				aTexture[textura_pos++] = 1-(sinf(ang)*((r/radius)*0.5) + 0.5) ;
				aTexture[textura_pos++] = cosf(ang)*((r/radius)*0.5) + 0.5 ;
            
		}
		ang+= incAngle;
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

	int inc = layers*vertex;
	ang = 0.0f;

	for(int i=0; i<vertex-1;i++){
		for(int ri=0;ri<layers-1;ri++){

					aIndex[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;

					aIndex[pos] = (ri+1)+(layers*i) +inc;
					pos++;

					aIndex[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex[pos] = ri+(layers*(i+1)) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;

		}
    }

	inc = layers*vertex + layers*vertex;
	ang = 0.0f;

	for(int i=0; i<vertex-1;i++){
		for(int ri=0;ri<layers-1;ri++){

					aIndex[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(layers*i) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;

					aIndex[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;
					aIndex[pos] = ri+(layers*(i+1)) +inc;
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