#pragma once
class BancoVBO
{
public:
	BancoVBO(double arg_alt, int arg_nlados, int arg_ncamadas, unsigned int arg_textura_pe, unsigned int arg_textura_assento);
	void draw();	
protected:
	double alt ;
	int nlados ;
	int ncamadas ;
	unsigned int textura_pe ;
	unsigned int textura_assento ;
};
