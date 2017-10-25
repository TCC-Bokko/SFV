#include "Cube.h"


Cube::Cube(int tam, GLfloat r, GLfloat g, GLfloat b)
{
	t = tam;
	_r = r;
	_g = g;
	_b = b;
}


Cube::~Cube()
{
}

void Cube::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	glColor3f(_r, _g, _b);
	glutSolidCube(t);
	glPopMatrix();
}