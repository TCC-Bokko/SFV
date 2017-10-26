#pragma once
#include "particula.h"
#include "Sphere.h"
#include <vector>

class EsfPar :
	public particula,
	public Sphere
{
public:
	EsfPar();
	EsfPar(GLUquadric* o, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, std::vector<float> p);
	~EsfPar();
};

