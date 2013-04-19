#include <GLUT/glut.h>
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
//#include "objects/sconces/simpleSconce.h"
//#include "objects/sconces/treeSconce.h"
#include "objects/bancos/banco.h"
#include "objects/bottles/wineBottle.h"
#include "objects/bottles/wiskyBottle.h"
<<<<<<< HEAD
#include "objects/sconces/sconce1.h"
#include "objects/sconces/sconce2.h"
#include "objects/sconces/sconce3.h"
=======
#include "objects/table/table.h"
#include "objects/computer/computer.h"
#include "objects/chair/chair.h"
>>>>>>> 691e9b061b0cdc70af938623a5623315976b86f5

float rotation;
float rotationz;
float px, pz;
float camx, camy;
int face, modo;
bool cull;
bool dragging;
int dragx, dragy;
int figura;

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
    
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// set the camera
	glLoadIdentity();
    gluLookAt(3*sin(camx),camy,3*cos(camx),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
    
    // por instrucoes de desenho aqui
    //glutPostRedisplay();
    
    glPolygonMode(face, modo);
	if(cull) glEnable(GL_CULL_FACE);
	else glDisable(GL_CULL_FACE);
    
    glTranslatef(px, 0.0f, pz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationz, 1.0f,0.0f,0.0f);
<<<<<<< HEAD
    if (figura==0) {
        drawSconce3(4,30, 30);
=======
    
	drawChairClassica() ;	

	/*if (figura==0) {
        drawComputer(5, 10, 10);
>>>>>>> 691e9b061b0cdc70af938623a5623315976b86f5
    } else
    if (figura==1) {
        drawCylinder(3, 10, 30, 30);
    }else if(figura==2){
        drawPlane(5, 7, 30);
    }else if(figura==3){
        drawCube(5, 30);
    }else if(figura==4){
        drawSphere(3, 30, 30);
    }else if (figura==5){
        drawCylinder(3, 5, 30);
    }else if (figura==6){
        drawPlane(5, 5);
    }else if (figura==7){
        drawCone(3, 5, 30, 30);
    }else if (figura==9){
        drawWineCup(5, 30, 30);
    }else if (figura==10){
        drawCocktailCup(5, 30, 30);
    }else if (figura==11){
        drawBeerCup(5, 30, 30);
    }else if (figura==12){
        drawShotCup(5, 30, 30);
    }else if (figura==13){
        drawVodkaCup(5, 30, 30);
    }*/
    
	// End of frame
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
}

void menu_objectos_handler(int op){
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
        case 5:
		{
			figura = 6; // Plano sem camadas
			break;
		}
        default: return;
	}
	glutPostRedisplay();
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
        glutAddMenuEntry("CILINDRO SEM CAMADAS", 4);
        glutAddMenuEntry("PLANO SEM CAMADAS", 5);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mcopos = glutCreateMenu(menu_copos_handler);
        glutAddMenuEntry("Copo de Vinho", 0);
        glutAddMenuEntry("Copo de Cocktail", 1);
        glutAddMenuEntry("Copo de Fino", 2);
        glutAddMenuEntry("Copo de Shot", 3);
        glutAddMenuEntry("Codo de Bebida Branca", 4);
		glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mobjectos=  glutCreateMenu(menu_objectos_handler);
		glutAddSubMenu("Copos", mcopos);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    
    glutCreateMenu(menu_principal_handler);
        glutAddSubMenu("Opções", mopcoes);
        glutAddSubMenu("Primitivas", mfiguras);
		glutAddSubMenu("Objectos", mobjectos);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    // alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    
    // entrar no ciclo do GLUT
	glutMainLoop();
    
	return 1;
}
