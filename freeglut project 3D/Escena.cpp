#include "Escena.h"
#include "particula.h"


PuntoVector3D* randomVector(PuntoVector3D* target, int min, int max) {
	target->setX(rand() % max + min);
	target->setY(rand() % max + min);
	target->setZ(rand() % max + min);
	return target;

}

Escena::Escena()
{
	PuntoVector3D* pos = new PuntoVector3D(0,0,0,1);
	PuntoVector3D* acc = new PuntoVector3D(0,0,0,1);
	PuntoVector3D* vel = new PuntoVector3D(0,0,0,1);


	for (int i = 0; i < MAX_PARTICLES; i++) {
		//pos, acc, vel, mass
		objetos.push_back(new particula(new PuntoVector3D()), randomVector(acc, 3, 10), randomVector(vel, 2, 4), 1));
	}

}
void Escena::update(long long deltaTime){
	system("cls");
	for each (auto objeto in objetos)
	{
		objeto->update(deltaTime);
		//objeto->dibuja();
		objeto->Pstatus();
	}
	draw();
}

void Escena::draw()
{
	for (auto o : objetos)
		o->dibuja();
}

