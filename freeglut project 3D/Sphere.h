#ifndef H_SPHERE_H
#define H_SPHERE_H

#include "ObjetoCuadrico.h"
class Sphere :
	public ObjetoCuadrico
{
public:
	Sphere(GLfloat rad, GLfloat r, GLfloat g, GLfloat b);
	virtual ~Sphere(){}
	void dibuja();
protected:
	GLfloat _rad;
};
#endif
