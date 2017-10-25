#ifndef H_CUBE_H
#define H_CUBE_H

#include "ObjetoCuadrico.h"

class Cube :
	public ObjetoCuadrico
{
public:
	Cube(int tam, GLfloat r, GLfloat g, GLfloat b);
	virtual ~Cube();
	void dibuja();
private:
	int t;
};

#endif