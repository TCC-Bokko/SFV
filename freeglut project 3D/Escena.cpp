#include "Escena.h"
#include "particula.h"


PuntoVector3D* randomVector(float x, float y, float z) {
	int _x, _y, _z;
	x < 0 ? _x = x : _x = rand() % 15;
	y < 0 ? _z = y : _y = rand() % 15;
	z < 0 ? _z = z : _z = rand() % 15;
	return new PuntoVector3D(_x, _y, _z, 1);
}

Escena::Escena()
{
	PuntoVector3D* origin = new PuntoVector3D(0, 0, 0, 0);
	PuntoVector3D* v = new PuntoVector3D(0, 0, 0, 0);
	for (int i = 0; i < MAX_PARTICLES; i++) {
		//pos, acc, vel, mass
		objetos.push_back(new particula(new PuntoVector3D(rand()%10, 10, rand()%10, 1), new PuntoVector3D(0, 0, 0, 1), new PuntoVector3D(0, -((rand() % 0, 5) + 3), 0, 1), 1));
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

