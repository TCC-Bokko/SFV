#ifndef H_DISK_H
#define H_DISK_H

#include "ObjetoCuadrico.h"
class Disk :
	public ObjetoCuadrico
{
public:
	Disk(GLUquadric* o, GLfloat inR, GLfloat outR, GLfloat r, GLfloat g, GLfloat b);
	virtual ~Disk(){}
	void dibuja();
private:
	GLfloat _inR, _outR;
};
#endif
