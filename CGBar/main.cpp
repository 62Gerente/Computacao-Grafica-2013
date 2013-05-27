#include <glew.h>
#include <GLUT/glut.h>
#include <IL/il.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "primitives/cylinder/cylinder.h"
#include "primitives/plane/plane.h"
#include "primitives/cube/cube.h"
#include "primitives/sphere/sphere.h"
#include "objects/cups/wineCup.h"
#include "objects/cups/cocktailCup.h"
#include "primitives/cone/cone.h"
#include "objects/cups/beerCup.h"
#include "objects/cups/shotCup.h"
#include "objects/cups/vodkaCup.h"
#include "objects/sconces/treeSconce.h"
#include "objects/bancos/banco.h"
#include "objects/bottles/wineBottle.h"
#include "objects/bottles/wiskyBottle.h"
#include "objects/sconces/sconce1.h"
#include "objects/sconces/sconce2.h"
#include "objects/sconces/sconce3.h"
#include "objects/table/table.h"
#include "objects/computer/computer.h"
#include "objects/chair/chair.h"
#include "objects/estruturas/tecto.h"
#include "objects/estruturas/floor.h"
#include "objects/estruturas/walls.h"

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

#include "objects\computer\ComputerVBO.h"

#include "objects/paralelepipedo/ParallelepipedVBO.h"

#include "objects\sconces\Sconce1VBO.h"
#include "objects\sconces\Sconce2VBO.h"
#include "objects\sconces\Sconce3VBO.h"

#include "objects\estruturas\FloorVBO.h"
#include "objects\estruturas\WallsVBO.h"
#include "objects\estruturas\CeilingVBO.h"
/* Mesas e cadeiras */
#include "objects/table/tableVBO.h"
#include "objects/chair/ChairVBO.h"
/* Packs */
#include "objects\packs\Mesa2Cadeiras.h"
#include "objects\packs\Mesa4Cadeiras.h"
#include "objects\packs\Mesa4Esplanada.h"

float rotation;
float rotationz;
float px, pz;
float camx, camy;
int face, modo;
bool cull;
bool dragging;
int dragx, dragy;
int figura;

float camz = 5.0;
float camYaw=0.0;      
float camPitch=0.0;     
float movevel=0.2;
float mousevel=0.2;


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

//PACKS

Mesa2Cadeiras *mesa2;
Mesa4Cadeiras *mesa4;
Mesa4Esplanada *mesa4e;

float p1[] = {-1.0f, 0.0f, 1.0f};
float p2[] = {1.0f, 0.0f, 1.0f};
float p3[] = {1.0f, 0.0f, -1.0f};
float p4[] = {-1.0f, 0.0f, -1.0f};
float p5[] = {0.0f, 2.0f, 0.0f};

void changeSize(int w, int h) {
    
	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;
    
	// compute window's aspect ratio
	float ratio = w * 1.0 / h;
    
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
    
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    
	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);
    
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {
    
	float pos[4] = {0.0, 20.0, 0.0, 1};
	float dif[] = {0.3,0.3,0.3,1};

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// set the camera
	glLoadIdentity();
    gluLookAt(20*sin(camx),2*camy,20*cos(camx),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
    
	/* Luzes */
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, dif);
	
	/* Activar texturas */
	glEnable(GL_TEXTURE_2D) ;

    // por instrucoes de desenho aqui
    //glutPostRedisplay();
    
    glPolygonMode(face, modo);
	if(cull) glEnable(GL_CULL_FACE);
	else glDisable(GL_CULL_FACE);
    
    glTranslatef(px, 0.0f, pz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationz, 1.0f,0.0f,0.0f);  


	float vermelho[]={1.0,0.3,0.3};
	float cinzento[]={1,1,1};
	float spec[]={1,1,1,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,cinzento);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);


	switch(figura){
		case 0:
				floorv->draw();
				wallsv->draw();

				glPushMatrix();
				glTranslatef(-5.9f,0,-3.0f);
				mesa2->draw2LugaresWine();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-3.3f,0,-3.0f);
				mesa2->draw2LugaresWisky();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-3.3f,0,-0.4f);
				mesa4->draw4LugaresWine();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.9f,0,-0.4f);
				mesa4->draw4LugaresShot();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.5f,0,-5.3f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspRectFino();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.7f,0,-5.3f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspRectFino();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.7f,0,-7.5f);
				glRotatef(180,0,1,0);
				mesa4e->draw4LugaresEspQuaFino();
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
				floorv->draw();
				wallsv->draw();
				ceilingv->draw();
				break;
		case 27:
				computer->draw();
				break;
		default:
				floorv->draw();
				wallsv->draw();
				ceilingv->draw();
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



void lockCamera()
{
        if(camPitch>90)
                camPitch=90;
        if(camPitch<-90)
                camPitch=-90;
        if(camYaw<0.0)
                camYaw+=360.0;
        if(camYaw>360.0)
                camYaw-=360;
}
 
void moveCamera(float dist,float dir)
{
        float rad=(camYaw+dir)*M_PI/180.0;
        camx-=sin(rad)*dist;    
        camz-=cos(rad)*dist;    
}
 
void moveCameraUp(float dist,float dir)
{
        float rad=(camPitch+dir)*M_PI/180.0;
        camy+=sin(rad)*dist;   
}

void UpdateCamera()
{
        glTranslatef(-camx,-camy,-camz);       
}

void keyboard_handler_explorer(unsigned char key, int x, int y){

    switch (key) {
        case 'a':
		{
			moveCamera(movevel,90.0);
			break;
		}
        case 'd':
		{
			moveCamera(movevel,270);;
			break;
		}
        case 'w':
		{
			if(camPitch!=90 && camPitch!=-90)
                moveCamera(movevel,0.0);    
            moveCameraUp(movevel,0.0);      
			break;
		}
        case 's':
		{
			if(camPitch!=90 && camPitch!=-90)
                moveCamera(movevel,180.0);
            moveCameraUp(movevel,180.0);
			break;
		}
        default:
            break;
    }
}

void mouse_motion_handler_explorer(int x, int y){
        int MidX=glutGet(GLUT_SCREEN_WIDTH)/2;
        int MidY=glutGet(GLUT_SCREEN_HEIGHT)/2;
		camYaw+=mousevel*(MidX-x);   
        camPitch+=mousevel*(MidY-y); 
		glutPostRedisplay();
}

void Control(bool mi)    
{
        if(mi) 
        {
                int MidX=glutGet(GLUT_SCREEN_WIDTH)/2;
                int MidY=glutGet(GLUT_SCREEN_HEIGHT)/2;
                glutSetCursor(GLUT_CURSOR_NONE);  
                glutPassiveMotionFunc(mouse_motion_handler_explorer);
                lockCamera();
                glutWarpPointer(MidX,MidY);      
                glutKeyboardFunc(keyboard_handler_explorer);        
        }
        glRotatef(-camPitch,1.0,0.0,0.0);       
        glRotatef(-camYaw,0.0,1.0,0.0);
}


int main(int argc, char **argv) {
    
    // inicializacao
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
    
	px = 0.0f; pz = 0.0f;
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

    // alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	plane = new PlaneVBO(5.0,7.0,30, id_textura);
	cylinder = new CylinderVBO(5, 5, 20, 10, id_textura);
	cube = new CubeVBO(6.0,5, id_textura);
	sphere = new SphereVBO(6,100,120,id_textura);
	cone = new ConeVBO(5,5.0,50,80,id_textura );

	wineCup = new WineCupVBO(0.4,20,20, id_textura);
	cocktailCup = new CocktailCupVBO(5,30,30, id_textura);
	shotCup = new ShotCupVBO(5,30,30,id_textura);
	vodkaCup = new VodkaCupVBO(5,30,30,id_textura);
	beerCup = new BeerCupVBO(5,30,30,id_textura);

	wiskyBottle = new WiskyBottleVBO(5,30,30,id_textura, id_textura, id_textura, id_textura, id_textura, id_textura);
	wineBottle = new WineBottleVBO(0.5,20,20, textura_green_glass);

	parallelepiped = new ParallelepipedVBO(4,6,5,30,id_textura,id_textura,id_textura,id_textura,id_textura,id_textura);

	computer = new ComputerVBO(5,20,30,id_textura,id_textura,id_textura,id_textura);

	sconce1 = new Sconce1VBO(5,5,20,id_textura,id_textura,id_textura);
	sconce2 = new Sconce2VBO(5,5,20,20,id_textura,0);
	sconce3 = new Sconce3VBO(5,20,20,id_textura,0);

	floorv = new FloorVBO(1,textura_madeira_chao);
	wallsv = new WallsVBO(1,textura_paredes);
	ceilingv = new CeilingVBO(1,0);

	mesa_um = new TableOneVBO(2, 1, 0.05, 0.8, 0.05, 30, 10, textura_alum_pernas, textura_alum_topo); 	
	mesa_dois = new TableTwoVBO(0.9, 1.8, 0.05, 0.65, 0.05, 30, 10, textura_alum_pernas, textura_alum_topo); 
	mesa_circular = new TableCircularVBO(0.7, 0.7, 20, 10, textura_madeira_moveis,textura_madeira_moveis,textura_madeira_moveis) ;

	cadeira_um = new ChairClassicaOneVBO(1, 10, 10, textura_madeira_moveis, textura_madeira_moveis, textura_madeira_moveis) ;
	cadeira_dois = new ChairClassicaTwoVBO(1, 10, 10, textura_alum_pernas, textura_alum_pernas, textura_alum_pernas) ;
	cadeira_tres = new ChairClassicaThreeVBO(5, 20, 15, 0, 0, 0) ;
	cadeira_pub = new ChairPubVBO(5, 20, 15, 0, 0, 0, 0) ;

	//PACKS

	mesa2 = new Mesa2Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4 = new Mesa4Cadeiras(textura_madeira_moveis,id_textura,textura_green_glass,textura_toalha);
	mesa4e = new Mesa4Esplanada(textura_alum_pernas,id_textura,textura_green_glass,textura_alum_topo);

    // entrar no ciclo do GLUT
	glutMainLoop();
    
	return 1;

}

