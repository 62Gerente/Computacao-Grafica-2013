#include "CeilingVBO.h"

#include <GLUT/glut.h>

CeilingVBO::CeilingVBO(double argRatio, unsigned int aId_textura){
	ratio = argRatio;
	id_textura = aId_textura;

	c1 = new CubeVBO(5, 10, id_textura);
	c2 = new CubeVBO(5, 10, id_textura);
	c3 = new CubeVBO(5, 10, id_textura);
	c4 = new CubeVBO(5, 5, id_textura);
	c5 = new CubeVBO(5, 2, id_textura);
	c6 = new CubeVBO(5, 2, id_textura);
}

void CeilingVBO::draw(){

	glPushMatrix();
    glScaled(ratio, ratio, ratio);
    double alt = 2;
    glPushMatrix();
    glTranslatef(0, alt + 0.05, 7.5 + 0.25);
    glScaled(1, 0.02, 1);
	c1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, alt + 0.05, 0);
    glScaled(2, 0.02, 2);
    c2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, alt + 0.05, 2.5);
    glScaled(1, 0.02, 1);
    c3->draw();
    glPopMatrix();
    
    //Casa de Banho
    glPushMatrix();
    glTranslatef(5, alt + 0.05, -2);
    glScaled(1, 0.02, 0.5);
    c4->draw();
    glPopMatrix();

    //Passagens
    
    glPushMatrix();
    glTranslatef(2.5+0.125, alt + 0.05, 2.5);
    glScaled(0.05, 0.02, 0.5);
    c5->draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, alt + 0.05, 5+0.125);
    glScaled(0.5, 0.02, 0.05);
    c6->draw();
    glPopMatrix();
    glPopMatrix();
}

void CeilingVBO::draw(unsigned int id_texturag1,unsigned int id_texturag2,unsigned int id_texturag3,
				unsigned int id_texturacb,
			    unsigned int id_texturap1,unsigned int id_texturap2){

	c1 = new CubeVBO(5, 10, id_texturag1);
	c2 = new CubeVBO(5, 40, id_texturag2);
	c3 = new CubeVBO(5, 10, id_texturag3);
	c4 = new CubeVBO(5, 5, id_texturacb);
	c5 = new CubeVBO(5, 2, id_texturap1);
	c6 = new CubeVBO(5, 2, id_texturap2);

	glPushMatrix();
    glScaled(ratio, ratio, ratio);
    double alt = 2;
    glPushMatrix();
    glTranslatef(0, alt + 0.05, 7.5 + 0.25);
    glScaled(1, 0.02, 1);
	c1->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5, alt + 0.05, 0);
    glScaled(2, 0.02, 2);
    c2->draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5 + 0.25, alt + 0.05, 2.5);
    glScaled(1, 0.02, 1);
    c3->draw();
    glPopMatrix();
    
    //Casa de Banho
    glPushMatrix();
    glTranslatef(5, alt + 0.05, -2);
    glScaled(1, 0.02, 0.5);
    c4->draw();
    glPopMatrix();

    //Passagens
    
    glPushMatrix();
    glTranslatef(2.5+0.125, alt + 0.05, 2.5);
    glScaled(0.05, 0.02, 0.5);
    c5->draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, alt + 0.05, 5+0.125);
    glScaled(0.5, 0.02, 0.05);
    c6->draw();
    glPopMatrix();
    glPopMatrix();

}