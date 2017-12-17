#pragma once
#include "GL\freeglut.h"
#include "Cube.h"
#include <vector>
#include "Objeto3D.h"
#include "PuntoVector3D.h"

class Pared : public Cube 
{
public:
	Pared(PuntoVector3D * pos0, float mass, GLfloat r, GLfloat g, GLfloat b, PuntoVector3D * rot, GLfloat ang);
	virtual ~Pared();

	void update(long long deltaTime) {};
	void dibuja();

private:
	float mass;
};

