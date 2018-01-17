#include "Pared.h"
#include <iostream>

Pared::Pared(Punto centro, Vector faceTo, float h, float w, float cr):
	centro(centro), faceTo(faceTo), alto(h), ancho(w), cr(cr), plano(Plano(faceTo, centro))
{
	this->centro = centro;
	color[0] = 0;
	color[1] = 0;
	color[2] = 1.0f;

}


Pared::~Pared()
{
}

void Pared::draw()
{
	glPushMatrix();
		glTranslated(centro.getX(), centro.getY(), centro.getZ());
		//Hay que rotar el cubo para que apunte a donde apunta el plano
		glScaled(ancho, alto, 10);
		glColor3f(color[0], color[1], color[2]);
		glRotated(angleBetweenVectors(faceTo, Vector(1, 0, 0)), 1, 0, 0);
		glRotated(angleBetweenVectors(faceTo, Vector(0, 1, 0)), 0, 1, 0);
		glRotated(angleBetweenVectors(faceTo, Vector(0, 0, 1)), 0, 0, 1);
		glutSolidCube(1);
	glPopMatrix();
	cout << "////////////////////////////////////////"<<endl<<"////////////////////////////////////////" << endl;
}