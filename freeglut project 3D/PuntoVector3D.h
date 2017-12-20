#ifndef _PuntoVector3D_H_
#define _PuntoVector3D_H_

#include <math.h>
#include <GL/freeglut.h>
#include <iostream>

#define VECTOR 0
#define PUNTO 1
using namespace std;

class PuntoVector3D {
private:
	GLfloat x, y, z;
	int pv;
public:
	//Constructors
	PuntoVector3D(GLfloat x, GLfloat y, GLfloat z, int pv);
	PuntoVector3D(PuntoVector3D& other);
	PuntoVector3D(PuntoVector3D* pOther);
	inline PuntoVector3D() : x(0), y(0), z(0), pv(0) {};
	~PuntoVector3D();

	//Getters
	GLfloat getX() const;
	GLfloat getY() const;
	GLfloat getZ() const;

	//Operations////////////////
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	bool esPunto() const;
	bool esVector() const;
	void escalar(GLfloat factor);
	void dividir(GLfloat factor);
	void normalizar();
	void sumar(PuntoVector3D* pv);
	void restar(PuntoVector3D* other);
	PuntoVector3D* clonar();
	GLfloat productoEscalar(PuntoVector3D* vector);
	PuntoVector3D* productoVectorial(PuntoVector3D* vector);

	//OPERATORS////////////////
	//Asigment
	PuntoVector3D& operator=(PuntoVector3D &other);
	PuntoVector3D& operator=(PuntoVector3D* other);
	//Scale
	PuntoVector3D& operator*=(GLfloat scalar);
	PuntoVector3D operator*(GLfloat scalar);
	//Adding
	PuntoVector3D operator+(PuntoVector3D &other);
	PuntoVector3D& operator+=(PuntoVector3D &other);
	//Subtract
	PuntoVector3D operator-(PuntoVector3D &other);
	PuntoVector3D& operator-=(PuntoVector3D &other);
	//Divide
	PuntoVector3D operator/(GLfloat scalar);
	PuntoVector3D& operator/=(GLfloat scalar);

	//DEBUG
	void print();
};
#endif