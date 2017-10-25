#ifndef H_OBJETOCUADRICO_H
#define H_OBJETOCUADRICO_H
#include "Objeto3D.h"
class ObjetoCuadrico :
	public Objeto3D
{
public:
	ObjetoCuadrico();
	virtual ~ObjetoCuadrico();
protected:
	GLUquadric* _o;	
};
#endif
