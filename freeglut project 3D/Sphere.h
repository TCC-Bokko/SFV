#ifndef H_SPHERE_H
#define H_SPHERE_H

#include "ObjetoCuadrico.h"
class Sphere :
	public ObjetoCuadrico
{
public:
	Sphere(GLUquadric* o, GLfloat rad, GLfloat r, GLfloat g, GLfloat b);
	virtual ~Sphere(){}
	void dibuja();
private:
	GLfloat _rad;
};
#endif
