#include <GL/glut.h>
#include <math.h>
#include "cores.h"
#include "cube.h"

float rotation;
float rotationz;
float px, pz;
float camx, camy;
int face, modo;
bool cull;
bool dragging;
int dragx, dragy;

float p1[] = {-1.0f, 0.0f, 1.0f};
float p2[] = {1.0f, 0.0f, 1.0f};
float p3[] = {1.0f, 0.0f, -1.0f};
float p4[] = {-1.0f, 0.0f, -1.0f};
float p5[] = {0.0f, 2.0f, 0.0f};

float origem[] = {0.0f, 0.0f, 0.0f};
float pX[] = {2.0f, 0.0f, 0.0f};
float pY[] = {0.0f, 2.0f, 0.0f};
float pZ[] = {0.0f, 0.0f, 2.0f};

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

//void drawCube (float dim) {
//
//	float n = dim/2  ;
//
//	float A[] = {-n, -n, n};
//	float B[] = {n, -n, n};
//	float C[] = {n, -n, -n};
//	float D[] = {-n, -n, -n};
//
//	float E[] = {-n, n, n};
//	float F[] = {n, n, n};
//	float G[] = {n, n, -n};
//	float H[] = {-n, n, -n};
//	
//	glBegin(GL_TRIANGLES);
//		
//		/* base inferior */
//		glColor3f(AZUL) ;
//		glVertex3fv(A) ;
//		glVertex3fv(C) ;
//		glVertex3fv(B) ;
//
//		glColor3f(CINZNETO) ;
//		glVertex3fv(A) ;
//		glVertex3fv(D) ;
//		glVertex3fv(C) ;    
//
//		/* base superior */
//		glColor3f(AZUL) ;
//		glVertex3fv(G) ;
//		glVertex3fv(E) ;
//		glVertex3fv(F) ;
//
//		glColor3f(CINZNETO) ;
//		glVertex3fv(G) ;
//		glVertex3fv(H) ;
//		glVertex3fv(E) ;    
//
//		/* face lateral +z  */
//		glColor3f(LARANJA) ;
//		glVertex3fv(F) ;
//		glVertex3fv(A) ;
//		glVertex3fv(B) ;
//
//		glColor3f(VERMELHO) ;
//		glVertex3fv(F) ;
//		glVertex3fv(E) ;
//		glVertex3fv(A) ;    
//
//		/* face lateral -z  */
//		glColor3f(LARANJA) ;
//		glVertex3fv(C) ;
//		glVertex3fv(D) ;
//		glVertex3fv(G) ;
//
//		glColor3f(VERMELHO) ;
//		glVertex3fv(G) ;
//		glVertex3fv(D) ;
//		glVertex3fv(H) ; 
//
//		/* face lateral +x */
//		glColor3f(BRANCO) ;
//		glVertex3fv(B) ;
//		glVertex3fv(C) ;
//		glVertex3fv(F) ;
//
//		glColor3f(CASTANHO) ;
//		glVertex3fv(C) ;
//		glVertex3fv(G) ;
//		glVertex3fv(F) ; 
//
//		/* face lateral -x */
//		glColor3f(BRANCO) ;
//		glVertex3fv(D) ;
//		glVertex3fv(A) ;
//		glVertex3fv(H) ;
//
//		glColor3f(CASTANHO) ;
//		glVertex3fv(H) ;
//		glVertex3fv(A) ;
//		glVertex3fv(E) ; 
//
//    glEnd();
//}

void drawPlane(float x, float z, int layers){
    float divx = x/layers;
    float divz = z/layers;
    
    glBegin(GL_TRIANGLES);
    
    for(int i=0; i<layers; i++){
        for(int j=0; j<layers; j++){
            glVertex3f((-x/2) + i*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx, 0, (z/2) - (j+1)*divz);
            glVertex3f((-x/2) + i*divx , 0, z/2 - (j+1)*divz);
           
            glVertex3f((-x/2) + i*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx , 0, z/2 - j*divz);
            glVertex3f((-x/2) + (i+1)*divx, 0, (z/2) - (j+1)*divz);
        }
    }
    
    glEnd();
}

void drawAxis () {


	glBegin(GL_LINES) ;
		
		//glColor3f(CINZNETO) ;
		glVertex3fv(origem) ;
		glVertex3fv(pZ) ;
		
		//glColor3f(CINZNETO) ;
		glVertex3fv(origem) ;
		glVertex3fv(pX) ;

		//glColor3f(CINZNETO) ;
		glVertex3fv(origem) ;
		glVertex3fv(pY) ;

	glEnd();

}



void renderScene(void) {
    
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// set the camera
	glLoadIdentity();
    gluLookAt(5*sin(camx),camy,5*cos(camx), 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
	/*gluLookAt(0.0f, 10.0f ,0.0f, 
		      0.0,0.0,0.0,
			  1.0f,0.0f,0.0f);*/
    
    // por instrucoes de desenho aqui
    glutPostRedisplay();
    
    glPolygonMode(face, modo);
	if(cull) glEnable(GL_CULL_FACE);
	else glDisable(GL_CULL_FACE);
    
    glTranslatef(px, 0.0f, pz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationz, 0.0f,0.0f,1.0f);
    
    //drawCube(1, 5) ;
	drawCube(1, 4) ;
	drawAxis() ;
    
	// End of frame
	glutSwapBuffers();
}



// escrever funcao de processamento do teclado
void kb_special(int key, int x, int y){
	switch(key)
	{
        case GLUT_KEY_DOWN:
		{
			if(px > -2.0f) px -= 0.1f;
			break;
		}
        case GLUT_KEY_UP:
		{
			if(px < 2.0f) px += 0.1f;
			break;
		}
        case GLUT_KEY_LEFT:
		{
			if(pz < 2.0f) pz += 0.1f;
			break;
		}
        case GLUT_KEY_RIGHT:
		{
			if(pz > -2.0f) pz -= 0.1f;
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
			rotationz += 1.5f;
			break;
		}
        case 's':
		{
			rotationz -= 1.5f;
			break;
		}
        default:
            break;
    }
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

void menu_handler(int op)
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
    glutCreateMenu(menu_handler);
	glutAddMenuEntry("GL_FRONT", 0);
	glutAddMenuEntry("GL_BACK", 1);
	glutAddMenuEntry("GL_FRONT_AND_BACK", 2);
	glutAddMenuEntry("GL_FILL", 3);
	glutAddMenuEntry("GL_LINE", 4);
	glutAddMenuEntry("Enable Cull Face", 5);
	glutAddMenuEntry("Disable Cull Face", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    // alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
    // entrar no ciclo do GLUT
	glutMainLoop();
	
	return 1;
}