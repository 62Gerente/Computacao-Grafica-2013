#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Maths\Maths.h"

#include "objects\computer\ComputerVBO.h"
#include "objects/paralelepipedo/ParallelepipedVBO.h"
#include "objects\estruturas\FloorVBO.h"
#include "objects\estruturas\WallsVBO.h"
#include "objects\estruturas\CeilingVBO.h"
#include "objects/chair/ChairVBO.h"
#include "objects\balcony\Balcony.h"
#include "objects\packs\Mesa2Cadeiras.h"
#include "objects\packs\Mesa4Cadeiras.h"
#include "objects\packs\Mesa4Esplanada.h"

#include <IL/il.h>
#include <math.h>
#define _USE_MATH_DEFINES

#define ANG2RAD 3.14159265358979323846/360.0 
#define N_TEX 5
#define SENS_RATO 0.01
#define ANG 0.1
#define MOV 0.7

float height = 2.0f;
float x = 0.0f;
float z = 0.0f;

float camX = 0, camY = 0.5, camZ = 0;
float camDir[3]={-2,0,0};
float ang=0;
int startX, startY;

float alpha = 0.0f, beta = 45;

unsigned char *imageData[N_TEX];
unsigned int tex[N_TEX];
unsigned int shadowMapTexture;
unsigned int mFBO;
unsigned int shadowMapSize=4098;

int wHeight;
int wWidth;

MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;

float pos[4] = {0, 2.1, 0, 1};
float sol[4] = {0, 20, 0, 1};
float ambLight=0.4;

unsigned int id_textura=0;
unsigned int textura_terra ;
unsigned int textura_madeira_chao;
unsigned int textura_madeira_moveis;
unsigned int textura_paredes;
unsigned int textura_green_glass;
unsigned int textura_white_glass;
unsigned int textura_alum_pernas;
unsigned int textura_alum_topo;
unsigned int textura_toalha;
unsigned int textura_ecra;
unsigned int textura_pc;
unsigned int textura_couro;
unsigned int textura_beige;

ParallelepipedVBO* prateleira;
ComputerVBO* computer;

FloorVBO* floorv;
WallsVBO* wallsv;
CeilingVBO* ceilingv;
ChairPubVBO *cadeira_pub ;
Balcony* balcony;
Mesa2Cadeiras *mesa2;
Mesa4Cadeiras *mesa4;
Mesa4Esplanada *mesa4e;

int count;
GLuint buffers[2];

void initMatrix(){

	glPushMatrix();
	
	glLoadIdentity();
	gluPerspective(107, 1, 0.1, 20);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	pos[0], pos[1], pos[2],
				pos[0]-1, 1,pos[2]+1,
				0.0f, 1.0f, 0.0f);
	
	glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);
	
	camDir[0]=cos(alpha)*sin(beta);
	camDir[1]=cos(beta);
	camDir[2]=sin(alpha)*sin(beta);

	glLoadIdentity();
	gluPerspective(45,(float)wWidth/wHeight,0.1,20);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
	
	glLoadIdentity();
	gluLookAt(	camX,camY,camZ,
		camX+camDir[0],camY+camDir[1],camZ+camDir[2],
		0.0f, 1.0f, 0.0f);
	glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
	
	glPopMatrix();

}

void changeSize(int w, int h) {

	wHeight=h;
	wWidth=w;
}

void drawScene() {
	
				floorv->draw();
				wallsv->draw();
				ceilingv->draw();

				// Prateleiras

				glPushMatrix();
				glTranslatef(-5.7f,1.3,4.7);
				prateleira->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-4.5f,1.2,4.7);
				prateleira->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-6.9f,1.4,4.7);
				prateleira->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.2f,1.4,3.95);
				glRotatef(90,0,1,0);
				prateleira->draw();
				glPopMatrix();

				//Balcao

				glPushMatrix();
				glTranslatef(-4.5f,0,2.5f);
				balcony->draw();
				glPopMatrix();

				//PC

				glPushMatrix();
				glTranslatef(-2.7f,1.2,2.5f);
				computer->draw();
				glPopMatrix();

				// Cadeiras Balcao


				glPushMatrix();
				glTranslatef(-3.8f,0.9,1.5f);
				glRotatef(-90,0,1,0);
				cadeira_pub->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.3f,0.9,1.5f);
				glRotatef(-90,0,1,0);
				cadeira_pub->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-6.8f,0.9,1.5f);
				glRotatef(-90,0,1,0);
				cadeira_pub->draw();
				glPopMatrix();

				// Mesas Interior

				glPushMatrix();
				glTranslatef(-5.8f,0,-2.9f);
				mesa2->draw2LugaresWine();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.8f,0,-2.9f);
				mesa2->draw2LugaresWisky();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.8f,0,-0.8f);
				mesa4->draw4LugaresWine();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.8f,0,-0.8f);
				mesa4->draw4LugaresShot();
				glPopMatrix();

				// Mesas Esplanada

				glPushMatrix();
				glTranslatef(-5.5f,0,-5.3f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspRectFino();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.7f,0,-5.3f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspRect();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.7f,0,-7.5f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspQuaCocktail();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.5f,0,-7.5f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspQuaFino();
				glPopMatrix();
}

void renderScene(void) {
	initMatrix();
	
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(lightProjectionMatrix);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLoadMatrixf(lightViewMatrix);

	glViewport(0, 0, shadowMapSize, shadowMapSize);

	glCullFace(GL_FRONT);
	
	drawScene();

	glCullFace(GL_BACK);
	
	glBindFramebuffer(GL_FRAMEBUFFER,0);

	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(cameraProjectionMatrix);

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(cameraViewMatrix);

	glViewport(0, 0, wWidth, wHeight);

	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*ambLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*ambLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	
	glLightfv(GL_LIGHT1, GL_POSITION, sol);
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*ambLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*ambLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);

	glEnable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);

	drawScene();
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	static MATRIX4X4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.5f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.5f, 0.0f,
								0.5f, 0.5f, 0.5f, 1.0f);	//bias from [-1, 1] to [0, 1]
	MATRIX4X4 textureMatrix=biasMatrix*lightProjectionMatrix*lightViewMatrix;

	glEnable(GL_TEXTURE1);
	glActiveTexture(GL_TEXTURE1);
	
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
	glEnable(GL_TEXTURE_GEN_S);

	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
	glEnable(GL_TEXTURE_GEN_T);

	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
	glEnable(GL_TEXTURE_GEN_R);

	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
	glEnable(GL_TEXTURE_GEN_Q);

	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glEnable(GL_TEXTURE_2D);
	
	glActiveTexture(GL_TEXTURE0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	drawScene();
	
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE1);
	glDisable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE1);

	glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_GEN_Q);

	glDisable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE1);

	glutSwapBuffers();
	
}



void processMouseButtons(int button, int state, int xx, int yy) 
{
	if(button==GLUT_LEFT_BUTTON){
		startX=xx;
		startY=yy;
	}
	glutPostRedisplay();
}


void processMouseMotion(int xx, int yy)
{

	int deltaX=startX-xx;
	int deltaY=startY-yy;
	startX=xx;
	startY=yy;

	beta-=deltaY*SENS_RATO;
	alpha+=deltaX*SENS_RATO;

	glutPostRedisplay();
}

void carregarTextura (char* nome_ficheiro, unsigned int* textura_id) {
	
	unsigned int t, tw, th;
	unsigned char *texData;
	ilGenImages(1,&t);
	ilBindImage(t);
	ilLoadImage((ILstring)nome_ficheiro);
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);	
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	texData = ilGetData();
	glGenTextures(1,textura_id); // unsigned int texID - variavel global;
	glBindTexture(GL_TEXTURE_2D,*textura_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0,
	GL_RGBA, GL_UNSIGNED_BYTE, texData);
}

void init() {
	carregarTextura("textures/terra.jpg", &textura_terra) ;
	carregarTextura("textures/floor.jpeg", &textura_madeira_chao) ;
	carregarTextura("textures/table.jpg", &textura_madeira_moveis) ;
	carregarTextura("textures/text_wall.jpg", &textura_paredes);
	carregarTextura("textures/green_glass.jpg", &textura_green_glass);
	carregarTextura("textures/white_glass.jpg", &textura_white_glass);
	carregarTextura("textures/alumin.jpg", &textura_alum_pernas);
	carregarTextura("textures/metal_mesa.jpg", &textura_alum_topo);
	carregarTextura("textures/toalha2.jpg", &textura_toalha);
	carregarTextura("textures/plastic_wht.jpg", &textura_pc);
	carregarTextura("textures/text_pc.jpg", &textura_ecra);
	carregarTextura("textures/couro.jpg", &textura_couro);
	carregarTextura("textures/beige.jpg", &textura_beige);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	balcony = new Balcony(textura_madeira_chao,textura_alum_topo);;
	prateleira = new ParallelepipedVBO(0.1,0.5,1,10,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo);
	computer = new ComputerVBO(0.7,20,30,textura_ecra,textura_pc,textura_pc,textura_pc);
	floorv = new FloorVBO(1,textura_madeira_chao);
	wallsv = new WallsVBO(1,textura_paredes);
	ceilingv = new CeilingVBO(1,0);
	cadeira_pub = new ChairPubVBO(1.1, 20, 15, textura_alum_pernas,textura_alum_pernas, textura_alum_pernas, textura_couro) ;
	mesa2 = new Mesa2Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4 = new Mesa4Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4e = new Mesa4Esplanada(textura_alum_pernas,id_textura,textura_green_glass,textura_alum_topo);

	glGenTextures(1, &shadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_ALPHA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glGenFramebuffers(1,&mFBO);
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, mFBO);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMapTexture, 0);

	glDrawBuffer(GL_NONE);

	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_NORMALIZE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,0);
}

void teclado(unsigned char key, int x, int y){

	switch(key){

	case 'a': 
	case'A':
		alpha-=ANG;
		break;
	case 'd':
	case 'D':
		alpha+=ANG;
		break;
	case 'w':
	case 'W':
		camX+=MOV*camDir[0];
		camY+=MOV*camDir[1];
		camZ+=MOV*camDir[2];
		break;

	case 's':
	case 'S':
		camX-=MOV*camDir[0];
		camY-=MOV*camDir[1];
		camZ-=MOV*camDir[2];
		break;

	}
	glutPostRedisplay();
}


void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(0,0);
	wWidth=350;
	wHeight=350;
	glutInitWindowSize(wWidth,wHeight);
	glutCreateWindow("CG@DI-UM");
		
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	glutKeyboardFunc(teclado);

	glewInit();
	ilInit();
	init();	

	glutMainLoop();
}

