#ifndef H_ESCENA_H
#define H_ESCENA_H

#include "ObjetoCompuesto.h"
#include "SistemaPart.h"
#include "Entity.h"

class Escena :
	public ObjetoCompuesto
{
public:
	Escena();
	void update(long long deltaTime);
private:
	std::vector<Entity*> entitys;
};
#endif
