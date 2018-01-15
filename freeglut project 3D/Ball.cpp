#include "Ball.h"
#include <iostream>


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


const float FRICTION = 0.10;
const float GRAVITY = 1;
Vector Ball::forces222()
{
	float frictX = 1;
	float frictY = 1;
	float frictZ = 1;

	if (velocity.getX() > 0)
	{
		frictX = -FRICTION;
	}
	else if (velocity.getX() < 0)
	{
		frictX = FRICTION;
	}

	if (velocity.getY() > 0)
	{
		frictY = -FRICTION;
	}
	else if (velocity.getY() < 0)
	{
		frictY = FRICTION;
	}
	
	if (velocity.getZ() > 0)
	{
		frictZ = -FRICTION;
	}
	else if (velocity.getZ() < 0)
	{
		frictZ = FRICTION;
	}
	return Vector(frictX, -(GRAVITY - frictY), frictZ);
}

void Ball::update(unsigned int deltaTime)
{
	std::cout << deltaTime << "\n";
	oldLocation = location;
	location.set(velocity.getX() * deltaTime * 0.001, velocity.getY() * deltaTime * 0.001, velocity.getZ() * deltaTime * 0.001);
	//velocity += deltaTime*forces222() / mass;

		//ball.velocity[j] += dt*forces222(i, j, ball.velocity[j]) / ball.mass;

}