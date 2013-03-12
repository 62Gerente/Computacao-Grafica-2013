void drawCylinder(float radius, float height, int vertex){
    int i;
    float twoPi = 2.0f * M_PI;
    float angact = 0.0f;
    float ang = twoPi/((float)vertex);
    
    glBegin(GL_TRIANGLES);
    
    for(i=0;i<vertex;i++){
        glColor3ub(224, 255, 255);
        glVertex3f(0,-(height/2),0);
        glVertex3f(radius*sin(angact), -(height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        
        glColor3ub(224, 255, 255);
        glVertex3f(0,(height/2),0);
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), (height/2), radius*cos(angact + ang));
        
        glColor3ub(100, 149, 237);
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact), -(height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        
        glColor3ub(100, 149, 237);
        glVertex3f(radius*sin(angact), (height/2), radius*cos(angact));
        glVertex3f(radius*sin(angact + ang), -(height/2), radius*cos(angact + ang));
        glVertex3f(radius*sin(angact + ang), (height/2), radius*cos(angact + ang));
        
        angact+=ang;
    }
    
    glEnd();
}