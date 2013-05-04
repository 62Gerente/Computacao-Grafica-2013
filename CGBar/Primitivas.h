#pragma once
class Primitivas
{
public:
	virtual void draw() = 0;
protected:
	unsigned int buffers[3];
	int nrIndex;
	int *aIndex;
};

