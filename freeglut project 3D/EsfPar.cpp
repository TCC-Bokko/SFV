#include "EsfPar.h"


EsfPar::EsfPar()
{
}

EsfPar::EsfPar(GLUquadric* o, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, std::vector<float> p) {
	_o = o;
	_rad = rad;
	_r = r;
	_g = g;
	_b = b;
	pos = p;
	vel = { 0, 1, 0 };
	acl = { 0, 0, 0 };
	mas = 1;
}

EsfPar::~EsfPar()
{
}
