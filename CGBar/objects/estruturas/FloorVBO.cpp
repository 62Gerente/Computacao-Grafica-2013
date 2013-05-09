//#include "FloorVBO.h"
//
//#include <GLUT/glut.h>
//
//#include "../../primitives/cube/CubeVBO.h"
//#include "../../primitives/cylinder/CylinderVBO.h"
//
//FloorVBO::FloorVBO(double argRatio, unsigned int aId_textura){
//	ratio = argRatio;
//	id_textura = aId_textura;
//}
//
//void FloorVBO::draw(){
//    
//	
//	glPushMatrix();
//    glScaled(proporcao, proporcao, proporcao);
//    
//    glPushMatrix();
//    glTranslatef(0, 0, -2.5);
//    glScaled(1, 0.02, 3);
//    drawCube(5, 30);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(-2.5, 0, 7.5 + 0.25);
//    glScaled(2, 0.02, 1);
//    drawCube(5, 20);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(-2.5, 0, -5);
//    drawCylinder(5, 0.1, 300, 20);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(-5, 0, 0);
//    glScaled(1, 0.02, 2);
//    drawCube(5, 20);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(5 + 0.25, 0, 2.5);
//    glScaled(1, 0.02, 1);
//    drawCube(5, 10);
//    glPopMatrix();
//     
//    //Casa de Banho
//    glPushMatrix();
//    glTranslatef(5, 0, -2);
//    glScaled(1, 0.02, 0.5);
//    drawCube(5, 10);
//    glPopMatrix();
//    
//    //Passagens
//    
//    glPushMatrix();
//    glTranslatef(2.5+0.125, 0, 2.5);
//    glScaled(0.05, 0.02, 0.5);
//    drawCube(5, 2);
//    glPopMatrix();
//    
//    glPushMatrix();
//    glTranslatef(0, 0, 5+0.125);
//    glScaled(0.5, 0.02, 0.05);
//    drawCube(5, 2);
//    glPopMatrix();
//    
//    glPopMatrix();
//}