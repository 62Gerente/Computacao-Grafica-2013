#include "Mesa4Cadeiras.h"
#include <GLUT/glut.h>

Mesa4Cadeiras::Mesa4Cadeiras(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr, unsigned int text_mesa){
	cco =  new ChairClassicaOneVBO(1, 10, 10, text_cad, text_cad, text_cad) ;
	winec = new WineCupVBO(0.4,10,10, text_copo);
	vodkac = new VodkaCupVBO(0.3,10,10,text_copo);
	mesa2c = new Mesa2Cadeiras(text_cad,text_copo,text_garr,text_mesa);
	shotc = new ShotCupVBO(0.2,30,30,text_copo);
}

void Mesa4Cadeiras::draw4LugaresWine(){
	mesa2c->draw2LugaresWine();

				//Cadeiras
				glPushMatrix();	
				glTranslatef(-0,0.48f,-0.7f);
				glRotatef(-90,0,1,0);
				cco->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0,0.48f,0.7f);
				glRotatef(-(180+90),0,1,0);
				cco->draw() ;
				glPopMatrix();

				//Copo vinho
				glPushMatrix();	
				glTranslatef(0,0.9,0.4f);
				winec->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0,0.9,-0.4f);
				winec->draw() ;
				glPopMatrix();

}

void Mesa4Cadeiras::draw4LugaresWisky(){}

void Mesa4Cadeiras::draw4LugaresShot(){

		mesa2c->draw2LugaresShot();

				//Cadeiras
				glPushMatrix();	
				glTranslatef(-0,0.48f,-0.7f);
				glRotatef(-90,0,1,0);
				cco->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0,0.48f,0.7f);
				glRotatef(-(180+90),0,1,0);
				cco->draw() ;
				glPopMatrix();

				//Copo vinho
				glPushMatrix();	
				glTranslatef(-0.2,0.9,0.4f);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(-0.4,0.9,-0.5f);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.5,0.9,0.3f);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.3,0.9,-0.4f);
				shotc->draw() ;
				glPopMatrix();

}