#ifndef H_OBJECT_H
#define H_OBJECT_H

#include "gl/glut.h"
#include "Physics.cpp"

using namespace Physics;

class Objeto
{
public:
	Objeto(Punto location, Vector velocity, GLfloat mass) :
		location(location), oldLocation(location), velocity (velocity), mass(mass){};
	~Objeto() {};

	Punto location;
	Punto oldLocation;
	Vector velocity;
	GLfloat mass;
	GLfloat color[3];

	virtual void draw() = 0;
	virtual void update(unsigned int deltaTime) = 0;
};

#endif