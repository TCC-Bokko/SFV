#ifndef H_CYLINDER_H
#define H_CYLINDER_H
#include "ObjetoCuadrico.h"

class Cylinder :
	public ObjetoCuadrico
{
public:
	Cylinder(GLUquadric* o, GLfloat r1, GLfloat r2, GLfloat h, GLfloat r, GLfloat g, GLfloat b);
	virtual ~Cylinder(){}
	void dibuja();
private:
	GLfloat _r1,_r2, _h;
};
#endif
