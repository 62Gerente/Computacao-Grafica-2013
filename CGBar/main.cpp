#include <glew.h>
#include <GLUT/glut.h>
#include <IL/il.h>
#include <math.h>
#include "primitives/plane/PlaneVBO.h"
#include "primitives/cylinder/CylinderVBO.h"
#include "primitives/cube/CubeVBO.h"
#include "primitives/sphere/SphereVBO.h"
#include "primitives/cone/ConeVBO.h"
#include "objects/cups/WineCupVBO.h"
#include "objects/cups/CocktailCupVBO.h"
#include "objects/cups/ShotCupVBO.h"
#include "objects/cups/VodkaCupVBO.h"
#include "objects/cups/BeerCupVBO.h"
#include "objects/bottles/WineBottleVBO.h"
#include "objects/bottles/wiskyBottleVBO.h"
#include "objects/bottles/WiskyBottleVBO.h"
#include "objects/paralelepipedo/ParallelepipedVBO.h"
#include "objects\sconces\Sconce1VBO.h"
#include "objects\sconces\Sconce2VBO.h"
#include "objects\sconces\Sconce3VBO.h"
#include "objects\estruturas\FloorVBO.h"
#include "objects\estruturas\WallsVBO.h"
#include "objects\estruturas\CeilingVBO.h"
#include "objects/table/tableVBO.h"
#include "objects/chair/ChairVBO.h"
#include "objects\balcony\Balcony.h"
#include "objects\packs\Mesa2Cadeiras.h"
#include "objects\packs\Mesa4Cadeiras.h"
#include "objects\packs\Mesa4Esplanada.h"
#include "objects\frame\FrameCoimbra.h"
#include "objects\frame\BigFrame.h"
#include "objects\balcony\Kitchen.h"
#include "objects\fridge\Fridge.h"
#include "objects\oven\Oven.h"
#include "objects\microwave\Microwave.h"
#include "objects\computer\ComputerVBO.h"

#define _USE_MATH_DEFINES

float rotation;
float rotationz;
float px, py, pz;
float camx, camy;
int face, modo;
bool cull;
bool dragging;
int dragx, dragy;
int figura;

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
unsigned int textura_abajur;
unsigned int textura_cao;
unsigned int textura_ultima_ceia;
unsigned int textura_7;
unsigned int textura_frigo;
unsigned int textura_vidro_preto;
unsigned int textura_cand_cozinha;
unsigned int textura_chao_cozinha;
unsigned int textura_chao_cb;
unsigned int textura_chao_casacos;
unsigned int textura_marmore;

PlaneVBO* plane;
CylinderVBO* cylinder;
VodkaCupVBO* vodkaCup;
CubeVBO* cube;
SphereVBO* sphere;
ConeVBO* cone;
WineCupVBO* wineCup;
CocktailCupVBO* cocktailCup;
ShotCupVBO* shotCup;
BeerCupVBO* beerCup;
WineBottleVBO* wineBottle;
WiskyBottleVBO* wiskyBottle;
ParallelepipedVBO* parallelepiped;
ParallelepipedVBO* prateleira;
ComputerVBO* computer;
Sconce1VBO* sconce1;
Sconce2VBO* sconce2;
Sconce3VBO* sconce3;
FloorVBO* floorv;
WallsVBO* wallsv;
CeilingVBO* ceilingv;
ChairClassicaOneVBO *cadeira_um ;
ChairClassicaTwoVBO *cadeira_dois ;
ChairClassicaThreeVBO *cadeira_tres ;
ChairPubVBO *cadeira_pub ;
TableOneVBO *mesa_um ;
TableTwoVBO *mesa_dois ;
TableCircularVBO *mesa_circular ;
Balcony* balcony;
Mesa2Cadeiras *mesa2;
Mesa4Cadeiras *mesa4;
Mesa4Esplanada *mesa4e;
FrameCoimbra* framecao;
BigFrame* framee;
BigFrame* framed;
CocktailCupVBO* cc;
WineCupVBO* wc;
WineBottleVBO* wb; 
VodkaCupVBO* vc;
Sconce1VBO *cand;
Sconce1VBO *cand_cozinha;
Kitchen* kitchen;
Fridge* frigo;
Oven* oven;
Microwave* microwave;


void changeSize(int w, int h) {
    
	if(h == 0)
		h = 1;

	float ratio = w * 1.0 / h;
    
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
    
    glViewport(0, 0, w, h);

	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);
    
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {
	float pos_0[4] = {0,20,0, 1};
	float pos_1[4] = {-4.3f,1.9,-1.85, 1};
	float pos_2[4] = {-4.3f,1.9,2.5, 1};
	float pos_3[4] = {-0.3f,1.9,-1.85, 1};
	float pos_4[4] = {-0.3f,1.9,2.5, 1};
	float pos_5[4] = {-4.3f,1.9,7.5, 1};
	float pos_6[4] = {-0.3f,1.9,7.5, 1};

	GLfloat white[4] = {1., 1., 1., 1.};
	float dif[] = {0.2,0.2,0.2,1};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	glLoadIdentity();
    gluLookAt(20*sin(camx),2*camy,20*cos(camx),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
    
	glLightfv(GL_LIGHT0, GL_POSITION, pos_0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, dif);

	glLightfv(GL_LIGHT1, GL_POSITION, pos_1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	glLightfv(GL_LIGHT2, GL_POSITION, pos_2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white);

	glLightfv(GL_LIGHT3, GL_POSITION, pos_3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT3, GL_SPECULAR, white);

	glLightfv(GL_LIGHT4, GL_POSITION, pos_4);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT4, GL_SPECULAR, white);

	glLightfv(GL_LIGHT5, GL_POSITION, pos_5);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT5, GL_SPECULAR, white);

	glLightfv(GL_LIGHT6, GL_POSITION, pos_6);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT6, GL_SPECULAR, white);

	glEnable(GL_TEXTURE_2D) ;

    glPolygonMode(face, modo);
	if(cull) glEnable(GL_CULL_FACE);
	else glDisable(GL_CULL_FACE);
    
    glTranslatef(px, py, pz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationz, 1.0f,0.0f,0.0f);  

	float cinzento[]={1,1,1};
	float spec[]={0.33333,0.33333,0.33333,1.0};

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cinzento);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);

	switch(figura){
		case 0:
				floorv->draw();
				wallsv->draw();

				//Candeeiros Cozinha

				glPushMatrix();
				glTranslatef(-4.3f,1.70,7.5);
				cand_cozinha->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.3f,1.70,7.5);
				cand_cozinha->draw();
				glPopMatrix();

				//Microondas

				glPushMatrix();
				glTranslatef(-1,1.1,9.85f);
				microwave->draw();
				glPopMatrix();

				//Fogao

				glPushMatrix();
				glTranslatef(-6.66,0,9.8f);
				oven->draw();
				glPopMatrix();

				// Frigorifico

				glPushMatrix();
				glTranslatef(1.75,0,9.85f);
				frigo->draw();
				glPopMatrix();
				
				// Balcao Cozinha

				glPushMatrix();
				glTranslatef(-2.4f,0,9.8f);
				kitchen->draw();
				glPopMatrix();

				// Quadros

				glPushMatrix();
				glTranslatef(2.35,1.1,0.3);
				glRotatef(90,0,1,0);
				glRotatef(180,0,0,1);
				framecao->draw();
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-4,1.1,-3.9);
				glRotatef(180,0,1,0);
				glRotatef(180,0,0,1);
				framee->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.4,1.1,-1);
				glRotatef(-90,0,1,0);
				glRotatef(180,0,0,1);
				framed->draw();
				glPopMatrix();

				//Candeeiros

				glPushMatrix();
				glTranslatef(-4.3f,1.70,-1.85);
				cand->draw();
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-4.3f,1.70,2.5);
				cand->draw();
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-0.3f,1.70,-1.85);
				cand->draw();
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-0.3f,1.70,2.5);
				cand->draw();
				glPopMatrix();

				// Copos Balcao

				glPushMatrix();
				glTranslatef(-3.8f,1.1,2.5f);
				cc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.3f,1.1,2.5f);
				glRotatef(-90,0,1,0);
				vc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-6.8f,1.1,2.5f);
				glRotatef(-90,0,1,0);
				wc->draw();
				glPopMatrix();

				// Garrafas Prateleiras

				glPushMatrix();
				glTranslatef(-6.9f,1.4,4.7);
				wb->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-6.6f,1.4,4.7);
				wb->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.2f,1.4,4.7);
				wb->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.2f,1.4,3.95);
				glRotatef(90,0,1,0);
				wb->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.2f,1.4,4.25);
				glRotatef(90,0,1,0);
				wb->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-7.2f,1.4,3.65);
				glRotatef(90,0,1,0);
				wb->draw();
				glPopMatrix();

				// Copos Prateleiras

				glPushMatrix();
				glTranslatef(-5.7f,1.35,4.7);
				cc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.5f,1.35,4.7);
				cc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.3f,1.35,4.7);
				cc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.9f,1.35,4.7);
				cc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-6.1f,1.35,4.7);
				cc->draw();
				glPopMatrix();


				glPushMatrix();
				glTranslatef(-4.5f,1.25,4.7);
				wc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-4.7f,1.25,4.7);
				wc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-4.9f,1.25,4.7);
				wc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-4.3f,1.25,4.7);
				wc->draw();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-4.1f,1.25,4.7);
				wc->draw();
				glPopMatrix();

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

				break;
		case 1:
				cylinder->draw();
				break;
		case 2:
				plane->draw();
			break;
		case 3:
				cube->draw();
			break;
		case 4:
				sphere->draw();
			break ;
		case 5:
				cone->draw();
			break;

		case 9:
			wineCup->draw();
			break;
		case 10:

			cocktailCup->draw();
			break;
		case 11:

			beerCup->draw();
			break;
		case 12:
				shotCup->draw();
				break;
		case 13:
				vodkaCup->draw();
				break;
		case 14:
				wineBottle->draw();
				break;
		case 15:
				wiskyBottle->draw();
				break;
		case 16:
			cadeira_um->draw() ;
			break;
		case 17:
			cadeira_pub->draw();
			break;
		case 23:
			cadeira_dois->draw();
			break;
		case 24:
			cadeira_tres->draw();
			break;
        case 25:
			mesa_um->draw();
			break;
		case 18:
			mesa_circular->draw();
			break;
		case 19:
			mesa_dois->draw();
			break;
		case 20:
			sconce1->draw();
			break;
		case 21:
			sconce2->draw();
			break;
		case 22:
			sconce3->draw();
			break;
		case 26:
				figura=0;
				break;
		case 27:
				computer->draw();
				break;
		default:
				figura=0;
			break;
			}
   
	glutSwapBuffers();
}

// escrever funcao de processamento do teclado
void kb_special(int key, int x, int y){
	switch(key)
	{
        case GLUT_KEY_LEFT:
		{
			if(px > -5.0f) px -= 0.1f;
			break;
		}
        case GLUT_KEY_RIGHT:
		{
			if(px < 5.0f) px += 0.1f;
			break;
		}
        case GLUT_KEY_DOWN:
		{
			if(pz < 5.0f) pz += 0.1f;
			break;
		}
        case GLUT_KEY_UP:
		{
			if(pz > -5.0f) pz -= 0.1f;
			break;
		}
            
        default: return;
	}
	glutPostRedisplay();
}

void kb_normal(unsigned char key, int x, int y){
    switch (key) {
        case 'a':
		{
			rotation -= 1.5f;
			break;
		}
        case 'd':
		{
			rotation += 1.5f;
			break;
		}
        case 'w':
		{
			rotationz -= 1.5f;
			break;
		}
        case 's':
		{
			rotationz += 1.5f;
			break;
		}
        case 'i':
		{
			camy += 1.5f;
			break;
		}
        case 'o':
		{
			camy -= 1.5f;
			break;
		}
        case 'k':
		{
			camx += 1.5f;
			break;
		}
        case 'l':
		{
			camx -= 1.5f;
			break;
		}
        case 'n':
		{
			py += 1.5f;
			break;
		}
        case 'm':
		{
			py -= 1.5f;
			break;
		}
        default:
            break;
    }
	glutPostRedisplay();
}

void mouse_click_handler(int botao, int estado, int x, int y)
{
	if(botao == GLUT_LEFT_BUTTON)
	{
		switch(estado)
		{
            case GLUT_DOWN:
			{
				dragging = true;
				dragx = x;
				dragy = y;
				break;
			}
            case GLUT_UP:
			{
				dragging = false;
				break;
			}
		}
		glutPostRedisplay();
	}
}

void mouse_motion_handler(int x, int y)
{
	if(dragging)
	{
		if(dragx != x) camx = camx + 0.1 * ( dragx < x ? -1 : 1 );
        
		if(dragy != y) camy = camy + 0.1 * ( dragy < y ? 1 : -1 );
        
		dragx = x;
		dragy = y;
        
		glutPostRedisplay();
	}
}

// escrever funcao de processamento do menu

void menu_opcoes_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			face = GL_FRONT;
			break;
		}
        case 1:
		{
			face = GL_BACK;
			break;
		}
        case 2:
		{
			face = GL_FRONT_AND_BACK;
			break;
		}
        case 3:
		{
			modo = GL_FILL;
			break;
		}
        case 4:
		{
			modo = GL_LINE;
			break;
		}
        case 5:
		{
			cull = true;
			break;
		}
        case 6:
		{
			cull = false;
			break;
		}
        default: return;
	}
	glutPostRedisplay();
}
void menu_principal_handler(int op)
{
	switch (op)
	{
		case 5:
			//estrutura
			figura = 26 ;
			break;

		default:
		break;
	}
	glutPostRedisplay();
}

void menu_objectos_handler(int op){

	switch (op)
	{
		case 5:
			//estrutura
			figura = 27 ;
			break;

		default:
		break;
	}
	glutPostRedisplay();
}

void menu_figuras_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 1; // Cilindro
			break;
		}
        case 1:
		{
			figura = 2; // Plano
			break;
		}
        case 2:
		{
			figura = 3; // Cubo
			break;
		}
        case 3:
		{
			figura = 4; // Esfera
			break;
		}
        case 4:
		{
			figura = 5; // Cilindro sem camadas
			break;
		}
        default: return;
	}
	glutPostRedisplay();
}
void menu_copos_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 9; // Vinho
			break;
		}
        case 1:
		{
			figura = 10; // Cocktail
			break;
		}
        case 2:
		{
			figura = 11; // Fino
			break;
		}
        case 3:
		{
			figura = 12; // Shot
			break;
		}
        case 4:
        {
            figura = 13; // Bebida Branca
            break;
        }
        default: return;
	}
	glutPostRedisplay();
}


void menu_garrafas_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 14; 
			break;
		}
        case 1:
		{
			figura = 15; 
			break;
		}
        default: return;
	}
	glutPostRedisplay();
}

void menu_cadeiras_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 16; 
			break;
		}
        case 1:
		{
			figura = 17; 
			break;
		}
		case 2:
		{
			figura = 23; 
			break;
		}
        case 3:
		{
			figura = 24; 
			break;
		}
        default: return;
	}
	glutPostRedisplay();
}

void menu_mesas_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 18; 
			break;
		}
        case 1:
		{
			figura = 19; 
			break;
		}
        case 2:{
            figura=25;
            break;
        }
        default: return;
	}
	glutPostRedisplay();
}

void menu_candeeiros_handler(int op)
{
	switch(op)
	{
        case 0:
		{
			figura = 20; 
			break;
		}
        case 1:
		{
			figura = 21; 
			break;
		}
		case 2:
		{
			figura = 22; 
			break;
		}
        case 3:
		{
			figura = 23; 
			break;
		}
        default: return;
	}
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

int main(int argc, char **argv) {
    
    // inicializacao
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,800);
	glutCreateWindow("CG@DI-UM");
    
	px = 0.0f; pz = 0.0f; py = 0.0f;
	rotation = 0.0f;
    rotationz = 0.0f;
    camx = 0;
	camy = 1;
	face = GL_FRONT;
	modo = GL_FILL;
	cull = true;
	dragging = false;
	dragx = 0; dragy = 0;
    figura = 0;
    
    
    
    // registo de funcoes
	glutDisplayFunc(renderScene);
	//glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
    
    // por aqui registo da funcoes do teclado e rato
	glutSpecialFunc(kb_special);
    glutKeyboardFunc(kb_normal);
    glutMouseFunc(mouse_click_handler);
	glutMotionFunc(mouse_motion_handler);
    
    
    
    // por aqui a criacao do menu
    int mopcoes = glutCreateMenu(menu_opcoes_handler);
        glutAddMenuEntry("GL_FRONT", 0);
        glutAddMenuEntry("GL_BACK", 1);
        glutAddMenuEntry("GL_FRONT_AND_BACK", 2);
        glutAddMenuEntry("GL_FILL", 3);
        glutAddMenuEntry("GL_LINE", 4);
        glutAddMenuEntry("Enable Cull Face", 5);
        glutAddMenuEntry("Disable Cull Face", 6);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    int mfiguras = glutCreateMenu(menu_figuras_handler);
        glutAddMenuEntry("CILINDRO", 0);
        glutAddMenuEntry("PLANO", 1);
        glutAddMenuEntry("CUBO", 2);
        glutAddMenuEntry("ESFERA", 3);
        glutAddMenuEntry("CONE", 4);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mcopos = glutCreateMenu(menu_copos_handler);
        glutAddMenuEntry("Copo de Vinho", 0);
        glutAddMenuEntry("Copo de Cocktail", 1);
        glutAddMenuEntry("Copo de Fino", 2);
        glutAddMenuEntry("Copo de Shot", 3);
        glutAddMenuEntry("Codo de Bebida Branca", 4);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mgarrafas = glutCreateMenu(menu_garrafas_handler);
        glutAddMenuEntry("Garrafa de Vinho", 0);
		glutAddMenuEntry("Garrafa de Whisky", 1);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mcadeiras = glutCreateMenu(menu_cadeiras_handler);
        glutAddMenuEntry("Cadeira Classica", 0);
		glutAddMenuEntry("Cadeira de Pub", 1);
		glutAddMenuEntry("Cadeira Classica 2", 2);
		glutAddMenuEntry("Cadeira Classica 3", 3);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mmesas = glutCreateMenu(menu_mesas_handler);
        glutAddMenuEntry("Mesa Circular", 0);
		glutAddMenuEntry("Mesa Rectangular", 1);
        glutAddMenuEntry("Mesa Rectangular 2", 2);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mcandeeiros = glutCreateMenu(menu_candeeiros_handler);
        glutAddMenuEntry("Candeeiro 1", 0);
		glutAddMenuEntry("Candeeiro 2", 1);
		glutAddMenuEntry("Candeeiro 3", 2);
		glutAttachMenu(GLUT_RIGHT_BUTTON);


	int mobjectos=  glutCreateMenu(menu_objectos_handler);
		glutAddSubMenu("Copos", mcopos);
		glutAddSubMenu("Garrafas", mgarrafas);
		glutAddSubMenu("Cadeiras", mcadeiras);
		glutAddSubMenu("Mesas", mmesas);
		glutAddSubMenu("Candeeiros", mcandeeiros);
		glutAddMenuEntry("Computador", 5);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    
    glutCreateMenu(menu_principal_handler);
        glutAddSubMenu("Opcoes", mopcoes);
        glutAddSubMenu("Primitivas", mfiguras);
		glutAddSubMenu("Objectos", mobjectos);
		glutAddMenuEntry("Estrutura", 5);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
	/* Iniciar glew e il */
	glewInit();
	ilInit();

	/* Carregar textura */
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
	carregarTextura("textures/abajur.jpg", &textura_abajur);
	carregarTextura("textures/cao.jpeg", &textura_cao);
	carregarTextura("textures/ultimaceia.jpg", &textura_ultima_ceia);
	carregarTextura("textures/7.jpeg", &textura_7);
	carregarTextura("textures/frigo.jpg", &textura_frigo);
	carregarTextura("textures/cozinha.png", &textura_chao_cozinha);
	carregarTextura("textures/cbanho.jpg", &textura_chao_cb);
	carregarTextura("textures/marmore.jpg", &textura_marmore);
	carregarTextura("textures/vidropreto.jpg", &textura_vidro_preto);

    // alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);

	plane = new PlaneVBO(5.0,7.0,30, id_textura);
	cylinder = new CylinderVBO(5, 5, 20, 10, id_textura);
	cube = new CubeVBO(6.0,5, id_textura);
	sphere = new SphereVBO(6,100,120,id_textura);
	cone = new ConeVBO(5,5.0,50,80,id_textura );

	wineCup = new WineCupVBO(5,20,20, id_textura);
	cocktailCup = new CocktailCupVBO(5,30,30, id_textura);
	shotCup = new ShotCupVBO(5,30,30,id_textura);
	vodkaCup = new VodkaCupVBO(5,30,30,id_textura);
	beerCup = new BeerCupVBO(5,30,30,id_textura);

	wiskyBottle = new WiskyBottleVBO(5,30,30,id_textura, id_textura, id_textura, id_textura, id_textura, id_textura);
	wineBottle = new WineBottleVBO(5,20,20, textura_green_glass);

	parallelepiped = new ParallelepipedVBO(5,7,6,10,textura_madeira_moveis,textura_madeira_moveis,textura_madeira_moveis,textura_madeira_moveis,textura_madeira_moveis,textura_madeira_moveis);
	balcony = new Balcony(textura_madeira_chao,textura_alum_topo);;

	prateleira = new ParallelepipedVBO(0.1,0.5,1,10,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo,textura_alum_topo);


	computer = new ComputerVBO(0.7,20,30,textura_ecra,textura_pc,textura_pc,textura_pc);

	sconce1 = new Sconce1VBO(5,5,20,id_textura,id_textura,id_textura);
	sconce2 = new Sconce2VBO(5,5,20,20,id_textura,0);
	sconce3 = new Sconce3VBO(5,20,20,id_textura,0);

	floorv = new FloorVBO(1,textura_madeira_chao,textura_chao_cb,textura_chao_cozinha);
	wallsv = new WallsVBO(1,textura_paredes);
	ceilingv = new CeilingVBO(1,0);

	mesa_um = new TableOneVBO(2, 1, 0.05, 0.8, 0.05, 30, 10, 0, 0); 	
	mesa_dois = new TableTwoVBO(1, 2, 0.05, 0.8, 0.05, 30, 10, 0, 0);	
	mesa_circular = new TableCircularVBO(5, 7, 20, 10, 0, 0, 0) ;

	cadeira_um = new ChairClassicaOneVBO(5, 20, 15, 0, 0, 0) ;
	cadeira_dois = new ChairClassicaTwoVBO(5, 20, 15, 0, 0, 0) ;
	cadeira_tres = new ChairClassicaThreeVBO(5, 20, 15, 0, 0, 0) ;
	cadeira_pub = new ChairPubVBO(1.1, 20, 15, textura_alum_pernas,textura_alum_pernas, textura_alum_pernas, textura_couro) ;

	//PACKS

	mesa2 = new Mesa2Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4 = new Mesa4Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4e = new Mesa4Esplanada(textura_alum_pernas,id_textura,textura_green_glass,textura_alum_topo);

	cc=new CocktailCupVBO(0.4,30,30, id_textura);
	wc= new WineCupVBO(0.4,10,10, id_textura);
	vc=new VodkaCupVBO(0.3,10,10, id_textura);
	wb=new WineBottleVBO(0.5,10,10, textura_green_glass);
	cand = new Sconce1VBO(1.2,5,20,textura_alum_pernas,textura_alum_pernas,textura_abajur);
	cand_cozinha = new Sconce1VBO(1.2,5,20,textura_alum_pernas,textura_alum_pernas,textura_alum_pernas);

	framecao = new FrameCoimbra(textura_madeira_moveis,textura_cao);
	framee = new BigFrame(textura_madeira_moveis,textura_ultima_ceia);
	framed = new BigFrame(textura_madeira_moveis,textura_7);

	kitchen = new Kitchen(textura_marmore,textura_alum_topo);;

	frigo = new Fridge(textura_frigo);
	oven = new Oven(textura_frigo,textura_vidro_preto,textura_vidro_preto);
	microwave = new Microwave(textura_frigo,textura_vidro_preto,textura_vidro_preto);

    // entrar no ciclo do GLUT
	glutMainLoop();
    
	return 1;

}

