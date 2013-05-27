#include "Mesa4Esplanada.h"
#include <GLUT/glut.h>

Mesa4Esplanada::Mesa4Esplanada(unsigned int text_cad, unsigned int text_copo, unsigned int text_garr, unsigned int text_mesa){
	tt = new TableTwoVBO(1, 1.8, 0.05, 0.65, 0.05, 20, 10, text_cad, text_mesa);
	cct = new ChairClassicaTwoVBO(1, 10, 10, text_cad, text_cad, text_cad) ;
	to = new TableOneVBO(1.2,1.2,0.05,0.65,0.05,20,10,text_cad,text_mesa);
}

void Mesa4Esplanada::draw4LugaresEspRectFino(){

				glPushMatrix();
				glTranslatef(0,0.42,0);
				tt->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.4f,0.48,-0.5f);
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.4f,0.48,-0.5f);
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.4f,0.48,0.5f);
				glRotatef(180,0,1,0); 
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.4f,0.48,0.5f);
				glRotatef(180,0,1,0);
				cct->draw();
				glPopMatrix();

}

void Mesa4Esplanada::draw4LugaresEspQuaFino(){

				glPushMatrix();
				glTranslatef(0,0.42,0);
				to->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0,0.48,-0.6f);
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.6f,0.48,0);
				glRotatef(-90,0,1,0);
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0,0.48,0.6f);
				glRotatef(180,0,1,0); 
				cct->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.6f,0.48,0);
				glRotatef(90,0,1,0);
				cct->draw();
				glPopMatrix();

}