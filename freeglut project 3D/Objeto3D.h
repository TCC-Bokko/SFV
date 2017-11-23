#ifndef H_OBJETO3D_H
#define H_OBJETO3D_H
#include "TAfin.h"
#include "PuntoVector3D.h"
#include "GL\freeglut.h"

class Objeto3D
{
public:
	Objeto3D() { mT = new TAfin(); };
	virtual ~Objeto3D(){};
	virtual void dibuja() = 0;
	virtual void update(long long deltaTime) = 0;
	TAfin* mT;	
protected:
	PuntoVector3D* position;
	GLfloat _r, _g, _b;
};

#endif