#include "Sphere.h"


Sphere::Sphere(GLUquadric* o, GLfloat rad, GLfloat r, GLfloat g, GLfloat b)
{
	_o = o;
	_rad = rad;

	_r = r;
	_g = g;
	_b = b;
}


void Sphere::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	glColor3f(_r, _g, _b);
	gluSphere(_o, _rad, 30, 30);
	glPopMatrix();
}