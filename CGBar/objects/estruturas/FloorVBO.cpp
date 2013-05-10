#include "FloorVBO.h"

#include <GLUT/glut.h>

#include "../../primitives/cube/CubeVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

FloorVBO::FloorVBO(double argRatio, unsigned int aId_textura){
	ratio = argRatio;
	id_textura = aId_textura;
}

void FloorVBO::draw(){
	/* Geral */
	CubeVBO* cubeg1 = new CubeVBO(5, 30, id_textura);
	CubeVBO* cubeg2 = new CubeVBO(5, 20, id_textura);
	CylinderVBO* cylinderg3 = new CylinderVBO(5, 0.1, 300, 20, id_textura);
	CubeVBO* cubeg4 = new CubeVBO(5, 20, id_textura);
	CubeVBO* cubeg5 = new CubeVBO(5, 10, id_textura);
	CubeVBO* cubecb = new CubeVBO(5, 10, id_textura);
	CubeVBO* cubep1 = new CubeVBO(5, 30, id_textura);
	CubeVBO* cubep2 = new CubeVBO(5, 30, id_textura);
								

	glPushMatrix();
    glScaled(ratio, ratio, ratio);
    
    glPushMatrix();
    glTranslatef(0, 0, -2.5);
    glScaled(1, 0.02, 3);
	cubeg1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, 0, 7.5 + 0.25);
    glScaled(2, 0.02, 1);
	cubeg2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, -0.005, -5);
	cylinderg3->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    glScaled(1, 0.02, 2);
	cubeg4->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, 0, 2.5);
    glScaled(1, 0.02, 1);
	cubeg5->draw();
    glPopMatrix();
     
    //Casa de Banho
    glPushMatrix();
    glTranslatef(5, 0, -2);
    glScaled(1, 0.02, 0.5);
	cubecb->draw();
    glPopMatrix();
    
    //Passagens
    
    glPushMatrix();
    glTranslatef(2.5+0.125, 0, 2.5);
    glScaled(0.05, 0.02, 0.5);
	cubep1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 5+0.125);
    glScaled(0.5, 0.02, 0.05);
	cubep2->draw();
    glPopMatrix();
    
    glPopMatrix();
}

void FloorVBO::draw(unsigned int id_texturag1,unsigned int id_texturag2,unsigned int id_texturag3,
					unsigned int id_texturag4,unsigned int id_texturag5,unsigned int id_texturacb,
					unsigned int id_texturap1,unsigned int id_texturap2){
	/* Geral */
	CubeVBO* cubeg1 = new CubeVBO(5, 30, id_texturag1);
	CubeVBO* cubeg2 = new CubeVBO(5, 20, id_texturag2);
	CylinderVBO* cylinderg3 = new CylinderVBO(5, 0.1, 300, 20, id_texturag3);
	CubeVBO* cubeg4 = new CubeVBO(5, 20, id_texturag4);
	CubeVBO* cubeg5 = new CubeVBO(5, 10, id_texturag5);
	CubeVBO* cubecb = new CubeVBO(5, 10, id_texturacb);
	CubeVBO* cubep1 = new CubeVBO(5, 30, id_texturap1);
	CubeVBO* cubep2 = new CubeVBO(5, 30, id_texturap2);
								

	glPushMatrix();
    glScaled(ratio, ratio, ratio);
    
    glPushMatrix();
    glTranslatef(0, 0, -2.5);
    glScaled(1, 0.02, 3);
	cubeg1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, 0, 7.5 + 0.25);
    glScaled(2, 0.02, 1);
	cubeg2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, 0, -5);
	cylinderg3->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    glScaled(1, 0.02, 2);
	cubeg4->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, 0, 2.5);
    glScaled(1, 0.02, 1);
	cubeg5->draw();
    glPopMatrix();
     
    //Casa de Banho
    glPushMatrix();
    glTranslatef(5, 0, -2);
    glScaled(1, 0.02, 0.5);
	cubecb->draw();
    glPopMatrix();
    
    //Passagens
    
    glPushMatrix();
    glTranslatef(2.5+0.125, 0, 2.5);
    glScaled(0.05, 0.02, 0.5);
	cubep1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 5+0.125);
    glScaled(0.5, 0.02, 0.05);
	cubep2->draw();
    glPopMatrix();
    
    glPopMatrix();
}