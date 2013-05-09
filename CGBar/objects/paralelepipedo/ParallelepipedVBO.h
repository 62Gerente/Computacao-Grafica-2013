#pragma once
class ParallelepipedVBO
{
private:
	float height;
	float width;
	float length;
	int layers;
	unsigned int id_textura ;
public:
	ParallelepipedVBO(float argHeight, float argWidth, float arglength, int argLayers, unsigned int argId_textura);
	void draw();
	void draw(unsigned int id_texturaposx, unsigned int id_texturanegx, unsigned int id_texturaposy, unsigned int id_texturanegy, unsigned int id_texturaposz, unsigned int id_texturanegz);
};

