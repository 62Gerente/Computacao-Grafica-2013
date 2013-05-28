#include "ComputerVBO.h"

#include <GLUT/glut.h>

ComputerVBO::ComputerVBO(float argHeight, int argVertex, int argLayers, unsigned int id_texturae,unsigned int id_texturam,unsigned int id_texturacm,
			  unsigned int id_texturat){
	height = argHeight;
	vertex = argVertex;
	layers = argLayers;

	p1 = new ParallelepipedVBO(height/20, height - height/3, height-height/5,vertex,id_texturam,id_texturam,id_texturae,id_texturam,id_texturam,id_texturam);
	p2 = new ParallelepipedVBO(height/10, height - height/3 + height/7.5, height/15, vertex,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam);
	p3 = new ParallelepipedVBO(height/10, height - height/3 + height/7.5, height/15, vertex,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam);
	p4 = new ParallelepipedVBO(height/10, height/15, height - height/5, vertex,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam);
	p5 = new ParallelepipedVBO(height/10, height/15, height - height/5, vertex,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam,id_texturam);
	p6 = new ParallelepipedVBO(height/5, height/1.1, height -height/10, vertex,id_texturacm,id_texturacm,id_texturacm,id_texturacm,id_texturacm,id_texturacm);
	p7 = new ParallelepipedVBO(height/5 - height/15, height/100, height -height/10 -height/15, vertex,id_texturacm,id_texturacm,id_texturacm,id_texturacm,id_texturacm,id_texturacm);
	p8 = new ParallelepipedVBO(height/5, height/5, height/4, vertex,id_texturat,id_texturat,id_texturat,id_texturat,id_texturat,id_texturat);
	p9 = new PlaneVBO(height/6,height/6, vertex,id_texturat);
}

void ComputerVBO::draw(){	
	/* Ecra */
    glPushMatrix() ;
	glTranslatef(0, height/2 , 0);
    glRotatef(70, 1, 0, 0);
	p1->draw();
	glPopMatrix() ;

    
    /* Moldura */
    glPushMatrix() ;
	glTranslatef((height - height/5)/2, height/2, 0);
    glRotatef(70, 1, 0, 0);
	p2->draw();
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(-(height - height/5)/2, height/2, 0);
    glRotatef(70, 1, 0, 0);
	p3->draw();
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(0, height/7 + height/100, height/8);
    glRotatef(70, 1, 0, 0);
	p4->draw();
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(0,height -height/7 -height/100, -height/8);
    glRotatef(70, 1, 0, 0);
	p5->draw();
	glPopMatrix() ;
    
    /* Caixa de Moedas */
    
    glPushMatrix() ;
	glTranslatef(0,0,-height/10);
	p6->draw();
	glPopMatrix() ;

    glPushMatrix() ;
	glTranslatef(0,0,height/3 + height/40);
	p7->draw();
	glPopMatrix() ;
    
    /*Talao*/
    
    glPushMatrix() ;
	glTranslatef(height/2 + height/6,0,-height/10);
	p8->draw();
	glPopMatrix() ;
    
    glPushMatrix() ;
	glTranslatef(height/2 + height/6, height/6 , -height/10 -height/20);
    glRotatef(70, 1, 0, 0);
	p9->draw();
	glPopMatrix() ;
}

