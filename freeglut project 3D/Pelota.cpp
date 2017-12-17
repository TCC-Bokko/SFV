#include "Pelota.h"

#include <stdio.h>
#include <iostream>

Pelota::Pelota(PuntoVector3D* pos0, PuntoVector3D* a0, PuntoVector3D* v0, float mass) :Sphere(0.58f, 0.43f, 0.41f, 0) {
	position = pos0;
	lastPosition = new PuntoVector3D(*pos0);
	velocity = v0;
	acceletarion = a0;
	this->mass = mass;
	life = 100;

	mT->translate(position);

}


Pelota::~Pelota()
{
	delete position;
	delete acceletarion;
	delete velocity;
}

void Pelota::Pstatus() {
	std::cout << "Pos: " << "( " << position->getX() << ", " << position->getY() << ", " << position->getZ() << ")" << endl;
}

void Pelota::update(long long deltaTime) {
	*lastPosition = position;
	PuntoVector3D aux(*velocity);
	std::cout << "seg: " << (GLdouble)deltaTime / 1000 << "\n";
	aux.escalar((GLdouble)deltaTime / 1000);
	cout << "Vel: "; velocity->print();
	cout << "dT: " << deltaTime << endl;
	position->sumar(&aux);
	//vida--;
	if (position->getY() < 0) position->setPosition(position->getX(), 5, position->getZ());
}

void Pelota::dibuja()
{
	PuntoVector3D deltaSpace(*position);
	deltaSpace.restar(lastPosition);
	mT->translate(&deltaSpace);
	Sphere::dibuja();

}
