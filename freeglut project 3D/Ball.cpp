#include "Ball.h"



Ball::Ball(Punto location, Vector velocity, GLfloat mass, GLfloat radius):
	Objeto(location, velocity, mass), radius(radius)
{
	color[0] = color[1] = color[2] = 1.0f;
	sphere = new Esfera(&location, radius);
}


Ball::~Ball()
{
}


void Ball::draw() 
{
	glPushMatrix();
	glTranslated(location.getX(), location.getY(), location.getZ());
	glColor3f(color[0], color[1], color[2]);
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
}


void Ball::update(long deltaTime)
{
	oldLocation = location;

	location.set(velocity.getX() * deltaTime, velocity.getY() * deltaTime, velocity.getZ() * deltaTime);
}