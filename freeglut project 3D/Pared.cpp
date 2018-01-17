#include "Pared.h"


Pared::Pared(Punto centro, float h, float w, float cr)
{
	this->centro = centro;
	color[0] = 0;
	color[1] = 0;
	color[2] = 1.0f;
	Punto a(centro.getX() - w / 2, centro.getY() + h / 2, centro.getZ());
	Punto b(centro.getX() + w / 2, centro.getY() + h / 2, centro.getZ());
	Punto c(centro.getX() - w / 2, centro.getY() - h / 2, centro.getZ());
	plano = new Plano(&a, &b, &c);

	alto = h;
	ancho = w;
	coecifienteRecuperacion = cr;
}


Pared::~Pared()
{
	delete plano;
}

void Pared::draw()
{
	glPushMatrix();
		glTranslated(centro.getX(), centro.getY(), centro.getZ());
		glColor3f(color[0], color[1], color[2]);
		glPushMatrix();
			glScaled(ancho, alto, 10);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}