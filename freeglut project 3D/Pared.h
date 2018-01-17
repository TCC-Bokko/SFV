#ifndef H_WALL_H
#define H_WALL_H
#include "Objeto.h"

using namespace Physics;

class Pared
{
public:
	Pared(Punto centro, Vector faceTo, float h, float w, float cr);
	~Pared();
	void draw();

	GLfloat color[3];
	Punto centro;
	Vector faceTo;
	Plano plano;
	GLfloat alto;
	GLfloat ancho;
	GLfloat largo;
	GLfloat cr;
};

#endif