#include "WineCupVBO.h"
#include <stdlib.h>
#include <glew.h>
#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

double altura, rad;
int vert,lay;
unsigned int id_text ;


WineCupVBO::WineCupVBO(double alt, int vertex, int layers, unsigned int id_textura) : Primitivas(id_textura)

{
	altura = alt;
	vert = vertex;
	lay =layers;
	rad= alt/6;
	desenha = layers+layers*0.25;

	cone = new ConeVBO(altura/20, altura/25, vert, lay, id_textura);
    cylinder = new CylinderVBO(altura/80, altura/2/2, vert, lay, id_textura);
	cylinder1 = new CylinderVBO(altura/9, altura/200, vert, lay, id_textura);
	cone1 = new ConeVBO(altura/20, altura/25, vert, lay, id_textura);
}


void WineCupVBO::drawWineCup_top(double radius, double alt,  int vertex, int layers)
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
    double divV = (2*rad) / desenha;
	float angv, angh;

	int pos = 0;
	int textura_pos = 0;

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

			aTexture[textura_pos++] = 1-((float)j/(float)(vertex+1)) ;
			aTexture[textura_pos++] = (float)i/(float)(layers+1) ;
		}

	}
	for(int i=0; i<=layers;i++){
		angv=divV*i;

		for(int j=0; j<=vertex;j++){
			angh=divH*j;

			aVertex[pos]=radius*sin(angv)*sin(angh);
			aNormal[pos]=-sin(angv)*sin(angh);
			pos++;

			aVertex[pos]=radius*cos(angv);
			aNormal[pos]=-cos(angv);
			pos++;

			aVertex[pos]=radius*sin(angv)*cos(angh);
			aNormal[pos]=-sin(angv)*cos(angh);
			pos++;

			aTexture[textura_pos++] = 1-((float)j/(float)(vertex+1)) ;
			aTexture[textura_pos++] = (float)i/(float)(layers+1) ;
		}

	}


	pos=0;


	for(int i=0; i<layers;i++){

		for(int j=0; j<vertex;j++){
			aIndex[pos]=j+(i*(vertex+1)); 
			pos++;
			aIndex[pos]=j+((i+1)*(vertex+1)); 
			pos++;
			aIndex[pos]=(j+1)+(i*(vertex+1));
			pos++;
			
			
			aIndex[pos]=(j+1)+(i*(vertex+1));
			pos++;
			aIndex[pos]=j+((i+1)*(vertex+1)); 
			pos++;
			aIndex[pos]=(j+1)+((i+1)*(vertex+1)); 
			pos++;
			

		}

	}

	for(int i=0; i<layers;i++){

		for(int j=0; j<vertex;j++){
			aIndex[pos]=j+(i*(vertex+1)) + vertex*layers; 
			pos++;
			aIndex[pos]=j+((i+1)*(vertex+1)) + vertex*layers; 
			pos++;
			aIndex[pos]=(j+1)+(i*(vertex+1)) + vertex*layers;
			pos++;
			
			
			aIndex[pos]=(j+1)+(i*(vertex+1)) + vertex*layers;
			pos++;
			aIndex[pos]=j+((i+1)*(vertex+1)) + vertex*layers; 
			pos++;
			aIndex[pos]=(j+1)+((i+1)*(vertex+1)) + vertex*layers; 
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
void WineCupVBO::draw(){
	glPushMatrix();
    glTranslatef(0, (altura/2)-rad/2, 0);
    glRotatef(180, 1, 0, 0);

	drawWineCup_top(altura/6, altura, vert, lay);
	
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
        glTranslatef(0, altura/2/2+altura/50, 0);
        glRotatef(180,1,0,0);
        cone->draw();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,altura/2/4, 0); 
        cylinder->draw();
        glPopMatrix();
        
		glPushMatrix();
        cylinder1->draw();
        glPopMatrix();
  
        glPushMatrix();
        cone1->draw();
        glPopMatrix();
}

