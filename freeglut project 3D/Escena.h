#ifndef H_ESCENA_H
#define H_ESCENA_H

#include "PuntoVector3D.h"
#include "Objeto3D.h"
#include "particula.h"
#include <vector>

#define MAX_PARTICLES 30

class Escena
{
public:
	Escena();
	void update(long long deltaTime);
	void draw();
private:
	std::vector<Objeto3D*> objetos;
};
#endif
