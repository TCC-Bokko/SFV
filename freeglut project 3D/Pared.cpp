#include "Pared.h"



Pared::Pared(PuntoVector3D * pos0, float mass, GLfloat r, GLfloat g, GLfloat b, PuntoVector3D * rot, GLfloat ang) 
	: Cube(1, r, g, b){
	position = pos0;
	this->mass = mass;

	mT->translate(position);
	PuntoVector3D * v = new PuntoVector3D(0.5, 20, 20, 1);
	mT->rotate(ang, rot);
	mT->scale(v);

}


Pared::~Pared()
{
	delete position;

}

void Pared::dibuja()
{
	Cube::dibuja();
}
