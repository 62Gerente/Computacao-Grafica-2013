#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "chair.h"
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../paralelepipedo/paralelepipedo.h"
#include <stdio.h>

void drawChairClassica (float tamanho, int n_vertices, int n_camadas) {

	float altura_assento = 0.05*tamanho ;
	float comprimento_assento = 0.6*tamanho ;
	float largura_assento = 0.6*tamanho ;

	float altura_pe = 0.4*tamanho ;
	float raio_pe = 0.03*tamanho ;	

	float altura_encosto = 0.6*tamanho ;	
	float largura_encosto = 0.05*tamanho ;
	float inclinacao_encosto = 0 ;
	
	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;		
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
	glRotatef(inclinacao_encosto, 0, 0, 1) ;
	drawParalelepipedo(largura_encosto, comprimento_assento, altura_encosto, n_camadas) ;
	glPopMatrix() ;
}

void drawChairClassica2 (float tamanho, int n_vertices, int n_camadas) {
		
	/* Variáveis de assento */
	float altura_assento = 0.05*tamanho ;
	float comprimento_assento = 0.6*tamanho ;
	float largura_assento = 0.6*tamanho ;	

	/* Variáveis do pé */
	float altura_pe = 0.4*tamanho ;
	float raio_pe = 0.03*tamanho ;	
	float y_barra_pe = -2*(altura_pe/5) - (altura_assento/2) ;

	/* Variáveis do encosto */
	float altura_encosto = 0.6*tamanho ;	
	float largura_encosto = 0.05*tamanho ;
	float raio_encosto = 0.03*tamanho ;	
	float inclinacao_encosto = 0 ;	

	/* Variáveis dos braços */
	float altura_braco = altura_encosto/3 ;
	float comprimento_braco = (2*(largura_assento - largura_encosto))/3 ;
	float raio_braco = raio_encosto ;	

	/* Variáveis das barras do assento */
	float altura_barra = altura_pe/5 ;
	float comprimento_barra = comprimento_assento - 4*raio_pe ;
	float largura_barra = 2*raio_pe ;

	int n_barras = 3 ;

	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar as barras do assento */
	/* Barra entre 1 e 2 */
	glPushMatrix() ;
	glTranslatef(0, -altura_assento/2 - altura_barra/2, largura_assento/2 - raio_pe) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 3 e 4 */
	glPushMatrix() ;
	glTranslatef(0, - altura_assento/2 - altura_barra/2, -largura_assento/2 + raio_pe) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 2 e 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 1 e 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
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
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Barra entre o pé 2 e o pé 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento_assento/2 - raio_pe, y_barra_pe, 0) ;
	glRotatef(90, 1, 0, 0) ;	
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();
}


void drawChairClassica3 (float tamanho, int n_vertices, int n_camadas) {
		
	/* Variáveis de assento */
	float altura_assento = 0.05*tamanho ;
	float comprimento_assento = 0.6*tamanho ;
	float largura_assento = 0.6*tamanho ;	

	/* Variáveis do pé */
	float altura_pe = 0.4*tamanho ;
	float raio_pe = 0.03*tamanho ;	
	float y_barra_pe = -2*(altura_pe/5) - (altura_assento/2) ;

	/* Variáveis do encosto */
	float altura_encosto = 0.6*tamanho ;	
	float largura_encosto = 0.05*tamanho ;
	float raio_encosto = 0.03*tamanho ;	
	float inclinacao_encosto = 0 ;	

	/* Variáveis dos braços */
	float altura_braco = altura_encosto/3 ;
	float comprimento_braco = (2*(largura_assento - largura_encosto))/3 ;
	float raio_braco = raio_encosto ;	

	/* Variáveis das barras do assento */
	float altura_barra = altura_pe/5 ;
	float comprimento_barra = comprimento_assento - 4*raio_pe ;
	float largura_barra = 2*raio_pe ;

	int n_barras = 3 ;

	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;	
	drawParalelepipedo(altura_assento, largura_assento, comprimento_assento, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar as barras do assento */
	/* Barra entre 1 e 2 */
	glPushMatrix() ;
	glTranslatef(0, -altura_assento/2 - altura_barra/2, largura_assento/2 - raio_pe) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 3 e 4 */
	glPushMatrix() ;
	glTranslatef(0, - altura_assento/2 - altura_barra/2, -largura_assento/2 + raio_pe) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 2 e 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;
	/* Barra entre 1 e 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	drawParalelepipedo(altura_barra, largura_barra, comprimento_barra, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar os braços da cadeira */
	/* Braço entre o pé 1 e o pé 4 */
	/* Braço horizontal */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_braco, altura_assento/2 + altura_braco, -largura_assento/2 + largura_encosto + comprimento_braco/2) ;
	glRotatef(90, 1, 0, 0) ;
	drawCylinder(raio_braco, comprimento_braco, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Braço vertical */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_braco, altura_assento/2 + altura_braco/2, -largura_assento/2 + largura_encosto + comprimento_braco -raio_braco) ;	
	drawCylinder(raio_braco, altura_braco, n_vertices, n_camadas) ;
	glPopMatrix() ;
	
	/* Braço entre o pé 2 e o pé 3 */
	/* Braço horizontal */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_braco, altura_assento/2 + altura_braco, -largura_assento/2 + largura_encosto + comprimento_braco/2) ;
	glRotatef(90, 1, 0, 0) ;
	drawCylinder(raio_braco, comprimento_braco, n_vertices, n_camadas) ;
	glPopMatrix() ;
	/* Braço vertical */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_braco, altura_assento/2 + altura_braco/2, -largura_assento/2 + largura_encosto + comprimento_braco -raio_braco) ;	
	drawCylinder(raio_braco, altura_braco, n_vertices, n_camadas) ;
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
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Barra entre o pé 2 e o pé 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento_assento/2 - raio_pe, y_barra_pe, 0) ;
	glRotatef(90, 1, 0, 0) ;	
	drawCylinder(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas) ;
	glPopMatrix();
}


void drawChairPub(float tamanho, int n_vertices, int n_camadas) {

	float altura_assento = 0.02*tamanho ;
	float comprimento_assento = 0.6*tamanho ;
	float largura_assento = 0.6*tamanho ;	

	float altura_pe = 0.7*tamanho ;
	float raio_pe = 0.03*tamanho ;	

	float altura_encosto = 0.5*tamanho ;	
	float largura_encosto = 0.03*tamanho ;

	float altura_almofada = 0.05*tamanho ;
	float raio_almofada = ((comprimento_assento - largura_encosto)/2) ;
		
	float altura_base = 0.004*tamanho ;
	float raio_base = 0.4*tamanho ;	
	
	float altura_suporte = (altura_pe / 2) ;
	float comprimento_suporte = comprimento_assento - (comprimento_assento/3) ;
	float raio_suporte = 0.4 * raio_pe ;
	float x_suporte = comprimento_assento / 3  ;
	float z_suporte = largura_assento / 3  ;	
	
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
	glTranslatef(largura_encosto/2, altura_almofada/2 + altura_assento/2, 0) ;			
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