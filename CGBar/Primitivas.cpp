#include "Primitivas.h"

#include <glew.h>
#include <GLUT/glut.h>

Primitivas::Primitivas(unsigned int id_textura_arg) {
	id_textura = id_textura_arg ;
}

void Primitivas::draw(){

	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[1]);
	glNormalPointer(GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	/* Bind da textura */
	glBindTexture(GL_TEXTURE_2D, id_textura) ;
	glDrawElements(GL_TRIANGLES, nrIndex ,GL_UNSIGNED_INT, aIndex);		
	/* Unbind da textura */
	glBindTexture(GL_TEXTURE_2D, 0) ;
}