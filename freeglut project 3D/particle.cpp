#include "particle.h"
#include <stdio.h>
#include <iostream>

Particle::Particle() {
	pos = new PuntoVector3D(0, 0, 0, 0);
	vel = new PuntoVector3D(0, 0, 0, 0);
	acl = new PuntoVector3D(0, 0, 0, 0);
	mas = 1;
	//vida = 10;
}

Particle::Particle(PuntoVector3D* p)
{
	pos = p;
	vel = new PuntoVector3D(0, 0, 0, 0);
	acl = new PuntoVector3D(0, 0, 0, 0);
	mas = 1;
	//vida = 10;
}


Particle::~Particle()
{
}

void Particle::Pstatus() {
	std::cout << "Pos: (" << pos->getX() << ", " << pos->getY() << ", " << pos->getZ() << ")\n";
}

void Particle::update(long long deltaTime) {
	vel = sumVec(vel, acl);
	pos = sumVec(pos, vel);
	//vida--;
}

PuntoVector3D* Particle::sumVec(PuntoVector3D* a, PuntoVector3D* b) {

		return new PuntoVector3D(a->getX() + b->getX(), a->getY() + b->getY(), a->getZ() + b->getZ(), 0); 
}