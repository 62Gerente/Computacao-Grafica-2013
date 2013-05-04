#include <GLUT/glut.h>
#include "paralelepipedo.h"
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"


void drawParalelepipedo(float altura, float largura, float comprimento, int nCamadas) {

	/* Desenhar o plano y=-altura/2 */
	glPushMatrix() ;
	glTranslatef(0, -altura/2, 0) ;
	glRotatef(180, 0, 0, 1) ;
	drawPlane(comprimento, largura, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar o plano y=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, altura/2, 0) ;	
	drawPlane(comprimento, largura, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar o plano z=-largura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, -largura/2) ;	
	glRotatef(270, 1, 0, 0) ;
	drawPlane(comprimento, altura, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar o plano z=altura/2 */
	glPushMatrix() ;
	glTranslatef(0, 0, largura/2) ;	
	glRotatef(90, 1, 0, 0) ;
	drawPlane(comprimento, altura, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar o plano x=comprimento/2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2, 0, 0) ;	
	glRotatef(270, 0, 0, 1) ;
	drawPlane(altura, largura, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar o plano x=-comprimento/2 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2, 0, 0) ;	
	glRotatef(90, 0, 0, 1) ;
	drawPlane(altura, largura, nCamadas) ;
	glPopMatrix() ;

}