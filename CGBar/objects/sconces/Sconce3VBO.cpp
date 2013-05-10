#include "Sconce3VBO.h"

#include <GLUT/glut.h>

Sconce3VBO::Sconce3VBO(float argHeight, int argVertex, int argLayers, unsigned int argId_textura1, unsigned int argId_textura2){
	height = argHeight;
	vertex = argVertex;
	layers = argLayers;
	id_textura1 = argId_textura1;
	id_textura2 = argId_textura2;

	s1 = new SphereVBO(argHeight/20, argVertex, argLayers,argId_textura1);
	s2 = new SphereVBO(argHeight/26, argVertex, argLayers,argId_textura2);
}

void Sconce3VBO::draw(){
		glPushMatrix();
		glTranslatef(0,height/10,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(height,height,0.06);
		s1->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,height/10- 0.01,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(height,height,0.09);
		s2->draw();
        glPopMatrix();
}