#include <GLUT/glut.h>
#include "paralelepipedo.h"
#include "../../primitives/plane/PlaneVBO.h"

void drawParalelepipedo(float altura, float largura, float comprimento, int nCamadas, unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz) {
	/* Planos y */
	PlaneVBO* planeposy = new PlaneVBO(comprimento, largura, nCamadas, id_texturaposy) ;
	PlaneVBO* planenegy = new PlaneVBO(comprimento, largura, nCamadas, id_texturanegy) ;
	/* Planos z */
	PlaneVBO* planeposz = new PlaneVBO(comprimento, altura, nCamadas, id_texturaposz) ;
	PlaneVBO* planenegz = new PlaneVBO(comprimento, altura, nCamadas, id_texturanegz) ;
	/* Planos x */
	PlaneVBO* planeposx = new PlaneVBO(altura, largura, nCamadas, id_texturaposx) ;
	PlaneVBO* planenegx = new PlaneVBO(altura, largura, nCamadas, id_texturanegx) ;

	/* Desenhar o plano y=-altura/2 */
	glPushMatrix() ;
	glTranslatef(0, -altura/2, 0) ;
	glRotatef(180, 0, 0, 1) ;
	planenegy->draw ;
	glPopMatrix() ;

	/* Desenhar o plano y=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, altura/2, 0) ;	
	planeposy->draw ;
	glPopMatrix() ;

	/* Desenhar o plano z=-largura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, -largura/2) ;	
	glRotatef(270, 1, 0, 0) ;
	planenegz->draw ;
	glPopMatrix() ;

	/* Desenhar o plano z=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, largura/2) ;	
	glRotatef(90, 1, 0, 0) ;
	planeposz->draw ;
	glPopMatrix() ;

	/* Desenhar o plano x=comprimento/2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2, 0, 0) ;	
	glRotatef(270, 0, 0, 1) ;
	planenegx->draw ;
	glPopMatrix() ;

	/* Desenhar o plano x=-comprimento/2 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2, 0, 0) ;	
	glRotatef(90, 0, 0, 1) ;
	planeposx->draw ;
	glPopMatrix() ;

}

void drawParalelepipedo(float altura, float largura, float comprimento, int nCamadas, unsigned int id_textura) {
	/* Planos y */
	PlaneVBO* planey = new PlaneVBO(comprimento, largura, nCamadas,id_textura) ;
	/* Planos z */
	PlaneVBO* planez = new PlaneVBO(comprimento, altura, nCamadas,id_textura) ;
	/* Planos x */
	PlaneVBO* planex = new PlaneVBO(altura, largura, nCamadas,id_textura) ;

	/* Desenhar o plano y=-altura/2 */
	glPushMatrix() ;
	glTranslatef(0, -altura/2, 0) ;
	glRotatef(180, 0, 0, 1) ;
	planey->draw ;
	glPopMatrix() ;

	/* Desenhar o plano y=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, altura/2, 0) ;	
	planey->draw ;
	glPopMatrix() ;

	/* Desenhar o plano z=-largura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, -largura/2) ;	
	glRotatef(270, 1, 0, 0) ;
	planez->draw ;
	glPopMatrix() ;

	/* Desenhar o plano z=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, largura/2) ;	
	glRotatef(90, 1, 0, 0) ;
	planez->draw ;
	glPopMatrix() ;

	/* Desenhar o plano x=comprimento/2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2, 0, 0) ;	
	glRotatef(270, 0, 0, 1) ;
	planex->draw ;
	glPopMatrix() ;

	/* Desenhar o plano x=-comprimento/2 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2, 0, 0) ;	
	glRotatef(90, 0, 0, 1) ;
	planex->draw ;
	glPopMatrix() ;

}