#include "WallsVBO.h"

#include <GLUT/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

WallsVBO::WallsVBO(double argRatio, unsigned int aId_textura){
	ratio = argRatio;
	id_textura = aId_textura;

	double proporcao = 3;
	
	c1 = new CubeVBO(proporcao, 10, id_textura);
	c2 = new CubeVBO(proporcao, 10, id_textura);
	c3 = new CubeVBO(proporcao, 10, id_textura);
	c4 = new CubeVBO(proporcao, 10, id_textura);
	c5 = new CubeVBO(proporcao, 5, id_textura);
	c6 = new CubeVBO(proporcao, 10, id_textura);
	c7 = new CubeVBO(proporcao, 2, id_textura);
	c8 = new CubeVBO(proporcao, 5, id_textura);
	c9 = new CubeVBO(proporcao, 10, id_textura);
	c10 = new CubeVBO(proporcao, 10, id_textura);
	c11 = new CubeVBO(proporcao, 10, id_textura);
	c12 = new CubeVBO(proporcao, 10, id_textura);
	c13 = new CubeVBO(proporcao, 10, id_textura);
	c14 = new CubeVBO(proporcao, 15, id_textura);
	c15 = new CubeVBO(proporcao, 15, id_textura);
	c16 = new CubeVBO(proporcao, 15, id_textura);
	c17 = new CubeVBO(proporcao, 15, id_textura);
	c18 = new CubeVBO(proporcao, 2, id_textura);
	c19 = new CubeVBO(proporcao, 2, id_textura);

	cx1 = new CubeVBO(proporcao, 20, id_textura);
	cx2 = new CubeVBO(proporcao, 15, id_textura);
    cx3 = new CubeVBO(proporcao, 15, id_textura);
	cx4 = new CubeVBO(proporcao, 20, id_textura);
	cx5 = new CubeVBO(proporcao, 20, id_textura);
	cx6 = new CubeVBO(proporcao, 2, id_textura);
	cx7 = new CubeVBO(proporcao, 2, id_textura);
	cx8 = new CubeVBO(proporcao, 5, id_textura);
	cx9 = new CubeVBO(proporcao, 10, id_textura);
	cx10 = new CubeVBO(proporcao, 10, id_textura);
	cx11 = new CubeVBO(proporcao, 5, id_textura);
	cx12 = new CubeVBO(proporcao, 10, id_textura);
	cx13 = new CubeVBO(proporcao, 10, id_textura);
	cx14 = new CubeVBO(proporcao, 5, id_textura);
	cx15 = new CubeVBO(proporcao, 20, id_textura);
	cx16 = new CubeVBO(proporcao, 20, id_textura);
}

void WallsVBO::drawWallsZ(){
	double proporcao = 3;
	double espessura = 0.01*proporcao;
    double altura = 2;

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

    glPushMatrix();
    glScaled(ratio, ratio, ratio);
   
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 0);
    glScaled(espessura, altura/proporcao, 3.3333333);
    cx1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-7.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    cx2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 7.5 + 0.25);
    glScaled(espessura, altura/proporcao, 3.333333/2);
	cx3->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.75, altura/2, 2.5);
    glScaled(espessura, altura/proporcao, 3.333333/2);
    cx4->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.5, altura/2, -2);
    glScaled(espessura, altura/proporcao, 0.8);
    cx5->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    cx6->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.25, altura/2, 5.125);
    glScaled(espessura, altura/proporcao, 0.05);
    cx7->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    cx8->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    cx9->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    cx10->draw();
    glPopMatrix();

    //
    glPushMatrix();
    glTranslatef(2.75, 7*altura/8, 2.5);
    glScaled(espessura, altura/12, 2/proporcao);
    cx11->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 4.233333);
    glScaled(espessura, altura/3, 1.5/proporcao);
    cx12->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.75, altura/2, 0.766666);
    glScaled(espessura, altura/3, 1.5/proporcao);
    cx13->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, 7*altura/8, -2);
    glScaled(espessura, altura/12, 2/proporcao + 0.25);
    cx14->draw();
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(2.5, altura/2, -0.5);
    glScaled(espessura, altura/3, 1/proporcao);
    cx15->draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2.5, altura/2, -6);
    glScaled(espessura, altura/3, 5.5/proporcao);
    cx16->draw();
    glPopMatrix();
    
    glPopMatrix();
}

void WallsVBO::draw(){
	drawWallsX();
	drawWallsZ();
}