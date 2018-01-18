#include "Ball.h"
#include <iostream>


Ball::Ball(Punto location, Vector velocity, GLfloat mass, GLfloat radius):
	Objeto(location, velocity, mass), radius(radius)
{
	color[0] = color[1] = color[2] = 1.0f;
	sphere = new Esfera(location, radius);

	//Inicializar la gravedad
	aceleration = Vector(0, 0, 0);
}


Ball::~Ball()
{
	delete sphere;
}


void Ball::draw() 
{
	glPushMatrix();
	glTranslated(location.getX(), location.getY(), location.getZ());
	glColor3f(color[0], color[1], color[2]);
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
}


const float GRAVITY = 10;
void Ball::update(double deltaTime)
{
	// Lo del valor absoluto negativo esta en testing
	aceleration.setX(-std::abs((oldLocation.getX() - location.getX()) / deltaTime));
	aceleration.setY((-std::abs(oldLocation.getY() - location.getY()) / deltaTime) - GRAVITY);
	aceleration.setZ(-std::abs((oldLocation.getZ() - location.getZ()) / deltaTime));
	//std::cout << oldLocation.getY() - location.getY() << "\n";
	oldLocation = location;
	float x, y, z;
	x = location.getX();
	y = location.getY();
	z = location.getZ();

	velocity += aceleration.escalar(deltaTime);

	x += velocity.getX()*deltaTime;
	y += velocity.getY()*deltaTime;
	z += velocity.getZ()*deltaTime;

	location.set(x, y, z);
	sphere->updateCentro(location);

	if (location.getY() < -25.0f + radius) location.setY(-25.0f + radius);
}

void Ball::updatePhysics(Punto p, Vector impDir, GLfloat CR) { //Direccion impacto / Coef. Restitucion
	GLfloat yResult = -(velocity.getY()*CR);
	velocity.setY(yResult);
}

void Ball::debugMessage() {
	std::cout << "\n\n______BOLA_____\n";
	std::cout << "Ball Radius: " << radius << "\n";
	std::cout << "Ball Location: (" << location.getX() << ", " << location.getY() << ", " << location.getZ() << ")\n";
	std::cout << "Ball Velocity: (" << velocity.getX() << ", " << velocity.getY() << ", " << velocity.getZ() << ")\n";
	if (physicsUpdated) std::cout << "Updated Physics\n";
	else std::cout << "Not updated Physics\n";
}