#ifndef H_BALL_H
#define H_BALL_H
#include "Objeto.h"

using namespace Physics;

class Ball : public Objeto
{
public:
	Ball(Punto location, Vector velocity, GLfloat mass, GLfloat radius);
	~Ball();
	
	void draw();
	void update(long deltaTime);

	Esfera* sphere;
	GLfloat radius;
};
#endif