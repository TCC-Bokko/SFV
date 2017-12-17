#include "Escena.h"
#include "particula.h"
#include "Solid_Sphere.h"
#include "Pelota.h"
#include "Pared.h"


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
	objetos.push_back(new Pelota(new PuntoVector3D(20, 10, 20, 0), new PuntoVector3D(0, 0, 0, 1), new PuntoVector3D(0, 0, 0, 1), 1));

	objetos.push_back(new Pared(new PuntoVector3D(0, 10, 10, 0), 1, 0.82f, 0.1f, 0.012f, new PuntoVector3D(0, 1, 0, 1), 0));

	objetos.push_back(new Pared(new PuntoVector3D(10, 10, 0, 0), 1, 0.56f, 0.29f, 0.04f, new PuntoVector3D(0, 1, 0, 1), 90));

	objetos.push_back(new Pared(new PuntoVector3D(10, 0, 10, 0), 1, 0.13f, 0.69f, 0.42f, new PuntoVector3D(0, 0, 1, 1), 90));

}
void Escena::update(long long deltaTime){
	system("cls");
	for each (auto objeto in objetos)
	{
		objeto->update(deltaTime);
		//objeto->dibuja();
		//objeto->Pstatus();
	}
	draw();
}

void Escena::draw()
{
	for (auto o : objetos)
		o->dibuja();
}

