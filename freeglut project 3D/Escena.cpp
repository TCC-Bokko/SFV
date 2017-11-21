#include "Escena.h"
#include "Sphere.h"
#include "EsfPar.h"



Escena::Escena()
{
	//Emmmm esto darle una vuelta porque yo no lo tengo muyclaro
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
	for each (Entity* e in entitys)
	{
		e->update(deltaTime);
		e->draw();
	}
}
