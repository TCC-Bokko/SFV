
#ifndef _PuntoVector3D_H_
#define _PuntoVector3D_H_

#include <math.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

class PuntoVector3D {
private:
	GLfloat x, y, z;
	int pv;
public:
	PuntoVector3D(GLfloat x, GLfloat y, GLfloat z, int pv);
	~PuntoVector3D();
	GLfloat getX() const;
	GLfloat getY() const;
	GLfloat getZ() const;
	bool esPunto() const;
	bool esVector() const;
	void escalar(GLfloat factor);
	void normalizar();
	void sumar(PuntoVector3D* pv);
	PuntoVector3D* clonar();
	GLfloat productoEscalar(PuntoVector3D* vector);
	PuntoVector3D* productoVectorial(PuntoVector3D* vector);

	void print();
};
#endif

