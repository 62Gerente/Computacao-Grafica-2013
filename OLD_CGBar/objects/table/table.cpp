#include <GLUT/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "table.h"
#include "../../primitives/cylinder/cylinder.h"
#include "../../primitives/plane/plane.h"
#include "../paralelepipedo/paralelepipedo.h"

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da t�bua da mesa;
	float ALTURA: Altura dos p�s da mesa; 
	float RAIO: Raio dos p�s da mesa;	
	int NVERTICES: N�mero de v�rtices usado para desenhar os p�s da mesa (cilindro).
	int NCAMADAS: N�mero de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable(float largura, float comprimento, float altura_tabua, float altura, float raio, int nVertices, int nCamadas) {

	/* Desenhar a t�bua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	drawParalelepipedo(altura_tabua, largura, comprimento, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro p�s */		
	/* P� 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
}

/*	Desenha mesa centrada na origem:
	float LARGURA, COMPRIMENTO, ALTURA_TABUA: Comprimento, largura e altura da t�bua da mesa;
	float ALTURA: Altura dos p�s da mesa; 
	float RAIO: Raio dos p�s da mesa;	
	int NVERTICES: N�mero de v�rtices usado para desenhar os p�s da mesa (cilindro).
	int NCAMADAS: N�mero de camadas usado para as primitivas de cilindro e plano;	
*/
void drawTable2(float largura, float comprimento, float altura_tabua, float altura, float raio, int nVertices, int nCamadas) {

	/* Desenhar a t�bua */	
	glPushMatrix() ;
	glTranslatef(0, altura/2.0, 0);	
	drawParalelepipedo(altura_tabua, largura, comprimento, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar os quatro p�s */		
	/* P� 1 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 2 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, largura/2-raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 3 */
	glPushMatrix() ;
	glTranslatef(comprimento/2-raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;
	/* P� 4 */
	glPushMatrix() ;
	glTranslatef(-comprimento/2+raio, 0, -largura/2+raio) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, altura, nVertices, nCamadas) ;
	glPopMatrix() ;

	/* Desenhar a liga��o entre os p�s */
	/* Liga��o entre o p� 1 e o p� 4 */
	glPushMatrix() ;	
	glTranslatef(-comprimento/2+raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, largura-raio, nVertices, nCamadas) ;
	glPopMatrix();

	/* Liga��o entre o p� 2 e o p� 3 */
	glPushMatrix() ;	
	glTranslatef(comprimento/2-raio, -altura/2+raio, 0) ;
	glRotatef(90, 1, 0, 0) ;
	glRotatef(45, 0, 1, 0) ;
	drawCylinder(raio, largura-raio, nVertices, nCamadas) ;
	glPopMatrix();
}


/*	Desenha mesa redonda, com um s� p�, centrada na origem:
	float RAIO_TABUA, ALTURA_TABUA: Raio e altura do cilindro que representa a t�bua da mesa;
	float RAIO_PE, ALTURA_PE: Raio e altura do p� da mesa (cilindro); 		
	float RAIO_BASE, ALTURA_BASE: Raio e altura do cilindro que representa a base da mesa;
	int N_VERTICES: N�mero de v�rtices usado para desenhar o cilindros.
	int N_CAMADAS: N�mero de camadas usadas para desenhar o cilindro ;	
*/
//void drawTableCircular(float raio_tabua, float altura_tabua, float raio_pe, float altura_pe, float raio_base, float altura_base, int n_vertices, int n_camadas)  {
//
//	/* Desenhar a t�bua */
//	glPushMatrix();
//	glTranslatef(0, altura_pe/2+altura_tabua/2, 0) ;
//	drawCylinder(raio_tabua, altura_tabua, n_vertices, n_camadas) ;
//	glPopMatrix() ;
//
//	/* Desenhar o p� */
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

	/* Desenhar a t�bua */
	glPushMatrix();
	glTranslatef(0, altura_pe/2+altura_tabua/2, 0) ;
	drawCylinder(raio_tabua, altura_tabua, n_vertices, n_camadas) ;
	glPopMatrix() ;

	/* Desenhar o p� */
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