#include <GLUT/glut.h>
#include "bancoVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

BancoVBO::BancoVBO(double arg_alt, int arg_nlados, int arg_ncamadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento) {

	alt = arg_alt ;
	nlados = arg_nlados ;
	ncamadas = arg_ncamadas ;
	textura_pe = arg_textura_pe ;
	textura_assento = arg_textura_assento ;
}

void BancoVBO::draw(){
	
	CylinderVBO *assento = new CylinderVBO(alt/4, alt/10, nlados, ncamadas, textura_assento);
	CylinderVBO *pe = new CylinderVBO(alt/80, alt/1.5, nlados, ncamadas/3, textura_pe);
	
	glPushMatrix();
	glTranslatef(0, (alt/2), 0);
    assento->draw();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(alt/5,alt/7, 0);
    pe->draw();
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-alt/5,alt/7, 0);
    pe->draw();
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0 ,alt/9, alt/5);
    pe->draw();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0 ,alt/9, -alt/5);
    pe->draw();
    glPopMatrix();
}