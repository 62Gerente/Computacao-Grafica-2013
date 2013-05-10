#include "Sconce2VBO.h"

#include <GLUT/glut.h>

Sconce2VBO::Sconce2VBO(float argHeight, float argWidth, int argVertex, int argLayers, unsigned int argId_textura1, unsigned int argId_textura2){
	height = argHeight;
	width = argWidth;
	vertex = argVertex;
	layers = argLayers;
	id_textura1 = argId_textura1;
	id_textura2 = argId_textura2;

	c1 = new CubeVBO(argHeight/6, argLayers,argId_textura1);
	c2 = new CubeVBO(argHeight/8, argLayers,argId_textura2);
}

void Sconce2VBO::draw(){
		glPushMatrix();
		glTranslatef(0,height/10,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(height,width,0.06);
		c1->draw();
        glPopMatrix();

		glPushMatrix();
		glTranslatef(0,height/10- 0.01,0);
		glRotatef(90,1,0,0);
		glRotatef(90,0,0,1);
		glScalef(height,width,0.09);
		c2->draw();
        glPopMatrix();
}
