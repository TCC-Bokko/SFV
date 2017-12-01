#include "particula.h"

#include <stdio.h>
#include <iostream>

particula::particula(PuntoVector3D* pos0, PuntoVector3D* a0, PuntoVector3D* v0, float mass):Sphere(0.5f, 0.1f, 0.2f, 0){
	position = pos0;
	lastPosition = new PuntoVector3D(*pos0);
	velocity = v0;
	acceletarion = a0;
	this->mass = mass;
	life = 100;

	mT->translate(position);
	
}


particula::~particula()
{
	delete position;
	delete acceletarion;
	delete velocity;
}

void particula::Pstatus() {
	std::cout << "Pos: " << "( " << position->getX() << ", " << position->getY() << ", " << position->getZ() << ")" << endl;
}

void particula::update(long long deltaTime) {
	*lastPosition = position;

	PuntoVector3D acc(*acceletarion);
	PuntoVector3D vel(*velocity);
	acc.escalar((GLfloat)deltaTime / 1000);
	vel.sumar(&acc);
	vel.escalar((GLdouble)deltaTime / 1000);
	cout << "Vel: ";velocity->print();
	cout << "dT: " << deltaTime << endl;
	position->sumar(&vel);
	//vida--;
	if (position->getY() < 0) position->setPosition(position->getX(), 5, position->getZ());
}

void particula::dibuja()
{
	PuntoVector3D deltaSpace(*position);
	deltaSpace.restar(lastPosition);
	mT->translate(&deltaSpace);
	Sphere::dibuja();
	
}
