#include "Escena.h"
#include "Sphere.h"
#include "EsfPar.h"



Escena::Escena()
{
	PuntoVector3D* v = new PuntoVector3D(0, 0, 0, 0);
	
	//objetos.push_back(new Sphere(_o, 2, 1, 0, 0));
	componentes.push_back(new EsfPar(_o, 2, 2, 2, 0, v));
	//SP.addPar(par);
	
	/*
	PuntoVector3D * v = new PuntoVector3D(2, 2, 1, 0);
	objetos[0]->mT->scale(v);
	*/
}
void Escena::update(long long deltaTime){
	for each (auto c in componentes)
	{
		c->update(deltaTime);
		c->dibuja();
	}
}
