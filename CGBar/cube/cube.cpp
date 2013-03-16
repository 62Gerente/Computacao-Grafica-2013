#include <GL/glut.h>
#include <cores.h>
#include "cube.h"

#define FACE_1 1
#define FACE_2 2
#define FACE_3 3
#define FACE_4 4
#define FACE_5 5
#define FACE_6 6

//void drawCube (float dim, int layers) {
//
//	float n = dim/2  ;
//
//	float A[] = {-n, -n, n};
//	float B[] = {n, -n, n};
//	float C[] = {n, -n, -n};
//	float D[] = {-n, -n, -n};
//
//	float E[] = {-n, n, n};
//	float F[] = {n, n, n};
//	float G[] = {n, n, -n};
//	float H[] = {-n, n, -n};
//	
//	glBegin(GL_TRIANGLES);
//		
//		/* base inferior */
//		//glColor3f(AZUL) ;
//		glVertex3fv(A) ;
//		glVertex3fv(C) ;
//		glVertex3fv(B) ;
//
//		//glColor3f(CINZNETO) ;
//		glVertex3fv(A) ;
//		glVertex3fv(D) ;
//		glVertex3fv(C) ;    
//
//		/* base superior */
//		//glColor3f(AZUL) ;
//		glVertex3fv(G) ;
//		glVertex3fv(E) ;
//		glVertex3fv(F) ;
//
//		//glColor3f(CINZNETO) ;
//		glVertex3fv(G) ;
//		glVertex3fv(H) ;
//		glVertex3fv(E) ;    
//
//		/* face lateral +z  */
//		//glColor3f(LARANJA) ;
//		glVertex3fv(F) ;
//		glVertex3fv(A) ;
//		glVertex3fv(B) ;
//
//		//glColor3f(VERMELHO) ;
//		glVertex3fv(F) ;
//		glVertex3fv(E) ;
//		glVertex3fv(A) ;    
//
//		/* face lateral -z  */
//		//glColor3f(LARANJA) ;
//		glVertex3fv(C) ;
//		glVertex3fv(D) ;
//		glVertex3fv(G) ;
//
//		//glColor3f(VERMELHO) ;
//		glVertex3fv(G) ;
//		glVertex3fv(D) ;
//		glVertex3fv(H) ; 
//
//		/* face lateral +x */
//		//glColor3f(BRANCO) ;
//		glVertex3fv(B) ;
//		glVertex3fv(C) ;
//		glVertex3fv(F) ;
//
//		//glColor3f(CASTANHO) ;
//		glVertex3fv(C) ;
//		glVertex3fv(G) ;
//		glVertex3fv(F) ; 
//
//		/* face lateral -x */
//		//glColor3f(BRANCO) ;
//		glVertex3fv(D) ;
//		glVertex3fv(A) ;
//		glVertex3fv(H) ;
//
//		//glColor3f(CASTANHO) ;
//		glVertex3fv(H) ;
//		glVertex3fv(A) ;
//		glVertex3fv(E) ; 
//
//    glEnd();
//}


void drawCube (float dim, int layers)  {

	drawFace(dim, layers, FACE_1) ;
	drawFace(dim, layers, FACE_2) ;
	drawFace(dim, layers, FACE_3) ;
	drawFace(dim, layers, FACE_4) ;
	drawFace(dim, layers, FACE_5) ;
	drawFace(dim, layers, FACE_6) ;
}

void drawFace (float dim, int layers, int face) {

	float dec = dim/(float)layers ;
	float i = dim/2.0, n = dim/2.0 ;
	float decC = dec ;
	float decP = 0 ;	

	for(; i > -dim/2.0f ; i = i-dec) {
		
		float points[4][3] ;
		definePoints(points, n, decC, decP, face) ;
		drawLayer(points, face) ;
		decC += dec ;
		decP += dec ;
	}
}

void definePoints (float p[4][3], float i, float dec, float decP, int face)  {

	
	float	A[] = {-i, i-decP, i},
			B[] = {i, i-decP, i}, 
			C[] = {-i, i-dec, i}, 
			D[] = {i, i-dec, i},
			E[] = {-i, i-decP, -i},
			F[] = {i, i-decP, -i},
			G[] = {-i, i-dec, -i},
			H[] = {i, i-dec, -i} ;	
	
	switch (face) {
	case FACE_1 :	fillPoint(p, A, B, C, D) ; break ;
					
	case FACE_2 :	fillPoint(p, F, E, H, G) ; break ;
	
	case FACE_3 :	fillPoint(p, B, F, D, H) ; break ;

	case FACE_4 :	fillPoint(p, E, A, G, C) ; break ;

	case FACE_5 :	fillPoint(p, A, E, B, F) ; break ;					

	case FACE_6 :	fillPoint(p, G, C, H, D) ; break ;					
	}
}

void fillPoint (float p[4][3], float p1[3], float p2[3], float p3[3], float p4[3]) {
		
	for(int i=0; i < 3; i++) 
		p[0][i] = p1[i] ;
	for(int i=0; i < 3; i++) 
		p[1][i] = p2[i] ;
	for(int i=0; i < 3; i++) 
		p[2][i] = p3[i] ;
	for(int i=0; i < 3; i++) 
		p[3][i] = p4[i] ;
}

void drawLayer (float p[4][3], int face)  {
		
	switch (face) {
	case FACE_1 :	drawTriangle(p[1], p[0], p[2]) ;
					drawTriangle(p[1], p[2], p[3]) ; break ;

	case FACE_2 :	drawTriangle(p[2], p[3], p[0]) ;
					drawTriangle(p[0], p[3], p[1]) ; break ;

	case FACE_3 :	drawTriangle(p[2], p[3], p[0]) ;
					drawTriangle(p[3], p[1], p[0]) ; break ;

	case FACE_4 :	drawTriangle(p[1], p[0], p[2]) ;
					drawTriangle(p[1], p[2], p[3]) ; break ;

	case FACE_5 :	drawTriangle(p[3], p[1], p[0]) ;
					drawTriangle(p[3], p[0], p[2]) ; break ;

	case FACE_6 :	drawTriangle(p[1], p[0], p[2]) ;
					drawTriangle(p[1], p[2], p[3]) ; break ;
	}	
}

void drawTriangle (float p1[3], float p2[3], float p3[3])  {

	glBegin(GL_TRIANGLES) ; 
		glVertex3fv(p1) ;
		glVertex3fv(p2) ;
		glVertex3fv(p3) ;
	glEnd() ;
}