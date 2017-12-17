#pragma once
#include "GL\freeglut.h"
#include "Sphere.h"
#include <vector>
#include "Objeto3D.h"
#include "PuntoVector3D.h"

class Pelota : public Sphere
{
public:
	Pelota(PuntoVector3D * pos0, PuntoVector3D * a0, PuntoVector3D* v0, float mass);
	~Pelota();

	void update(long long deltaTime);
	void dibuja();
	//int getLife() { return vida; }
	void Pstatus();

protected:
	PuntoVector3D* lastPosition;
	PuntoVector3D* velocity;
	PuntoVector3D* acceletarion;
	float mass;
	int life;

};

