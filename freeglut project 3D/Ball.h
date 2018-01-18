#ifndef H_BALL_H
#define H_BALL_H
#include "Objeto.h"

using namespace Physics;

class Ball : public Objeto
{
public:
	Ball(Punto location, Vector velocity, GLfloat mass, GLfloat radius, Vector c);
	~Ball();
	void debugMessage();
	
	// De Objeto
	void draw();
	void update(double deltaTime);
	Esfera* getSphere() { return sphere; }
	void updatePhysics(Punto p, Vector impDir, GLfloat CR);
	bool physicsUpdated = false;

	Esfera* sphere;
	GLfloat radius;
	Vector aceleration;
};
#endif