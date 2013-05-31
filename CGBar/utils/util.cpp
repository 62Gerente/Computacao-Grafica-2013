#include <GLUT/glut.h>
#include "util.h"

void reiniciaMaterial() {

	float ambiente[] = {0.2, 0.2, 0.2, 1.0} ;
	float diffuse[] = {0.8, 0.8, 0.8, 1.0} ;
	float specular[] = {0.0, 0.0, 0.0, 1.0} ;
	float emission[] = {0.0, 0.0, 0.0, 1.0} ;
	float shininess[] = {0, 0, 0, 0} ;
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente) ; 
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse) ; 
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular) ; 
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission) ; 
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess) ; 
}