#include "Escena.h"
#include "Sphere.h"
#include "EsfPar.h"


Escena::Escena()
{
	//
	EsfPar* par;
	par = new EsfPar(_o, 2, 2, 2, 0, { 0,0,0 });
	//objetos.push_back(new Sphere(_o, 2, 1, 0, 0));
	objetos.push_back(par);
	SP.addPar(par);
	
	/*
	PuntoVector3D * v = new PuntoVector3D(2, 2, 1, 0);
	objetos[0]->mT->scale(v);
	*/
}
