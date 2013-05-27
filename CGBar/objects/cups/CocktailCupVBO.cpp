#include "CocktailCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>



CocktailCupVBO::CocktailCupVBO(double argAlt ,  int argVertex, int argLayers, unsigned int argId_textura) : Primitivas(id_textura)
{
	alt = argAlt;
	vertex = argVertex;
	layers = argLayers;
	rad= alt/6;
	altura=alt/5;
	id_textura = argId_textura;

	cylinder = new CylinderVBO(alt/80, alt/5, vertex, layers/3, id_textura);
    cone = new ConeVBO(alt/20, alt/25, vertex, layers, id_textura);
    cyl = new CylinderVBO(alt/9, alt/200, vertex, layers, id_textura);
}

void CocktailCupVBO::drawCocktailCup_top (){
	layers++;
	vertex++;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	nrIndex = 6*((vertex+vertex)*layers);
	int arraySize = (3*((vertex+vertex)*layers))*sizeof(float);
	int textSize = (2*((vertex+vertex)*layers))*sizeof(float);

	float* aVertex = (float*) malloc(arraySize);
	float* aNormal = (float*) malloc(arraySize);
	float* aTexture = (float*) malloc(textSize);

	aIndex = (int*) malloc (sizeof(int)*nrIndex);

	float ang=0.0f;
	float ang_inc=2*M_PI/((float) (layers-1));
    
	float r_inc=rad/((float)(layers-1));
    
	float fr_inc=rad/((float)(vertex-1));
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

	ang =0;
	textura_pos = 0 ;

	for(int i=0; i<layers;i++){
        
        
		float fr=0.0;
		float alt=altura;
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

	ang=0.0f;
	pos = 0;
	int inc = layers*vertex;

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

	for(int i=0; i<layers-1;i++){

		for(int f=0; f<vertex-1;f++){
			
					aIndex[pos] = f+(vertex*i)+inc;
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1))+inc;
					pos++;
					aIndex[pos] = (f+1)+(vertex*i)+inc;
					pos++;

					aIndex[pos] = f+(vertex*i)+inc;
					pos++;
					aIndex[pos] = f+(vertex*(i+1))+inc;
					pos++;
					aIndex[pos] = (f+1)+(vertex*(i+1))+inc;
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



void CocktailCupVBO::draw(){
    

	glPushMatrix();
    glTranslatef(0, (alt/2)-(2*rad/3), 0);
    glRotatef(180, 1, 0, 0);
	drawCocktailCup_top();

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
    glTranslatef(0,alt/2/4, 0);
	cylinder->draw();
    glPopMatrix();
    
    glPushMatrix();
    cone->draw();
    glPopMatrix();

	glPushMatrix();
	cyl->draw();
    glPopMatrix();
    

}