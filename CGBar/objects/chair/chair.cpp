#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "chair.h"
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../paralelepipedo/paralelepipedo.h"
#include <stdio.h>


void drawChairClassica () {

	float altura_assento = 0.1 ;
	float comprimento_assento = 0.6 ;
	float largura_assento = 0.6 ;

	float altura_pe = 0.4 ;
	float raio_pe = 0.01 ;	

	float altura_encosto = 0.6 ;
	float comprimento_encosto = 0.1 ;
	float largura_encosto = 0.1 ;	

	int	n_camadas = 5 ;
	int n_vertices = 20 ;	

	/* Desenhar o assento da cadeira na origem*/	
	glPushMatrix() ;
	//glTranslatef(0, altura_pe/2.0, 0);	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o encosto */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + largura_encosto/2, altura_assento/2 + altura_encosto/2, 0) ;
	glRotatef(90, 0, 0, 1) ;	
	drawParalelepipedo(largura_encosto, comprimento_assento, altura_encosto, n_camadas) ;
	glPopMatrix() ;
}

void drawChairClassicaBarras () {

	float altura_assento = 0.1 ;
	float comprimento_assento = 0.6 ;
	float largura_assento = 0.6 ;

	float altura_pe = 0.4 ;
	float raio_pe = 0.01 ;	

	float altura_encosto = 0.6 ;
	float comprimento_encosto = 0.1 ;
	float largura_enconsto = 0.1 ;
	float raio_encosto = 0.03 ;
	
	int n_barras = 3 ;

	int	n_camadas = 5 ;
	int n_vertices = 20 ;	

	/* Desenhar o assento da cadeira na origem*/	
	glPushMatrix() ;
	//glTranslatef(0, altura_pe/2.0, 0);	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o encosto */
	/* Prolongamento do pé 4 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	drawCylinder(raio_encosto, altura_encosto, n_vertices, n_camadas) ;
	glPopMatrix() ;
	
	/* Prolongamento do pé 3 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	drawCylinder(raio_encosto, altura_encosto, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar as barras do encosto */
	int i ;
	float h_barra, inc_h ;
	h_barra = altura_assento/2 + (altura_encosto / n_barras) ; 
	inc_h = altura_encosto / n_barras ;
	for(i = 0 ; i < n_barras ; i++) {
		glPushMatrix() ;
		glTranslatef(0, h_barra - raio_encosto, -largura_assento/2 + raio_encosto) ;		
		glRotatef(90, 0, 0, 1) ;
		glRotatef(45, 0, 1, 0) ;	
		drawCylinder(raio_encosto, comprimento_assento - raio_encosto, n_vertices, n_camadas) ;
		glPopMatrix() ;
		h_barra += inc_h ;
	}
}

void drawChair2 () {

	float altura_assento = 0.1 ;
	float comprimento_assento = 0.6 ;
	float largura_assento = 0.6 ;

	float altura_pe = 0.4 ;
	float raio_pe = 0.01 ;
	float y_barra_pe = -(0.75 * altura_pe) - (altura_assento/2) ;

	float altura_encosto = 0.6 ;
	float comprimento_encosto = 0.1 ;
	float largura_enconsto = 0.1 ;
	float raio_encosto = 0.03 ;	
	
	int n_barras = 3 ;

	int	n_camadas = 5 ;
	int n_vertices = 20 ;	

	/* Desenhar o assento da cadeira na origem*/	
	glPushMatrix() ;
	//glTranslatef(0, altura_pe/2.0, 0);	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o encosto */
	/* Prolongamento do pé 4 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	drawCylinder(raio_encosto, altura_encosto, n_vertices, n_camadas) ;
	glPopMatrix() ;
	
	/* Prolongamento do pé 3 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	drawCylinder(raio_encosto, altura_encosto, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar as barras do encosto */
	int i ;
	float h_barra, inc_h ;
	h_barra = altura_assento/2 + (altura_encosto / n_barras) ; 
	inc_h = altura_encosto / n_barras ;
	for(i = 0 ; i < n_barras ; i++) {
		glPushMatrix() ;
		glTranslatef(0, h_barra - raio_encosto, -largura_assento/2 + raio_encosto) ;		
		glRotatef(90, 0, 0, 1) ;
		glRotatef(45, 0, 1, 0) ;	
		drawCylinder(raio_encosto, comprimento_assento - raio_encosto, n_vertices, n_camadas) ;
		glPopMatrix() ;
		h_barra += inc_h ;
	}

	/* Desenhar as barras entre os pés */
	/* Barra entre o pé 1 e o pé 4 */
	glPushMatrix() ;		
	glTranslatef(-comprimento_assento/2 + raio_pe, y_barra_pe, 0) ;	
	glRotatef(90, 1, 0, 0) ;
	//glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Barra entre o pé 2 e o pé 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento_assento/2 - raio_pe, y_barra_pe, 0) ;
	glRotatef(90, 1, 0, 0) ;
	//glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Ligação entre as barras dos pés */
	glPushMatrix() ;	
	glTranslatef(0, y_barra_pe, 0) ;
	glRotatef(90, 0, 0, 1) ;
	//glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, comprimento_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();
}

void drawChairPub() {

	float altura_assento = 0.1 ;
	float comprimento_assento = 0.6 ;
	float largura_assento = 0.6 ;

	float altura_almofada = 0.15 ;
	float raio_almofada = 0.2 ;

	float altura_pe = 0.7 ;
	float raio_pe = 0.01 ;	

	float altura_encosto = 0.5 ;	
	float largura_encosto = 0.03 ;
		
	float altura_base = 0.004 ;
	float raio_base = 0.3 ;	
	
	float altura_suporte = altura_pe / 2 ;
	float comprimento_suporte = comprimento_assento - (comprimento_assento/3) ;
	float raio_suporte = 0.4 * raio_pe ;
	float x_suporte = comprimento_assento / 3  ;
	float z_suporte = largura_assento / 3  ;	

	int	n_camadas = 5 ;
	int n_vertices = 20 ;

	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o encosto */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + largura_encosto/2, altura_assento/2 + altura_encosto/2, 0) ;
	glRotatef(90, 0, 0, 1) ;	
	drawParalelepipedo(largura_encosto, comprimento_assento, altura_encosto, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar a almofada */
	glPushMatrix() ;		
	glTranslatef(0, altura_almofada/2 + altura_assento/2, 0) ;			
	drawCylinder(raio_almofada, altura_almofada, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Desenhar o pé */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe/2 - altura_assento/2, 0);	
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar a base */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe - altura_base/2 - altura_assento/2, 0) ;
	drawCylinder(raio_base, altura_base, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Desenhar o suporte para os pés */
	/* Desenhar o suporte vertical */
	glPushMatrix() ;
	glTranslatef(x_suporte, -altura_suporte/2 - altura_assento/2, z_suporte) ;
	drawCylinder(raio_suporte, altura_suporte, n_vertices, n_camadas) ;
	glPopMatrix();
	/* Desenhar o suporte horizontal*/
	glPushMatrix() ;
	glTranslatef(x_suporte, -altura_suporte - altura_assento/2, z_suporte - comprimento_suporte/2) ;
	glRotatef(90, 1, 0, 0) ;
	drawCylinder(raio_suporte, comprimento_suporte, n_vertices, n_camadas) ;
	glPopMatrix();
}