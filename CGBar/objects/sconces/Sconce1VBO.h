#pragma once
class Sconce1VBO
{
private:
	double alt;
	int nlados;
	int ncamadas;
	unsigned int id_textura1;
	unsigned int id_textura2;
	unsigned int id_textura3;

	CylinderVBO* base;
	CylinderVBO* suporte;
	SphereVBO* esfera;
	CylinderVBO* apoio1;
	CylinderVBO* apoio2;
	CylinderVBO* apoio3;
	CylinderVBO* apoio4;
	CylinderVBO* abajur;

public:
	Sconce1VBO(void);
	void draw();
};

