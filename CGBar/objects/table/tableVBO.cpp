#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "TableVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/plane/PlaneVBO.h"
#include "../paralelepipedo/ParallelepipedVBO.h"

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da tábua da mesa;
	float ALTURA: Altura dos pés da mesa; 
	float RAIO: Raio dos pés da mesa;	
	int NVERTICES: Número de vértices usado para desenhar os pés da mesa (cilindro).
	int NCAMADAS: Número de camadas usado para as primitivas de cilindro e plano;	
*/

TableOneVBO::TableOneVBO(float arg_largura_tabua, float arg_comprimento_tabua, float arg_altura_tabua, float arg_altura_pes, float arg_raio_pes, int arg_n_vertices_pes, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua) {

	largura = arg_largura_tabua ; 
	comprimento = arg_comprimento_tabua ; 
	altura_tabua = arg_altura_tabua ;
	altura = arg_altura_pes ;
	raio = arg_raio_pes ; 
	nVertices = arg_n_vertices_pes ; 
	nCamadas = arg_n_camadas ;
	textura_pe = arg_textura_pe ; 
	textura_tabua = arg_textura_tabua ;
	tabua = new ParallelepipedVBO(altura_tabua, largura, comprimento, nCamadas, textura_tabua, textura_tabua, textura_tabua, textura_tabua, textura_tabua, textura_tabua) ;
	pe = new CylinderVBO(raio, altura, nVertices, nCamadas, textura_pe) ;
}
void TableOneVBO::draw() {

	/* Desenhar a tábua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	tabua->draw();
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw();
	glPopMatrix() ;
}

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da tábua da mesa;
	float ALTURA: Altura dos pés da mesa; 
	float RAIO: Raio dos pés da mesa;	
	int NVERTICES: Número de vértices usado para desenhar os pés da mesa (cilindro).
	int NCAMADAS: Número de camadas usado para as primitivas de cilindro e plano;	
*/

TableTwoVBO::TableTwoVBO(float arg_largura_tabua, float arg_comprimento_tabua, float arg_altura_tabua, float arg_altura_pes, float arg_raio_pes, int arg_n_vertices_pes, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua) {

	largura = arg_largura_tabua ; 
	comprimento = arg_comprimento_tabua ; 
	altura_tabua = arg_altura_tabua ;
	altura = arg_altura_pes ;
	raio = arg_raio_pes ; 
	nVertices = arg_n_vertices_pes ; 
	nCamadas = arg_n_camadas ;
	textura_pe = arg_textura_pe ; 
	textura_tabua = arg_textura_tabua ;
	tabua = new ParallelepipedVBO(altura_tabua, largura, comprimento, nCamadas, textura_tabua, textura_tabua, textura_tabua, textura_tabua, textura_tabua, textura_tabua) ;
	pe = new CylinderVBO(raio, altura, nVertices, nCamadas, textura_pe) ;
	ligacao_pe = new CylinderVBO(raio, largura-raio, nVertices, nCamadas, textura_pe) ;
}
void TableTwoVBO::draw() {

	/* Desenhar a tábua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	tabua->draw();
	glPopMatrix() ;
	
	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw() ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw() ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw() ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	pe->draw() ;
	glPopMatrix() ;

	/* Desenhar a ligação entre os pés */
	/* Ligação entre o pé 1 e o pé 4 */
	glPushMatrix() ;	
	glTranslatef(-comprimento/2+raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	ligacao_pe->draw() ;
	glPopMatrix();

	/* Ligação entre o pé 2 e o pé 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento/2-raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	ligacao_pe->draw() ;
	glPopMatrix();
}


/*	Desenha mesa redonda, com um só pé, centrada na origem:
	float RAIO_TABUA, ALTURA_TABUA: Raio e altura do cilindro que representa a tábua da mesa;
	float RAIO_PE, ALTURA_PE: Raio e altura do pé da mesa (cilindro); 		
	float RAIO_BASE, ALTURA_BASE: Raio e altura do cilindro que representa a base da mesa;
	int N_VERTICES: Número de vértices usado para desenhar o cilindros.
	int N_CAMADAS: Número de camadas usadas para desenhar o cilindro ;	
*/
//void drawTableCircular(float raio_tabua, float altura_tabua, float raio_pe, float altura_pe, float raio_base, float altura_base, int n_vertices, int n_camadas)  {
//
//	/* Desenhar a tábua */
//	glPushMatrix();
//	glTranslatef(0, altura_pe/2+altura_tabua/2, 0) ;
//	drawCylinder(raio_tabua, altura_tabua, n_vertices, n_camadas) ;
//	glPopMatrix() ;
//
//	/* Desenhar o pé */
//	glPushMatrix() ;
//	glTranslatef(0, 0, 0);
//	glRotatef(45, 0, 1, 0) ;
//	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
//	glPopMatrix() ;
//
//	/* Desenhar a base */
//	glPushMatrix() ;
//	glTranslatef(0, -altura_pe/2-altura_base/2, 0) ;
//	drawCylinder(raio_base, altura_base, n_vertices, n_camadas) ;
//	glPopMatrix();
//}

TableCircularVBO::TableCircularVBO(float arg_raio_tabua, float arg_altura_pe, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua, unsigned int arg_textura_base) {

	/* Argumentos */
	raio_tabua = arg_raio_tabua ;
	altura_pe = arg_altura_pe ;
	n_vertices = arg_n_vertices ;
	n_camadas = arg_n_camadas ;
	textura_pe = arg_textura_pe ;
	textura_tabua = arg_textura_tabua ;
	textura_base = arg_textura_base ;
	/* Derivações */
	altura_tabua = altura_pe/20 ;	
	raio_pe = raio_tabua/50 ;
	altura_base = altura_tabua/5 ;
	raio_base = raio_tabua/3 ;
	/* Objectos */
	tabua = new CylinderVBO(raio_tabua, altura_tabua, n_vertices, n_camadas, textura_tabua) ;
	pe = new CylinderVBO(raio_pe, altura_pe, n_vertices, n_camadas, textura_pe) ;
	base = new CylinderVBO(raio_base, altura_base, n_vertices, n_camadas, textura_base) ;
}


void TableCircularVBO::draw() {

	/*float altura_tabua = altura_pe/20 ;
	
	float raio_pe = raio_tabua/50 ;

	float altura_base = altura_tabua/5 ;
	float raio_base = raio_tabua/3 ;*/

	/* Desenhar a tábua */
	glPushMatrix();
	glTranslatef(0, altura_pe/2+altura_tabua/2, 0) ;
	tabua->draw() ;
	glPopMatrix() ;

	/* Desenhar o pé */
	glPushMatrix() ;
	glTranslatef(0, 0, 0);
	glRotatef(45, 0, 1, 0) ;
	pe->draw() ;
	glPopMatrix() ;

	/* Desenhar a base */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe/2-altura_base/2, 0) ;
	base->draw() ;
	glPopMatrix();
}