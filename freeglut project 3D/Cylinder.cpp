#include "Cylinder.h"


Cylinder::Cylinder(GLUquadric* o, GLfloat r1, GLfloat r2, GLfloat h, GLfloat r, GLfloat g, GLfloat b)
{
	_o = o;
	_r1 = r1;
	_r2 = r2;
	_h = h;

	_r = r;
	_g = g;
	_b = b;
}


void Cylinder::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	glColor3f(_r, _g, _b);
	gluCylinder(_o, _r1, _r2, _h, 10, 10);
	glPopMatrix();
	
}