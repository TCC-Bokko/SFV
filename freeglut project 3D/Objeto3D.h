#ifndef H_OBJETO3D_H
#define H_OBJETO3D_H
#include "TAfin.h"
#include "GL\freeglut.h"

class Objeto3D
{
public:
	Objeto3D() { mT = new TAfin(); };
	virtual ~Objeto3D(){};
	virtual void dibuja() = 0;
	TAfin* mT;	
protected:
	GLfloat _r, _g, _b;
};

#endif