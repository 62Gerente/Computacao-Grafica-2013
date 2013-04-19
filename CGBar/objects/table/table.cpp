#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "table.h"
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../paralelepipedo/paralelepipedo.h"

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da tábua da mesa;
	float ALTURA: Altura dos pés da mesa; 
	float RAIO: Raio dos pés da mesa;	
	int NVERTICES: Número de vértices usado para desenhar os pés da mesa (cilindro).
	int NCAMADAS: Número de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable(float largura, float comprimento, float altura_tabua, float altura, float raio, int nVertices, int nCamadas) {

	/* Desenhar a tábua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	drawParalelepipedo(altura_tabua, largura, comprimento, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
}

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da tábua da mesa;
	float ALTURA: Altura dos pés da mesa; 
	float RAIO: Raio dos pés da mesa;	
	int NVERTICES: Número de vértices usado para desenhar os pés da mesa (cilindro).
	int NCAMADAS: Número de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable2(float largura, float comprimento, float altura_tabua, float altura, float raio, int nVertices, int nCamadas) {

	/* Desenhar a tábua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	drawParalelepipedo(altura_tabua, largura, comprimento, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro pés */		
	/* Pé 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* Pé 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar a ligação entre os pés */
	/* Ligação entre o pé 1 e o pé 4 */
	glPushMatrix() ;	
	glTranslatef(-comprimento/2+raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, largura-raio, nVertices, nCamadas) ;
	glPopMatrix();

	/* Ligação entre o pé 2 e o pé 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento/2-raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, largura-raio, nVertices, nCamadas) ;
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

void drawTableCircular(float raio_tabua, float altura_pe, int n_vertices, int n_camadas)  {

	float altura_tabua = altura_pe/20 ;
	
	float raio_pe = raio_tabua/50 ;

	float altura_base = altura_tabua/5 ;
	float raio_base = raio_tabua/3 ;

	/* Desenhar a tábua */
	glPushMatrix();
	glTranslatef(0, altura_pe/2+altura_tabua/2, 0) ;
	drawCylinder(raio_tabua, altura_tabua, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o pé */
	glPushMatrix() ;
	glTranslatef(0, 0, 0);
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio_pe, altura_pe, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar a base */
	glPushMatrix() ;
	glTranslatef(0, -altura_pe/2-altura_base/2, 0) ;
	drawCylinder(raio_base, altura_base, n_vertices, n_camadas) ;
	glPopMatrix();
}