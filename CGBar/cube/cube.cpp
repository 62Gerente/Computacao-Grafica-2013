void drawCube (float dim) {

	float n = dim/2  ;

	float A[] = {-n, -n, n};
	float B[] = {n, -n, n};
	float C[] = {n, -n, -n};
	float D[] = {-n, -n, -n};

	float E[] = {-n, n, n};
	float F[] = {n, n, n};
	float G[] = {n, n, -n};
	float H[] = {-n, n, -n};
	
	glBegin(GL_TRIANGLES);
		
		/* base inferior */
		glColor3f(AZUL) ;
		glVertex3fv(A) ;
		glVertex3fv(C) ;
		glVertex3fv(B) ;

		glColor3f(CINZNETO) ;
		glVertex3fv(A) ;
		glVertex3fv(D) ;
		glVertex3fv(C) ;    

		/* base superior */
		glColor3f(AZUL) ;
		glVertex3fv(G) ;
		glVertex3fv(E) ;
		glVertex3fv(F) ;

		glColor3f(CINZNETO) ;
		glVertex3fv(G) ;
		glVertex3fv(H) ;
		glVertex3fv(E) ;    

		/* face lateral +z  */
		glColor3f(LARANJA) ;
		glVertex3fv(F) ;
		glVertex3fv(A) ;
		glVertex3fv(B) ;

		glColor3f(VERMELHO) ;
		glVertex3fv(F) ;
		glVertex3fv(E) ;
		glVertex3fv(A) ;    

		/* face lateral -z  */
		glColor3f(LARANJA) ;
		glVertex3fv(C) ;
		glVertex3fv(D) ;
		glVertex3fv(G) ;

		glColor3f(VERMELHO) ;
		glVertex3fv(G) ;
		glVertex3fv(D) ;
		glVertex3fv(H) ; 

		/* face lateral +x */
		glColor3f(BRANCO) ;
		glVertex3fv(B) ;
		glVertex3fv(C) ;
		glVertex3fv(F) ;

		glColor3f(CASTANHO) ;
		glVertex3fv(C) ;
		glVertex3fv(G) ;
		glVertex3fv(F) ; 

		/* face lateral -x */
		glColor3f(BRANCO) ;
		glVertex3fv(D) ;
		glVertex3fv(A) ;
		glVertex3fv(H) ;

		glColor3f(CASTANHO) ;
		glVertex3fv(H) ;
		glVertex3fv(A) ;
		glVertex3fv(E) ; 

    glEnd();
}