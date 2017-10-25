#pragma once
#include "PuntoVector3D.h"
#include "GL\freeglut.h"


class TAfin
{
public:
	TAfin();
	virtual ~TAfin();
	void postMultiplica(GLfloat* m1);
	void translate(PuntoVector3D* v);
	void rotate(GLfloat ang, PuntoVector3D* v);
	void scale(PuntoVector3D* v);
	GLfloat *getm();
private:
	GLfloat m[16];
};

