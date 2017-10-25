#include "ParcialDisk.h"


ParcialDisk::ParcialDisk(GLUquadric* o, GLfloat inR, GLfloat outR, GLfloat fAng, GLfloat sAng, GLfloat r, GLfloat g, GLfloat b)
{
	_o = o;
	_inR = inR;
	_outR = outR;
	_fAng = fAng;
	_sAng = sAng;

	_r = r;
	_g = g;
	_b = b;
}

void ParcialDisk::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	glColor3f(_r, _g, _b);
	gluPartialDisk(_o, _inR, _outR, 10, 10, _fAng, _sAng);
	glPopMatrix();
}
