#include "BeerCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "../../utils/util.h"

BeerCupVBO::BeerCupVBO(double argAlt,  int argVertex, int argLayers, unsigned int argId_textura) : Primitivas(id_textura)
{
	alt = argAlt;
	vertex = argVertex++;
	layers = argLayers++;
	id_textura = argId_textura;
	rad= alt/6;
	desenha = argVertex*0.60;
	height=alt*2; 
	radius=alt/9;
	altura=alt/6;
	raio= alt/9;
	desenhabase = argVertex*0.5;

	
    drawBeer_top();
	drawBeer_base();
}

void BeerCupVBO::drawBeer_top(){

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

void BeerCupVBO::drawBeer_base(){

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex2 = 6*((vertex+layers)*layers);
	int arraySize = (3*((vertex+layers)*layers))*sizeof(float);
	int textSize = (2*((vertex+layers)*layers))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex2 = (int*) malloc (sizeof(int)*nrIndex2);

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) (layers-1));
    
	float r_inc=raio/((float)(layers-1));
    
	float fr_inc=raio/((float)(vertex-1));
	float alt_dec=altura/((float)(vertex-1));
    
	int pos = 0;
	int textura_pos = 0 ;

	for(int i=0; i<layers;i++){
        
        
		float fr=0.0;
		float alt=altura;
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

	ang = 0.0f;

	for(int i=0; i<layers;i++){
        
		float fr=0.0;
		//float alt=height;
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

				aTexture[textura_pos++] = 1-(sinf(ang)*((r/radius)*0.5) + 0.5) ;
				aTexture[textura_pos++] = cosf(ang)*((r/radius)*0.5) + 0.5 ;
            
		}
		ang+=ang_inc;
	}

	ang=0.0f;
	pos = 0;

	for(int i=0; i<layers-1;i++){

		for(int f=vertex-2; f>desenhabase;f--){
			
					aIndex2[pos] = f+(vertex*i);
					pos++;
					aIndex2[pos] = (f+1)+(vertex*i);
					pos++;
					aIndex2[pos] = (f+1)+(vertex*(i+1));
					pos++;

					aIndex2[pos] = f+(vertex*i);
					pos++;
					aIndex2[pos] = (f+1)+(vertex*(i+1));
					pos++;
					aIndex2[pos] = f+(vertex*(i+1));
					pos++;
            
		}
	}

	int inc = layers*vertex;
	ang = 0.0f;

	for(int i=0; i<layers-1;i++){
		for(int ri=0;ri<layers-1;ri++){

					aIndex2[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex2[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;

					aIndex2[pos] = (ri+1)+(layers*i) +inc;
					pos++;

					aIndex2[pos] = ri+(layers*i) +inc;
					pos++;
					aIndex2[pos] = ri+(layers*(i+1)) +inc;
					pos++;
					aIndex2[pos] = (ri+1)+(layers*(i+1)) +inc;
					pos++;

		}
    }

	glGenBuffers(3, buffers2);
	glBindBuffer(GL_ARRAY_BUFFER,buffers2[0]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, aVertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers2[1]);
	glBufferData(GL_ARRAY_BUFFER, arraySize, aNormal, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,buffers2[2]);
	glBufferData(GL_ARRAY_BUFFER, textSize, aTexture, GL_STATIC_DRAW);

	free(aVertex);
	free(aNormal);
	free(aTexture);

}
	

void BeerCupVBO::draw(void)
{

					float spec[]={0.33333,0.33333,0.33333,1.0} ;

				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE, cinzentoAlphaCopo);				
				glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
				glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);

				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
    glTranslatef(0, alt - alt/3.5, 0);
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

	glPushMatrix();

	glBindBuffer(GL_ARRAY_BUFFER,buffers2[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers2[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers2[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	glBindTexture(GL_TEXTURE_2D, id_textura) ;
	glDrawElements(GL_TRIANGLES, nrIndex ,GL_UNSIGNED_INT, aIndex2);		
	/* Unbind da textura */
	glBindTexture(GL_TEXTURE_2D, 0) ;
	glPopMatrix();

	glDisable(GL_BLEND);	
	reiniciaMaterial();
}
