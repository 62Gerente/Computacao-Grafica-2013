#include "WallsVBO.h"

#include <GLUT/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/plane/PlaneVBO.h"
#include "../../primitives/cube/CubeVBO.h"

WallsVBO::WallsVBO(double argRatio, unsigned int aId_textura){
	ratio = argRatio;
	id_textura = aId_textura;
}

void WallsVBO::drawWallsZ(){
    double proporcao = 3;
    double espessura = 0.01*proporcao;
    double altura = 2;

	CubeVBO* c1 = new CubeVBO(proporcao, 30, id_textura);
	CubeVBO* c2 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c3 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c4 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c5 = new CubeVBO(proporcao, 5, id_textura);
	CubeVBO* c6 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c7 = new CubeVBO(proporcao, 2, id_textura);
	CubeVBO* c8 = new CubeVBO(proporcao, 5, id_textura);
	CubeVBO* c9 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c10 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c11 = new CubeVBO(proporcao, 30, id_textura);
	CubeVBO* c12 = new CubeVBO(proporcao, 30, id_textura);
	CubeVBO* c13 = new CubeVBO(proporcao, 50, id_textura);
	CubeVBO* c14 = new CubeVBO(proporcao, 15, id_textura);
	CubeVBO* c15 = new CubeVBO(proporcao, 15, id_textura);
	CubeVBO* c16 = new CubeVBO(proporcao, 15, id_textura);
	CubeVBO* c17 = new CubeVBO(proporcao, 15, id_textura);
	CubeVBO* c18 = new CubeVBO(proporcao, 2, id_textura);
	CubeVBO* c19 = new CubeVBO(proporcao, 2, id_textura);

    glPushMatrix();
    glScaled(ratio, ratio, ratio);

    //Sala principal
    //paralelas
    glPushMatrix();
    glTranslatef(-5, altura/2, -4);
    glScaled(5/proporcao, altura/proporcao, espessura);
	c1->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, 5.25);
    glScaled(2/proporcao, altura/12, espessura);
    c2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, 5.25);
    glScaled(1.5/proporcao, altura/3, espessura);
    c3->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.2/3, altura/2, 5.25);
    glScaled(1.5/proporcao, altura/3, espessura);
    c4->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, 5);
    glScaled(2/proporcao, altura/12, espessura);
    c5->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, 5);
    glScaled(1.5/proporcao, altura/3, espessura);
    c6->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5.2/3, altura/2, 5);
    glScaled(1.5/proporcao, altura/3, espessura);
    c7->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(0, 7*altura/8, -4);
    glScaled(2/proporcao, altura/12, espessura);
    c8->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5.2/3, altura/2, -4);
    glScaled(1.5/proporcao, altura/3, espessura);
    c9->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5.2/3, altura/2, -4);
    glScaled(1.5/proporcao, altura/3, espessura);
    c10->draw();
    glPopMatrix();
    
    //Entrada escadas
    //paralelas
    glPushMatrix();
    glTranslatef(-5, altura/2, 5);
    glScaled(5/proporcao, altura/proporcao, espessura);
    c11->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, altura/2, 5.25);
    glScaled(5/proporcao, altura/proporcao, espessura);
	c12->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, altura/2, 10.25);
    glScaled(10/proporcao, altura/proporcao, espessura);
    c13->draw();
    glPopMatrix();
    
    //Entrada    
    //paralelas
    
    glPushMatrix();
    glTranslatef(5 + 0.25, altura/2, 0);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    c14->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, altura/2, 5);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    c15->draw();
    glPopMatrix();
    
    
    //Casa de Banho
    //paralelas
    glPushMatrix();
    glTranslatef(5, altura/2, -0.75);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    c16->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5, altura/2, -3.25);
    glScaled(0.55*proporcao, altura/proporcao, espessura);
    c17->draw();
    glPopMatrix();
    
    
    //Passagens
    glPushMatrix();
    glTranslatef(2.625, altura/2, 1.25);
    glScaled(0.05, altura/proporcao, espessura);
    c18->draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2.625, altura/2, 3.75);
    glScaled(0.05, altura/proporcao, espessura);
    c19->draw();
    glPopMatrix();
    
    glPopMatrix();
}
void WallsVBO::drawWallsX(){
    double proporcao = 3;
    double espessura = 0.01*proporcao;
    double altura = 2;

	CubeVBO* c1 = new CubeVBO(proporcao, 20, id_textura);
	CubeVBO* c2 = new CubeVBO(proporcao, 15, id_textura);
    CubeVBO* c3 = new CubeVBO(proporcao, 15, id_textura);
	CubeVBO* c4 = new CubeVBO(proporcao, 20, id_textura);
	CubeVBO* c5 = new CubeVBO(proporcao, 20, id_textura);
	CubeVBO* c6 = new CubeVBO(proporcao, 2, id_textura);
	CubeVBO* c7 = new CubeVBO(proporcao, 2, id_textura);
	CubeVBO* c8 = new CubeVBO(proporcao, 5, id_textura);
	CubeVBO* c9 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c10 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c11 = new CubeVBO(proporcao, 5, id_textura);
	CubeVBO* c12 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c13 = new CubeVBO(proporcao, 10, id_textura);
	CubeVBO* c14 = new CubeVBO(proporcao, 5, id_textura);
	CubeVBO* c15 = new CubeVBO(proporcao, 20, id_textura);
	 CubeVBO* c16 = new CubeVBO(proporcao, 20, id_textura);

    glPushMatrix();
    glScaled(ratio, ratio, ratio);
   
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 0);
    glScaled(espessura, altura/proporcao, 3.3333333);
    c1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    c2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
	c3->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.75, altura/2, 2.5);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    c4->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.5, altura/2, -2);
    glScaled(espessura, altura/proporcao, 0.8);
    c5->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    c6->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    c7->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    c8->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    c9->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    c10->draw();
    glPopMatrix();

    //
    glPushMatrix();
    glTranslatef(2.75, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    c11->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    c12->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    c13->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, -2);
    glScaled(espessura, altura/12, 2/proporcao + 0.25);
    c14->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, altura/2, -0.5);
    glScaled(espessura, altura/3, 1/proporcao);
    c15->draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, -6);
    glScaled(espessura, altura/3, 5.5/proporcao);
    c16->draw();
    glPopMatrix();
    
    glPopMatrix();
}

void WallsVBO::draw(){
	drawWallsX();
	drawWallsZ();
}