#ifndef H_PLANE_H
#define H_PLANE_H
#include "Objeto.h"

using namespace Physics;

class Plane : public Objeto
{
public:
	Plane(Punto o, GLfloat t, GLfloat r); //Origen, tamaño y coeficiente restitucion
	//Plane(Punto* p1, Punto* p2, Punto* p3);
	~Plane();

	// De Objeto
	void draw();
	void update(double deltaTime);
	void debugMessage();
	void invNormal() { normal.getY()*-1; }
	Plano* getPlane() { return plano; };
	PlanoXZ* getPlanoXZ() { return plXZ; }
	GLfloat getCR() { return CR; }
	Vector getN() { return normal; }
	//Vector forces222();

protected:
	void ptsXtam();

private:
	Plano* plano;
	Vector normal;
	PlanoXZ* plXZ;
	Punto pt1, pt2, pt3, pt4;
	GLfloat tam;
	GLfloat CR; //Coeficiente de restitucion
	Punto origen;
};
#endif