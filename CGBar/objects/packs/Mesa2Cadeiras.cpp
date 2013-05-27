#include "Mesa2Cadeiras.h"
#include <GLUT/glut.h>

Mesa2Cadeiras::Mesa2Cadeiras(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr, unsigned int text_mesa){
	cco =  new ChairClassicaOneVBO(1, 10, 10, text_cad, text_cad, text_cad) ;
	wineb = new WineBottleVBO(0.5,10,10, text_garr);
	wiskyb = new WiskyBottleVBO(0.5,10,10,text_garr, text_garr, text_garr, text_garr, text_garr, text_garr);
	mcirc = new TableCircularVBO(0.7, 0.7, 20, 10, text_cad,text_mesa,text_cad) ;
	winec = new WineCupVBO(0.4,10,10, text_copo);
	vodkac = new VodkaCupVBO(0.3,10,10,text_copo);
	shotc = new ShotCupVBO(0.2,30,30,text_copo);
}

void Mesa2Cadeiras::draw2LugaresWine(){
			
				//Cadeiras
				glPushMatrix();	
				glTranslatef(-0.7f,0.48f,0);
				cco->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.7f,0.48f,0);
				glRotatef(180,0,1,0);
				cco->draw() ;
				glPopMatrix();

				//Mesa
				glPushMatrix();	
				glTranslatef(0,0.48f,0);
				mcirc->draw() ;
				glPopMatrix();

				// Grrafa vinho
				glPushMatrix();	
				glTranslatef(0,0.9,0);
				wineb->draw() ;
				glPopMatrix();

				//Copo vinho
				glPushMatrix();	
				glTranslatef(0.4f,0.9,0);
				winec->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(-0.4f,0.9,0);
				winec->draw() ;
				glPopMatrix();

}

void Mesa2Cadeiras::draw2LugaresWisky(){
			
				//Cadeiras
				glPushMatrix();	
				glTranslatef(-0.7f,0.48f,0);
				cco->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.7f,0.48f,0);
				glRotatef(180,0,1,0);
				cco->draw() ;
				glPopMatrix();

				//Mesa
				glPushMatrix();	
				glTranslatef(0,0.48f,0);
				mcirc->draw() ;
				glPopMatrix();

				// Grrafa wisky
				glPushMatrix();	
				glTranslatef(0,0.9,0);
				wiskyb->draw() ;
				glPopMatrix();

				//Copo vodka
				glPushMatrix();	
				glTranslatef(0.4f,0.9,0);
				vodkac->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(-0.4f,0.9,0);
				vodkac->draw() ;
				glPopMatrix();

}

void Mesa2Cadeiras::draw2LugaresShot(){

				//Cadeiras
				glPushMatrix();	
				glTranslatef(-0.7f,0.48f,0);
				cco->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.7f,0.48f,0);
				glRotatef(180,0,1,0);
				cco->draw() ;
				glPopMatrix();

				//Mesa
				glPushMatrix();	
				glTranslatef(0,0.48f,0);
				mcirc->draw() ;
				glPopMatrix();

				// Grrafa wisky
				glPushMatrix();	
				glTranslatef(0,0.9,0);
				wiskyb->draw() ;
				glPopMatrix();

				//Copo shot
				glPushMatrix();	
				glTranslatef(0.4f,0.9,0);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(-0.4f,0.9,0);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(0.4f,0.9,0.2);
				shotc->draw() ;
				glPopMatrix();

				glPushMatrix();	
				glTranslatef(-0.4f,0.9,-0.2);
				shotc->draw() ;
				glPopMatrix();

}