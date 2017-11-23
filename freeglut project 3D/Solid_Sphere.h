#pragma once
#include "Sphere.h"

class Solid_Sphere :
	public Sphere
{
public:
	Solid_Sphere(PuntoVector3D * pos0, PuntoVector3D * a0, PuntoVector3D* v0, float mass);
	virtual ~Solid_Sphere();
	void update(long long deltaTime);
	void dibuja();
private:
	PuntoVector3D* lastPosition;
	PuntoVector3D* velocity;
	//PuntoVector3D* acceletarion;
	PuntoVector3D* linearMomentum;
	PuntoVector3D*	linearSpeed;
	PuntoVector3D*	translation;
	float mass;

	PuntoVector3D* force;

};

