#ifndef H_BALL_H
#define H_BALL_H
#include "Objeto.h"

using namespace Physics;

class Ball : public Objeto
{
public:
	Ball(Punto location, Vector velocity, GLfloat mass, GLfloat radius);
	~Ball();
	void debugMessage();
	
	// De Objeto
	void draw();
	void update(double deltaTime);

	Vector forces222();

	Esfera* sphere;
	GLfloat radius;
	Vector aceleration;

};
#endif