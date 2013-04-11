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
int rad = 60;
int Zin = 60;
int rad1 = 4;
int Zin1 = 4;
int rad2 = 0;
int Zin2 = -36;

for(int i=0;i<30;i++){

for(int j=0;j<360;j++){
		
		glRotatef(1, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_POINTS);

		
		glVertex3f( rad,0.0,Zin);
		
		glEnd();

}
	rad = rad - 2;
	
	Zin = Zin - 2;
	
}

for(int o=0;o<21;o++){

for(int p=0;p<360;p++){
		
		glRotatef(1, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_POINTS);

		
		glVertex3f( rad1,0.0,Zin1);
		
		glEnd();

}
	//rad = rad - 2;
	
	Zin1 = Zin1 - 2;
	
}

for(int q=0;q<360;q++){
		
		glRotatef(15, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_LINES);

		glVertex3f( 4.0,0.0,4.0);
		glVertex3f( 4.0,0.0,-38.0);
		
		glEnd();

}

for(int k=0;k<10;k++){

for(int l=0;l<360;l++){
		
		glRotatef(1, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_POINTS);

		
		glVertex3f( rad2,0.0,Zin2);
		
		glEnd();

}
	rad2 = rad2 + 2;
	
	Zin2 = Zin2 - 2;
	
}


for(int m=0;m<360;m++){
		
		glRotatef(15, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_LINES);

		glVertex3f( 0.0,0.0,0.0);
		glVertex3f( 60,0.0,60);
		
		glEnd();

}

for(int n=0;n<360;n++){
		
		glRotatef(15, 0.0f, 0.0f, 1.0f);
		glColor3f (0.50, 0.50, 0.50);
		glBegin(GL_LINES);

		glVertex3f( 0.0,0.0,-34);
		glVertex3f( 18.0,0.0,-54.0);
		
		glEnd();

}

glTranslatef(60.0,0.0,60.0);
for(int r=0;r<10;r++){

for(int s=0;s<360;s++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,0.0,20.0);
		
		glEnd();

}

for(int t=0;t<360;t++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,0.0,23.0);
		
		glEnd();

}	

for(int u=0;u<360;u++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,0.0,2.0);
		
		glEnd();

}

for(int v=0;v<360;v++){
		
		glRotatef(45, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f( 0.0,0.0,2.0);
		glVertex3f( 0.0,0.0,20.0);
		
		glEnd();

}		
	


for(int s1=0;s1<360;s1++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,2.0,20.0);
		
		glEnd();

}

for(int t1=0;t1<360;t1++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,2.0,23.0);
		
		glEnd();

}	

for(int u1=0;u1<360;u1++){
		
		glRotatef(1, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POINTS);

		
		glVertex3f( 0.0,2.0,2.0);
		
		glEnd();

}

for(int v1=0;v1<360;v1++){
		
		glRotatef(45, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f( 0.0,2.0,2.0);
		glVertex3f( 0.0,2.0,20.0);
		
		glEnd();

}

for(int v2=0;v2<360;v2++){
		
		glRotatef(10, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f( 0.0,2.0,20.0);
		glVertex3f( 0.0,0.0,20.0);
		
		glEnd();

}				
	
for(int v3=0;v3<360;v3++){
		
		glRotatef(10, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f( 0.0,2.0,23.0);
		glVertex3f( 0.0,0.0,23.0);
		
		glEnd();

}	

for(int v4=0;v4<360;v4++){
		
		glRotatef(10, 0.0f, 1.0f, 0.0f);
		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_LINES);

		glVertex3f( 0.0,2.0,2.0);
		glVertex3f( 0.0,0.0,2.0);
		
		glEnd();

}					
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
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (250,250);
	glutCreateWindow ("Glass: by Ahmed Rashed (05-06195-3)");
	init();
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutKeyboardFunc (keyboard);
	glutMainLoop ();
	return 0;
}


