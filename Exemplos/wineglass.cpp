/*
Name: Ahmed Rashed
ID: 05-06195-3
*/
#include <GLUT/glut.h>
#include <iostream>
using namespace std;

static GLfloat spin= 0.0;
static GLfloat co_x=0.0, co_y=0.0, co_z=1.0;

void init ()
{
	glClearColor (0.0,0.0,0.0,1.0);
	glShadeModel (GL_SMOOTH);
}

void display ()
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,co_x,co_y,co_z);
int yin = -46;
int yin1 = -98;
int rad = 4;


for(int i=0;i<90;i++){
	glRotatef(4, 0.0f, 1.0f, 0.0f);
for(int j=0;j<90;j++){
	if(j<57){
		glRotatef(4, 0.0f, 0.0f, 1.0f);
		glColor3f (1.0, 0.0, 1.0);
		glBegin(GL_POINTS);

		
		glVertex3f( -40.0,20.0,0.0);
		
		glEnd();
	}
	else
	{
		glRotatef(4, 0.0f, 0.0f, 1.0f);
		glColor3f (0.0, 0.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( -40.0,20.0,0.0);
		
		glEnd();
	}
}
}

for(int o=0;o<27;o++){

for(int p=0;p<45;p++){
		
		glRotatef(8, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 0.0, 1.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 4.5,yin,0.0);
		
		glEnd();
}
	yin = yin - 2;
}

for(int k=0;k<10;k++){
for(int l=0;l<360;l++){
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 0.0, 1.0);
		glBegin(GL_POINTS);
		glVertex3f( rad,yin1,0.0);
		glEnd();
}
	rad = rad + 2;
	yin1 = yin1 - 2;
}
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay ()
{
	spin= spin+1.0;
    if (spin>360)
        spin= spin-360;
    	glutPostRedisplay();
}

void spinDisplay1 ()
{
	spin= spin-1.0;
    if (spin<360)
        spin= spin+360;
    	glutPostRedisplay();
}

void reshape (int w, int h)
{
	glViewport (0,0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho (-150.0, 150.0, -150.0, 150.0, -150.0, 150.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
			{
				glutIdleFunc(spinDisplay1);
				
			}
			break;
		default:
			break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'x':
			co_x= 1.0;
			co_y= 0.0;
			co_z= 0.0;
			glutPostRedisplay();
			glutIdleFunc(NULL);
			break;

		case 'y':
			co_x= 0.0;
			co_y= 1.0;
			co_z= 0.0;
			glutPostRedisplay();
			glutIdleFunc(NULL);
			break;
				
		case 'z':
			co_x= 0.0;
			co_y= 0.0;
			co_z= 1.0;
			glutPostRedisplay();
			glutIdleFunc(NULL);
			break;


		case 'Z':
			co_x= 1.0;
			co_y= 1.0;
			co_z= 1.0;
			glutPostRedisplay();
			glutIdleFunc(NULL);
			break;

		case 's':
			spin = 0.0;
			glutPostRedisplay();
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}

int main ()
{
    glutInit();
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (250,250);
	glutCreateWindow ("Wine Glass: by Ahmed Rashed (05-06195-3)");
	init();
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutKeyboardFunc (keyboard);
	glutMainLoop ();
	return 0;
}


