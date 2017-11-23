#include "Solid_Sphere.h"

Solid_Sphere::Solid_Sphere(PuntoVector3D * pos0, PuntoVector3D * a0, PuntoVector3D* v0, float mass) : Sphere(0.5f, 0.1f, 0.2f, 0)
{
	position = pos0;
	lastPosition = new PuntoVector3D(*pos0);
	velocity = v0;
	//acceletarion = a0;
	this->mass = mass;

	mT->translate(position);

	force = new PuntoVector3D(0, 1, 1, 0);

	linearMomentum = force;
}


Solid_Sphere::~Solid_Sphere()
{
	delete position;
	//delete acceletarion;
	delete velocity;
	delete force;
}

void Solid_Sphere::update(long long deltaTime) 
{
	//momento linear
	force->escalar(deltaTime / 1000);
	linearMomentum->sumar(force);

	//velocidad
	linearMomentum->dividir(mass);
	linearSpeed = linearMomentum;

	//movimiento (distancia y direccion)
	linearSpeed->escalar(deltaTime / 1000);
	translation = linearSpeed;
}

void Solid_Sphere::dibuja() {
	mT->translate(translation);
	Sphere::dibuja();
}

