#include "ParallelepipedVBO.h"

#include <GLUT/glut.h>

#include "../../primitives/plane/PlaneVBO.h"

ParallelepipedVBO::ParallelepipedVBO(float argHeight, float argWidth, float arglength, int argLayers, unsigned int argId_textura){
	height = argHeight;
	width = argWidth;
	length = arglength;
	layers =  argLayers;
	id_textura = argId_textura;
}

void ParallelepipedVBO::draw(unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz) {
	/* Planos y */
	PlaneVBO* planeposy = new PlaneVBO(length, width, layers, id_texturaposy) ;
	PlaneVBO* planenegy = new PlaneVBO(length, width, layers, id_texturanegy) ;
	/* Planos z */
	PlaneVBO* planeposz = new PlaneVBO(length, height, layers, id_texturaposz) ;
	PlaneVBO* planenegz = new PlaneVBO(length, height, layers, id_texturanegz) ;
	/* Planos x */
	PlaneVBO* planeposx = new PlaneVBO(height, width, layers, id_texturaposx) ;
	PlaneVBO* planenegx = new PlaneVBO(height, width, layers, id_texturanegx) ;

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

void ParallelepipedVBO::draw() {
	/* Planos y */
	PlaneVBO* planey = new PlaneVBO(length, width, layers,id_textura) ;
	/* Planos z */
	PlaneVBO* planez = new PlaneVBO(length, height, layers,id_textura) ;
	/* Planos x */
	PlaneVBO* planex = new PlaneVBO(height, width, layers,id_textura) ;

	/* Desenhar o plano y=-height/2 */
	glPushMatrix() ;
	glTranslatef(0, -height/2, 0) ;
	glRotatef(180, 0, 0, 1) ;
	planey->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano y=height/2 */
	glPushMatrix() ;
	glTranslatef(0, height/2, 0) ;	
	planey->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano z=-width/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, -width/2) ;	
	glRotatef(270, 1, 0, 0) ;
	planez->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano z=height/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, width/2) ;	
	glRotatef(90, 1, 0, 0) ;
	planez->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano x=length/2 */
	glPushMatrix() ;
	glTranslatef(length/2, 0, 0) ;	
	glRotatef(270, 0, 0, 1) ;
	planex->draw() ;
	glPopMatrix() ;

	/* Desenhar o plano x=-length/2 */
	glPushMatrix() ;
	glTranslatef(-length/2, 0, 0) ;	
	glRotatef(90, 0, 0, 1) ;
	planex->draw() ;
	glPopMatrix() ;

}