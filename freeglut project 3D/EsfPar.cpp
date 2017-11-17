#include "EsfPar.h"


EsfPar::EsfPar()
{
}

EsfPar::EsfPar(GLUquadric* o, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, PuntoVector3D* p) {
	_o = o;
	_rad = rad;
	_r = r;
	_g = g;
	_b = b;
	pos = p;
	vel = new PuntoVector3D(0, 1, 0, 0);
	acl = new PuntoVector3D(0, 0, 0, 0);
	mas = 1;
}

EsfPar::~EsfPar()
{
}

void EsfPar::update(){
	particula::update();
	Sphere::dibuja();
}