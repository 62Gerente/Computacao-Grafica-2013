#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "ChairVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/plane/PlaneVBO.h"
#include "../paralelepipedo/ParallelepipedVBO.h"
#include <stdio.h>

ChairClassicaOneVBO::ChairClassicaOneVBO(float arg_tamanho, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) {
	
	/* Parametros */
	tamanho = arg_tamanho ;
	n_vertices = arg_n_vertices ;
	textura_pe = arg_textura_pe ;
	textura_assento = arg_textura_assento ;
	textura_encosto = arg_textura_encosto ;	
	
	/* Deriva��es */
	altura_assento = 0.05*tamanho ;
	comprimento_assento = 0.6*tamanho ;
	largura_assento = 0.6*tamanho ;

	altura_pe = 0.4*tamanho ;
	raio_pe = 0.03*tamanho ;	

	altura_encosto = 0.6*tamanho ;	
	largura_encosto = 0.05*tamanho ;
	inclinacao_encosto = 0 ;

	/* Objectos */
	assento = new ParallelepipedVBO(altura_assento, largura_assento, comprimento_assento, n_camadas, textura_assento) ;
	pe = new CylinderVBO(raio_pe, altura_pe, n_vertices, n_camadas, textura_pe) ;
	encosto = new ParallelepipedVBO(largura_encosto, comprimento_assento, altura_encosto, n_camadas, textura_encosto) ;
}

void ChairClassicaOneVBO::draw() {
		
	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;		
	assento->draw();
	glPopMatrix() ;

	/* Desenhar os quatro p�s */		
	/* P� 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;

	/* Desenhar o encosto */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + largura_encosto/2, altura_assento/2 + altura_encosto/2, 0) ;
	glRotatef(90, 0, 0, 1) ;	
	glRotatef(inclinacao_encosto, 0, 0, 1) ;
	encosto->draw();
	glPopMatrix() ;
}

ChairClassicaTwoVBO::ChairClassicaTwoVBO(float arg_tamanho, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) {
	
	/* Parametros */
	tamanho = arg_tamanho ;
	n_vertices = arg_n_vertices ;
	textura_pe = arg_textura_pe ;
	textura_assento = arg_textura_assento ;
	textura_encosto = arg_textura_encosto ;	
	
	/* Vari�veis de assento */
	altura_assento = 0.05*tamanho ;
	comprimento_assento = 0.6*tamanho ;
	largura_assento = 0.6*tamanho ;	
	assento = new ParallelepipedVBO(altura_assento, largura_assento, comprimento_assento, n_camadas, textura_assento) ;
	/* Vari�veis do p� */
	altura_pe = 0.4*tamanho ;
	raio_pe = 0.03*tamanho ;	
	y_barra_pe = -2*(altura_pe/5) - (altura_assento/2) ;
	pe = new CylinderVBO(raio_pe, altura_pe, n_vertices, n_camadas, textura_pe) ;
	barra_pe = new CylinderVBO(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas, textura_pe) ;
	/* Vari�veis do encosto */
	altura_encosto = 0.6*tamanho ;	
	raio_encosto = 0.03*tamanho ;	
	encosto_vertical = new CylinderVBO(raio_encosto, altura_encosto, n_vertices, n_camadas, textura_encosto) ;
	encosto_horizontal = new CylinderVBO(raio_encosto, comprimento_assento - raio_encosto, n_vertices, n_camadas, textura_encosto) ;
	/* Vari�veis das barras do assento */
	altura_barra = altura_pe/5 ;
	comprimento_barra = comprimento_assento - 4*raio_pe ;
	largura_barra = 2*raio_pe ;
	barra_assento = new ParallelepipedVBO(altura_barra, largura_barra, comprimento_barra, n_camadas, textura_pe) ;
}


void ChairClassicaTwoVBO::draw() {

	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;	
	assento->draw();
	glPopMatrix() ;

	/* Desenhar as barras do assento */
	/* Barra entre 1 e 2 */
	glPushMatrix() ;
	glTranslatef(0, -altura_assento/2 - altura_barra/2, largura_assento/2 - raio_pe) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 3 e 4 */
	glPushMatrix() ;
	glTranslatef(0, - altura_assento/2 - altura_barra/2, -largura_assento/2 + raio_pe) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 2 e 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 1 e 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	barra_assento->draw();
	glPopMatrix() ;

	/* Desenhar os quatro p�s */		
	/* P� 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;

	/* Desenhar o encosto */
	/* Prolongamento do p� 4 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	encosto_vertical->draw();
	glPopMatrix() ;
	
	/* Prolongamento do p� 3 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	encosto_vertical->draw();
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
		encosto_horizontal->draw();
		glPopMatrix() ;
		h_barra += inc_h ;
	}

	/* Desenhar as barras entre os p�s */
	/* Barra entre o p� 1 e o p� 4 */
	glPushMatrix() ;		
	glTranslatef(-comprimento_assento/2 + raio_pe, y_barra_pe, 0) ;	
	glRotatef(90, 1, 0, 0) ;	
	barra_pe->draw();
	glPopMatrix();

	/* Barra entre o p� 2 e o p� 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento_assento/2 - raio_pe, y_barra_pe, 0) ;
	glRotatef(90, 1, 0, 0) ;	
	barra_pe->draw();
	glPopMatrix();
}

ChairClassicaThreeVBO::ChairClassicaThreeVBO(float arg_tamanho, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) {
	
	/* Parametros */
	tamanho = arg_tamanho ;
	n_vertices = arg_n_vertices ;
	textura_pe = arg_textura_pe ;
	textura_assento = arg_textura_assento ;
	textura_encosto = arg_textura_encosto ;	
	
	/* Vari�veis de assento */
	altura_assento = 0.05*tamanho ;
	comprimento_assento = 0.6*tamanho ;
	largura_assento = 0.6*tamanho ;	
	assento = new ParallelepipedVBO(altura_assento, largura_assento, comprimento_assento, n_camadas, textura_assento) ;
	/* Vari�veis do p� */
	altura_pe = 0.4*tamanho ;
	raio_pe = 0.03*tamanho ;	
	y_barra_pe = -2*(altura_pe/5) - (altura_assento/2) ;
	pe = new CylinderVBO(raio_pe, altura_pe, n_vertices, n_camadas, textura_pe) ;
	barra_pe = new CylinderVBO(raio_pe, largura_assento-raio_pe, n_vertices, n_camadas, textura_pe) ;
	/* Vari�veis do encosto */
	altura_encosto = 0.6*tamanho ;	
	raio_encosto = 0.03*tamanho ;	
	encosto_vertical = new CylinderVBO(raio_encosto, altura_encosto, n_vertices, n_camadas, textura_encosto) ;
	encosto_horizontal = new CylinderVBO(raio_encosto, comprimento_assento - raio_encosto, n_vertices, n_camadas, textura_encosto) ;
	/* Vari�veis das barras do assento */
	altura_barra = altura_pe/5 ;
	comprimento_barra = comprimento_assento - 4*raio_pe ;
	largura_barra = 2*raio_pe ;
	barra_assento = new ParallelepipedVBO(altura_barra, largura_barra, comprimento_barra, n_camadas, textura_pe) ;
	/* Vari�veis dos bra�os */
	altura_braco = altura_encosto/3 ;
	comprimento_braco = (2*(largura_assento - largura_encosto))/3 ;
	raio_braco = raio_encosto ;	
	CylinderVBO *braco_vertical = new CylinderVBO(raio_braco, altura_braco, n_vertices, n_camadas, textura_assento) ;
	CylinderVBO *braco_horizontal = new CylinderVBO(raio_braco, comprimento_braco, n_vertices, n_camadas, textura_assento) ;	
}


void ChairClassicaThreeVBO::draw() {
		
//	/* Vari�veis de assento */
//	float altura_assento = 0.05*tamanho ;
//	float comprimento_assento = 0.6*tamanho ;
//	float largura_assento = 0.6*tamanho ;	
//
//	/* Vari�veis do p� */
//	float altura_pe = 0.4*tamanho ;
//	float raio_pe = 0.03*tamanho ;	
//	float y_barra_pe = -2*(altura_pe/5) - (altura_assento/2) ;
//
//	/* Vari�veis do encosto */
//	float altura_encosto = 0.6*tamanho ;	
//	float largura_encosto = 0.05*tamanho ;
//	float raio_encosto = 0.03*tamanho ;	
////	float inclinacao_encosto = 0 ;
//
//	/* Vari�veis dos bra�os */
//	float altura_braco = altura_encosto/3 ;
//	float comprimento_braco = (2*(largura_assento - largura_encosto))/3 ;
//	float raio_braco = raio_encosto ;	
//
//	/* Vari�veis das barras do assento */
//	float altura_barra = altura_pe/5 ;
//	float comprimento_barra = comprimento_assento - 4*raio_pe ;
//	float largura_barra = 2*raio_pe ;
//
//	int n_barras = 3 ;

	/* Desenhar o assento da cadeira na origem */	
	glPushMatrix() ;	
	assento->draw();
	glPopMatrix() ;

	/* Desenhar as barras do assento */
	/* Barra entre 1 e 2 */
	glPushMatrix() ;
	glTranslatef(0, -altura_assento/2 - altura_barra/2, largura_assento/2 - raio_pe) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 3 e 4 */
	glPushMatrix() ;
	glTranslatef(0, - altura_assento/2 - altura_barra/2, -largura_assento/2 + raio_pe) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 2 e 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	barra_assento->draw();
	glPopMatrix() ;
	/* Barra entre 1 e 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_pe, - altura_assento/2 - altura_barra/2, 0) ;
	glRotatef(90, 0, 1, 0) ;
	barra_assento->draw();
	glPopMatrix() ;

	/* Desenhar os bra�os da cadeira */
	/* Bra�o entre o p� 1 e o p� 4 */
	/* Bra�o horizontal */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_braco, altura_assento/2 + altura_braco, -largura_assento/2 + largura_encosto + comprimento_braco/2) ;
	glRotatef(90, 1, 0, 0) ;
	braco_horizontal->draw();
	glPopMatrix() ;
	/* Bra�o vertical */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2 + raio_braco, altura_assento/2 + altura_braco/2, -largura_assento/2 + largura_encosto + comprimento_braco -raio_braco) ;	
	braco_vertical->draw();
	glPopMatrix() ;
	
	/* Bra�o entre o p� 2 e o p� 3 */
	/* Bra�o horizontal */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_braco, altura_assento/2 + altura_braco, -largura_assento/2 + largura_encosto + comprimento_braco/2) ;
	glRotatef(90, 1, 0, 0) ;
	braco_horizontal->draw();
	glPopMatrix() ;
	/* Bra�o vertical */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2 - raio_braco, altura_assento/2 + altura_braco/2, -largura_assento/2 + largura_encosto + comprimento_braco -raio_braco) ;	
	braco_vertical->draw();
	glPopMatrix() ;

	/* Desenhar os quatro p�s */		
	/* P� 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 2 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, largura_assento/2-raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 3 */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* P� 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_pe, -altura_assento/2 - altura_pe/2, -largura_assento/2+raio_pe) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;

	/* Desenhar o encosto */
	/* Prolongamento do p� 4 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(-comprimento_assento/2+raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	encosto_vertical->draw();
	glPopMatrix() ;
	
	/* Prolongamento do p� 3 (sentido oposto) */
	glPushMatrix() ;
	glTranslatef(comprimento_assento/2-raio_encosto, altura_assento/2 + altura_encosto/2, -largura_assento/2+raio_encosto) ;
	glRotatef(45, 0, 1, 0) ;	
	encosto_vertical->draw();
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
		encosto_horizontal->draw();
		glPopMatrix() ;
		h_barra += inc_h ;
	}

	/* Desenhar as barras entre os p�s */
	/* Barra entre o p� 1 e o p� 4 */
	glPushMatrix() ;		
	glTranslatef(-comprimento_assento/2 + raio_pe, y_barra_pe, 0) ;	
	glRotatef(90, 1, 0, 0) ;	
	barra_pe->draw();
	glPopMatrix();

	/* Barra entre o p� 2 e o p� 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento_assento/2 - raio_pe, y_barra_pe, 0) ;
	glRotatef(90, 1, 0, 0) ;	
	barra_pe->draw();
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

	/* Desenhar o p� */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe/2 - altura_assento/2, 0);	
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar a base */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe - altura_base/2 - altura_assento/2, 0) ;
	drawCylinder(raio_base, altura_base, n_vertices, n_camadas) ;
	glPopMatrix();

	/* Desenhar o suporte para os p�s */
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