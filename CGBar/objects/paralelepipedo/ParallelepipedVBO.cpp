#include "ParallelepipedVBO.h"

#include <GLUT/glut.h>

ParallelepipedVBO::ParallelepipedVBO(float argHeight, float argWidth, float arglength, int argLayers, unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz){
	height = argHeight;
	width = argWidth;
	length = arglength;
	layers =  argLayers;

	/* Planos y */
	planeposy = new PlaneVBO(length, width, layers, id_texturaposy) ;
	planenegy = new PlaneVBO(length, width, layers, id_texturanegy) ;
	/* Planos z */
	planeposz = new PlaneVBO(length, height, layers, id_texturaposz) ;
	planenegz = new PlaneVBO(length, height, layers, id_texturanegz) ;
	/* Planos x */
	planeposx = new PlaneVBO(height, width, layers, id_texturaposx) ;
	planenegx = new PlaneVBO(height, width, layers, id_texturanegx) ;
}

void ParallelepipedVBO::draw() {

	/* Desenhar o plano y=-height/2 */
	glPushMatrix() ;
	glTranslatef(0, -height/2, 0) ;
	glRotatef(180, 0, 0, 1) ;
	planenegy->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano y=height/2 */
	glPushMatrix() ;
	glTranslatef(0, height/2, 0) ;	
	planeposy->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano z=-width/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, -width/2) ;	
	glRotatef(270, 1, 0, 0) ;
	planenegz->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano z=height/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, width/2) ;	
	glRotatef(90, 1, 0, 0) ;
	planeposz->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano x=length/2 */
	glPushMatrix() ;
	glTranslatef(length/2, 0, 0) ;	
	glRotatef(270, 0, 0, 1) ;
	planenegx->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano x=-length/2 */
	glPushMatrix() ;
	glTranslatef(-length/2, 0, 0) ;	
	glRotatef(90, 0, 0, 1) ;
	planeposx->draw() ;
	glPopMatrix() ;

}