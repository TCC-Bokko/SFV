#pragma once
#include "GL\freeglut.h"
#include <vector>
//#include "Objeto3D.h"
#include "PuntoVector3D.h"
#include "PhysicObject.h"

class Particle:
	public PhysicObject
{
public:
	Particle();
	Particle(PuntoVector3D* p);
	~Particle();

	void update(long long deltaTime);
	//int getLife() { return vida; }
	void Pstatus();
	PuntoVector3D* Particle::sumVec(PuntoVector3D* a, PuntoVector3D* b);

protected:
	PuntoVector3D* pos;
	PuntoVector3D* vel;
	PuntoVector3D* acl;
	float mas;
	//int vida;

};

