#include "Disk.h"


Disk::Disk(GLUquadric* o, GLfloat inR, GLfloat outR, GLfloat r, GLfloat g, GLfloat b)
{
	_o = o;
	_inR = inR;
	_outR = outR;

	_r = r;
	_g = g;
	_b = b;
}


void Disk::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	glColor3f(_r, _g, _b);
	gluDisk(_o, _inR, _outR, 10, 10);
	glPopMatrix();
	
}