#include "../../primitives/cylinder/CylinderVBO.h"
#include "../../primitives/plane/PlaneVBO.h"
#include "../paralelepipedo/ParallelepipedVBO.h"

#pragma once
class ChairClassicaOneVBO
{
public:
	ChairClassicaOneVBO(float arg_tamanho, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) ;
	void draw();	
protected:
	float tamanho ;
	int n_vertices ;
	int n_camadas ;
	unsigned int textura_pe ;
	unsigned int textura_assento ;
	unsigned int textura_encosto ;
	float altura_assento ;
	float comprimento_assento ;
	float largura_assento ;
	float altura_pe ;
	float raio_pe ;	
	float altura_encosto ;	
	float largura_encosto ;
	float inclinacao_encosto ;
	CylinderVBO *pe ;
	ParallelepipedVBO *assento ;
	ParallelepipedVBO *encosto ;
};

class ChairClassicaTwoVBO
{
public:
	ChairClassicaTwoVBO(float tamanho, int n_vertices, int n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) ;
	void draw();	
protected:
	float tamanho ;
	int n_vertices ;
	int n_camadas ;
	unsigned int textura_pe ;
	unsigned int textura_assento ;
	unsigned int textura_encosto ;
	/* Vari�veis de assento */
	float altura_assento ;
	float comprimento_assento ;
	float largura_assento ;	
	ParallelepipedVBO *assento ;
	/* Vari�veis do p� */
	float altura_pe ;
	float raio_pe ;	
	float y_barra_pe  ;
	CylinderVBO *pe ;
	/* Vari�veis do encosto */
	float altura_encosto ;	
	float raio_encosto ;	
	CylinderVBO *encosto_vertical, *encosto_horizontal ;
	int n_barras ;
	/* Vari�veis das barras do assento */
	float altura_barra ;
	float comprimento_barra ;
	float largura_barra ;
	ParallelepipedVBO *barra_assento ;
	/* Barras entre os p�s */
	CylinderVBO *barra_pe ;
};

class ChairClassicaThreeVBO
{
public:
	ChairClassicaThreeVBO(float tamanho, int n_vertices, int n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto) ;
	void draw();	
protected:
	float tamanho ;
	int n_vertices ;
	int n_camadas ;
	unsigned int textura_pe ;
	unsigned int textura_assento ;
	unsigned int textura_encosto ;
	/* Vari�veis de assento */
	float altura_assento ;
	float comprimento_assento ;
	float largura_assento ;	
	ParallelepipedVBO *assento ;
	/* Vari�veis do p� */
	float altura_pe ;
	float raio_pe ;	
	float y_barra_pe  ;
	CylinderVBO *pe ;
	/* Vari�veis do encosto */
	float altura_encosto ;	
	float raio_encosto ;	
	float largura_encosto ;
	CylinderVBO *encosto_vertical, *encosto_horizontal ;
	int n_barras ;
	/* Vari�veis dos bra�os */
	float altura_braco ;
	float comprimento_braco ;
	float raio_braco ;
	CylinderVBO *braco_vertical ;
	CylinderVBO *braco_horizontal ;
	/* Vari�veis das barras do assento */
	float altura_barra ;
	float comprimento_barra ;
	float largura_barra ;
	ParallelepipedVBO *barra_assento ;
	/* Barras entre os p�s */
	CylinderVBO *barra_pe ;
};

class ChairPubVBO
{
public:
	ChairPubVBO(float arg_tamanho, int arg_n_vertices, int arg_n_camadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento, unsigned int arg_textura_encosto, unsigned int arg_textura_almofada) ;	
	void draw();	
protected:
	float tamanho ;
	int n_vertices ;
	int n_camadas ;
	unsigned int textura_pe ;
	unsigned int textura_assento ;
	unsigned int textura_encosto ;
	unsigned int textura_almofada ;
	/* Vari�veis de assento */
	float altura_assento ;
	float comprimento_assento ;
	float largura_assento ;	
	ParallelepipedVBO *assento ;
	/* Vari�veis do p� */
	float altura_pe ;
	float raio_pe ;	
	CylinderVBO *pe ;
	/* Vari�veis do encosto */
	float altura_encosto ;	
	float largura_encosto ;
	ParallelepipedVBO *encosto ;
	/* Vari�veis da almofada */
	float altura_almofada ;
	float raio_almofada ;
	CylinderVBO *almofada ;
	/* Vari�veis da base */
	float altura_base ;
	float raio_base ;	
	CylinderVBO *base ;
	/* Vari�veis do suporte */
	float altura_suporte ;
	float comprimento_suporte ;
	float raio_suporte ;
	float x_suporte ;
	float z_suporte ;	
	CylinderVBO *suporte_vertical ;
	CylinderVBO *suporte_horizontal ;
};