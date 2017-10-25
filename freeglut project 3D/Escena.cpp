#include "Escena.h"
#include "Sphere.h"
Escena::Escena()
{
	objetos.push_back(new Sphere(_o, 2, 1, 0, 0));

	PuntoVector3D * v = new PuntoVector3D(2, 2, 1, 0);
	objetos[0]->mT->scale(v);
}
