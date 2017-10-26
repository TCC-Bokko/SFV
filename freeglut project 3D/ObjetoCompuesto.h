#ifndef H_OBJETOCOMPUESTO_H
#define H_OBJETOCOMPUESTO_H

#include "Objeto3D.h"
#include <vector>
#include "PuntoVector3D.h"
class ObjetoCompuesto :
	public Objeto3D
{
public:
	ObjetoCompuesto();
	virtual ~ObjetoCompuesto();
	void dibuja();
	//void update();
protected:
	GLUquadric* _o;
	std::vector <Objeto3D*> objetos; // objetos que contiene(pueden ser compuestos o cuadricos)
};
#endif
