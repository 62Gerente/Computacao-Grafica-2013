#include "../paralelepipedo/ParallelepipedVBO.h"
#include "../../primitives/cylinder/CylinderVBO.h"

#pragma once
class TableOneVBO
{
public:	
	TableOneVBO(float arg_largura_tabua, float arg_comprimento_tabua, float arg_altura_tabua, float arg_altura_pes, float arg_raio_pes, int arg_n_vertices_pes, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua);
	void draw();
protected:
	float largura ; 
	float comprimento ; 
	float altura_tabua ;
	float altura ;
	float raio ; 
	int nVertices ; 
	int nCamadas ;
	int textura_pe ; 
	int textura_tabua ;
	ParallelepipedVBO *tabua ;
	CylinderVBO *pe ;
};

class TableTwoVBO
{
public:	
	TableTwoVBO(float arg_largura_tabua, float arg_comprimento_tabua, float arg_altura_tabua, float arg_altura_pes, float arg_raio_pes, int arg_n_vertices_pes, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua);
	void draw();
protected:
	float largura ; 
	float comprimento ; 
	float altura_tabua ;
	float altura ;
	float raio ; 
	int nVertices ; 
	int nCamadas ;
	int textura_pe ; 
	int textura_tabua ;
	ParallelepipedVBO *tabua ;
	CylinderVBO *pe ;
	CylinderVBO *ligacao_pe ;
};


class TableCircularVBO
{
public:	
	TableCircularVBO(float arg_raio_tabua, float arg_altura_pe, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_tabua, unsigned int arg_textura_base) ;
	void draw();
protected:
	float raio_tabua ;
	float altura_pe ; 
	int n_vertices ;
	int n_camadas ;
	float altura_tabua ;	
	float raio_pe ;
	float altura_base ;
	float raio_base ;		
	unsigned int textura_pe ; 
	unsigned int textura_tabua ;
	unsigned int textura_base ;	
	CylinderVBO *tabua ;
	CylinderVBO *pe ;
	CylinderVBO *base ;
};