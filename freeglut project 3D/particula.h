#pragma once
#include "GL\freeglut.h"
#include <vector>
//#include "Objeto3D.h"

class particula //: public Objeto3D
{
public:
	particula();
	particula(std::vector<float> p);
	~particula();

	void update();
	//int getLife() { return vida; }
	void Pstatus();
	std::vector<float> particula::sumVec(std::vector<float> a, std::vector<float> b);

protected:
	std::vector<float> pos;
	std::vector<float> vel;
	std::vector<float> acl;
	float mas;
	//int vida;

};

