#include "Plane.h"
#include <iostream>

//Constructor del plano a partir de un origen y un tamaño
Plane::Plane(Punto o, GLfloat t) {
	tam = t;
	origen = o;
	ptsXtam();
	Punto* apt1 = &pt1;
	Punto* apt2 = &pt2;
	Punto* apt3 = &pt3;
	normal.setX(0);
	normal.setY(0);
	normal.setZ(0);
	//plano = new Plano(apt1, apt2, apt3);
	plXZ = new PlanoXZ(origen, t, normal);
}


Plane::Plane(Punto* p1, Punto* p2, Punto* p3) : Objeto() {
	pt1 = *p1;
	pt2 = *p2;
	pt3 = *p3;
	color[0] = color[1] = color[2] = 1.0f;
	//plano = new Plano(p1, p2, p3);
}

Plane::~Plane()
{
	delete plano;
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

void Plane::debugMessage() {
	std::cout << "\n\n______PLANO_____\n";
	std::cout << "Plane Location: (" << location.getX() << ", " << location.getY() << ", " << location.getZ() << ")\n";
	/*
	std::cout << "Plane Velocity: (" << velocity.getX() << ", " << velocity.getY() << ", " << velocity.getZ() << ")\n";
	std::cout << "Vertice 1: (" << pt1.getX() << ", " << pt1.getY() << ", " << pt1.getZ() << ")\n";
	std::cout << "Vertice 2: (" << pt2.getX() << ", " << pt2.getY() << ", " << pt2.getZ() << ")\n";
	std::cout << "Vertice 3: (" << pt3.getX() << ", " << pt3.getY() << ", " << pt3.getZ() << ")\n";
	std::cout << "Vertice 4: (" << pt4.getX() << ", " << pt4.getY() << ", " << pt4.getZ() << ")\n";
	*/
}