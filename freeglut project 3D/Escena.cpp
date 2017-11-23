#include "Escena.h"
#include "particula.h"


PuntoVector3D* randomPosition() {
	return new PuntoVector3D(rand()%100, 30, rand()%100, 1);
}

Escena::Escena()
{
	PuntoVector3D* origin = new PuntoVector3D(0, 0, 0, 0);
	PuntoVector3D* v = new PuntoVector3D(0, 3, 0, 0);
	for (int i = 0; i < 1; i++) {
		objetos.push_back(new particula(v, new PuntoVector3D(0, 0, 0, 1), new PuntoVector3D(0, 0, 0, 1), 1));
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
}

void Escena::draw()
{
	for (auto o : objetos)
		o->dibuja();
}

