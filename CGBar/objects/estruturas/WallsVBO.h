#pragma once
class WallsVBO
{
private:
	double ratio;
	unsigned int id_textura ;
public:
	WallsVBO(double argRatio, unsigned int aId_textura);
	void draw();
	void drawWallsX();
	void drawWallsZ();
};

