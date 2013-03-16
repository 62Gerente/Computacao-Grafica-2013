#ifndef _CUBE_H_
#define _CUBE_H_

void drawCube (float dim, int layers) ;
void drawFace (float dim, int layers, int face) ;
void definePoints (float p[4][3], float i, float dec, float decP, int face) ;
void fillPoint (float p[4][3], float p1[3], float p2[3], float p3[3], float p4[3]) ;
void drawLayer (float p[4][3], int face) ;
void drawTriangle (float p1[3], float p2[3], float p3[3]) ;
#endif 