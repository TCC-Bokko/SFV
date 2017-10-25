#ifndef H_PARCIALDISK_H
#define H_PARCIALDISK_H

#include "ObjetoCuadrico.h"
class ParcialDisk :
	public ObjetoCuadrico
{
public:
	ParcialDisk(GLUquadric* _o, GLfloat inR, GLfloat outR, GLfloat fAng, GLfloat sAng, GLfloat r, GLfloat g, GLfloat b);
	virtual ~ParcialDisk(){}
	void dibuja();
private:
	GLfloat _inR, _outR, _fAng, _sAng;
};
#endif
