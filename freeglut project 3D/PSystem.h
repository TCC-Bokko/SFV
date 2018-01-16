#pragma once

#include "gl/glut.h"
#include "Objeto.h"
#include "Ball.h"
//#include "Physics.cpp" //ya lo obtiene de Objeto.h
#include <vector>

using namespace Physics;


class PSystem
{
public:
	PSystem();
	PSystem(Punto loc, int n, Vector sp, float r, bool g, bool d) : location(loc), np(n), speed(sp), radius(r), gravity(g), debug(d) { setup(speed); }
	~PSystem();

	void setup(Vector speed);
	void update(double dt);
	void resizeSys(int n) { sistema.resize(n); } //
	int sysSize() { return np; }
	void addParticle(Ball* obj) { sistema.push_back(obj); }
	void debugMessage();
	void draw();
protected:
	void calcV(double dt);

private:
	bool gravity;
	bool debug;
	float gForce;
	Punto location; //Lugar de origen del sistema de partículas
	int np; //Numero de particulas
	float radius;
	Vector speed;
	vector<Ball*> sistema;
};

