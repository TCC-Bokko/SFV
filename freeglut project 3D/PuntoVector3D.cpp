
#include "PuntoVector3D.h"
#include <math.h>

PuntoVector3D::PuntoVector3D(GLfloat x, GLfloat y, GLfloat z, int pv) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->pv = pv;
}

PuntoVector3D::PuntoVector3D(PuntoVector3D & other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->pv = other.pv;
}

PuntoVector3D::~PuntoVector3D() {}

GLfloat PuntoVector3D::getX() const  {
	return x;
}
GLfloat PuntoVector3D::getY() const {
	return y;
}

GLfloat PuntoVector3D::getZ() const {
	return z;
}

void PuntoVector3D::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool PuntoVector3D::esPunto() const{
	return pv == 1;
}

bool PuntoVector3D::esVector() const{
	return pv == 0;
}

void PuntoVector3D::escalar(GLfloat factor) {
	x *= factor;
	y *= factor;
	z *= factor;
}

void PuntoVector3D::normalizar() {
	GLfloat modulo2 = productoEscalar(this);
	if (modulo2>0) {
		x = x / sqrt(modulo2);
		y = y / sqrt(modulo2);
		z = z / sqrt(modulo2);
	}
}

void PuntoVector3D::dividir(GLfloat factor) {
	x /= factor;
	y /= factor;
	z /= factor;
}

void PuntoVector3D::sumar(PuntoVector3D* pv) {
	x += pv->getX();
	y += pv->getY();
	z += pv->getZ();
}
void PuntoVector3D::restar(PuntoVector3D* other) {
	x -= other->getX();
	y -= other->getY();
	z -= other->getZ();
}

PuntoVector3D* PuntoVector3D::clonar() {
	return new PuntoVector3D(x, y, z, pv);
}

GLfloat PuntoVector3D::productoEscalar(PuntoVector3D* vector) {
	return x*vector->getX() +
		y*vector->getY() +
		z*vector->getZ();
}

PuntoVector3D* PuntoVector3D::productoVectorial(PuntoVector3D* v) {
	GLfloat resx = 0;
	GLfloat resy = 0;
	GLfloat resz = 0;
	resx = this->y*v->z - v->y*this->z;
	resy = this->z*v->x - v->z*this->x;
	resz = this->x*v->y - v->x*this->y;
	return new PuntoVector3D(resx, resy, resz, 0);
}

PuntoVector3D & PuntoVector3D::operator=(PuntoVector3D * other)
{
	x = other->getX();
	y = other->getY();
	z = other->getZ();
	pv = other->pv;
	return *this;
}

void PuntoVector3D::print()
{
	cout<< "( " << getX() << ", " << getY() << ", " << getZ() << ")";
}
