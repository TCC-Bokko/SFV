#pragma once
#include "PuntoVector3D.h"
class Instancia
{
public:
	Instancia(PuntoVector3D * posicion, float mass);
	virtual ~Instancia();
	void update(long long deltaTime) {};

private:
	float _mass;
};

