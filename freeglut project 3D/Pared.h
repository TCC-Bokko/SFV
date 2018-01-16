#ifndef H_WALL_H
#define H_WALL_H
#include "Objeto.h"

using namespace Physics;

class Pared
{
public:
	Pared(Punto centro, float h, float w, float cr);
	~Pared();
	void draw();

	GLfloat color[3];
	Punto centro;
	Plano* plano;
	GLfloat alto;
	GLfloat ancho;
	GLfloat largo;
	GLfloat coecifienteRecuperacion;
};

#endif