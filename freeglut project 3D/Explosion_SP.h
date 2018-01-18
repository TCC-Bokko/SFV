#pragma once

#include "gl/glut.h"
#include "Objeto.h"
#include "Ball.h"
//#include "Physics.cpp" //ya lo obtiene de Objeto.h
#include <vector>


class Explosion_SP
{
public:
	Explosion_SP();
	Explosion_SP(Physics::Punto loc, int n, Physics::Vector sp, float r, int life, bool g, bool d) : 
		location(loc), np(n), speed(sp), radius(r), life(life), gravity(g), debug(d), maxlife(life)
	{
		setup(speed);
	}
	~Explosion_SP();
	void setup(Physics::Vector speed);
	void update(double dt);
	void resizeSys(int n) { sistema.resize(n); } 
	int sysSize() { return np; }
	void addParticle(Ball* obj) { sistema.push_back(obj); }
	void debugMessage();
	void draw();
protected:
	void calcV(double dt);

private:
	int life;
	int maxlife;
	bool gravity;
	bool debug;
	float gForce;
	Physics::Punto location; //Lugar de origen del sistema de partículas
	int np; //Numero de particulas
	float radius;
	Physics::Vector speed;
	list<Ball*> sistema;
};

