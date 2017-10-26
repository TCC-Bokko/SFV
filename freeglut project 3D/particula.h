#pragma once
#include "GL\freeglut.h"
#include <vector>

class particula
{
public:
	particula();
	particula(std::vector<float> p);
	~particula();

	void update();
	//int getLife() { return vida; }
	std::vector<float> particula::sumVec(std::vector<float> a, std::vector<float> b);

protected:
	std::vector<float> pos;
	std::vector<float> vel;
	std::vector<float> acl;
	float mas;
	//int vida;

};

