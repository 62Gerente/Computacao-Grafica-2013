#pragma once
class Primitivas
{
public:
	void draw();
	Primitivas(unsigned int id_textura_arg);
protected:
	unsigned int buffers[3];
	int nrIndex;
	int *aIndex;
	unsigned int id_textura ;
};

