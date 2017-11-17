#pragma once
#include "GL\freeglut.h"
#include <vector>
//#include "Objeto3D.h"
#include "PuntoVector3D.h"

class particula //: public Objeto3D
{
public:
	particula();
	particula(PuntoVector3D* p);
	~particula();

	void update(long long deltaTime);
	//int getLife() { return vida; }
	void Pstatus();
	PuntoVector3D* particula::sumVec(PuntoVector3D* a, PuntoVector3D* b);

protected:
	PuntoVector3D* pos;
	PuntoVector3D* vel;
	PuntoVector3D* acl;
	float mas;
	//int vida;

};

