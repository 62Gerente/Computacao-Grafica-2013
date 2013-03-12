#include <GL/glut.h>
#include <cores.h>
#include <math.h>

float rotation;
float rotationz;
float px, pz;

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
	gluLookAt(7.0f,0.0f,0.0f,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
    
    // por instrucoes de desenho aqui
    glutPostRedisplay();
    glEnable(GL_CULL_FACE);
    
    glTranslatef(px, 0.0f, pz);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationz, 0.0f,0.0f,1.0f);
    
    glBegin(GL_TRIANGLES);
    glColor3ub(100, 149, 237);
    glVertex3f(p1[0], p1[1], p1[2]);
    glVertex3f(p2[0], p2[1], p2[2]);
    glVertex3f(p5[0], p5[1], p5[2]);
    
    glColor3ub(135, 206, 250);
    glVertex3f(p2[0], p2[1], p2[2]);
    glVertex3f(p3[0], p3[1], p3[2]);
    glVertex3f(p5[0], p5[1], p5[2]);
    
    glColor3ub(224, 255, 255);
    glVertex3f(p1[0], p1[1], p1[2]);
    glVertex3f(p4[0], p4[1], p4[2]);
    glVertex3f(p3[0], p3[1], p3[2]);
    
    glColor3ub(224, 255, 255);
    glVertex3f(p1[0], p1[1], p1[2]);
    glVertex3f(p3[0], p3[1], p3[2]);
    glVertex3f(p2[0], p2[1], p2[2]);
    
    glColor3ub(135, 206, 250);
    glVertex3f(p1[0], p1[1], p1[2]);
    glVertex3f(p5[0], p5[1], p5[2]);
    glVertex3f(p4[0], p4[1], p4[2]);
    
    glColor3ub(100, 149, 237);
    glVertex3f(p4[0], p4[1], p4[2]);
    glVertex3f(p5[0], p5[1], p5[2]);
    glVertex3f(p3[0], p3[1], p3[2]);
    
    glEnd();
    
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


// escrever funcao de processamento do menu




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
    
    // registo de funcoes
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
    
    // por aqui registo da funcoes do teclado e rato
	glutSpecialFunc(kb_special);
    glutKeyboardFunc(kb_normal);
    
    
    // por aqui a criacao do menu
    
    
    // alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
    // entrar no ciclo do GLUT
	glutMainLoop();
	
	return 1;
}

