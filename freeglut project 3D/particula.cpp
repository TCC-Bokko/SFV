#include "particula.h"

#include <stdio.h>
#include <iostream>

particula::particula(PuntoVector3D* pos0, PuntoVector3D* a0, PuntoVector3D* v0, float mass):Sphere(0.5, 0.1, 0.2, 0){
	position = pos0;
	velocity = v0;
	acceletarion = a0;
	this->mass = mass;
	life = 100;
	
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
	velocity->escalar(deltaTime / 1000);
	velocity->print();
	position->sumar(velocity);
	//vida--;
}

void particula::dibuja()
{
	mT->translate(position);
	Sphere::dibuja();
	
}
