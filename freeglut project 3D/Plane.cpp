#include "Plane.h"
#include <iostream>

//Constructor del plano a partir de un origen y un tamaño
Plane::Plane(Punto o, GLfloat t, GLfloat r) {
	tam = t;
	origen = o;
	ptsXtam();
	Punto* apt1 = &pt1;
	Punto* apt2 = &pt2;
	Punto* apt3 = &pt3;

	normal.setX(0);
	normal.setY(1);
	normal.setZ(0);

	(r >= 0 && r <= 1) ? CR = r : CR = 1;

	plXZ = new PlanoXZ(origen, t, normal);
}

Plane::~Plane()
{
	delete plXZ;
}

void Plane::update(double deltaTime) {

}

void Plane::ptsXtam() {
	pt1.set(origen.getX(), origen.getY(), origen.getZ());
	pt2.set(tam+origen.getX(), origen.getY(), origen.getZ());
	pt3.set(tam+origen.getX(), origen.getY(), tam+origen.getZ());
	pt4.set(origen.getX(), origen.getY(), tam+origen.getZ());
}

void Plane::draw()
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0f, 0.0);	glVertex3f(pt1.getX(), pt1.getY(), pt1.getZ());
	glColor3f(0.0, 1.0f, 0.0);	glVertex3f(pt2.getX(), pt2.getY(), pt1.getZ());
	glColor3f(0.0, 1.0f, 0.0);	glVertex3f(pt3.getX(), pt3.getY(), pt3.getZ());
	glColor3f(0.0, 1.0f, 0.0);	glVertex3f(pt4.getX(), pt4.getY(), pt4.getZ());
	glEnd();
	glPopMatrix();
	

}
