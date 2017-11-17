#ifndef H_ESCENA_H
#define H_ESCENA_H

#include "ObjetoCompuesto.h"
#include "SistemaPart.h"
#include "particula.h"

class Escena :
	public ObjetoCompuesto
{
public:
	Escena();
	SistemaPart getSP(){ return SP; }
	void update(long long deltaTime);
private:
	SistemaPart SP;
};
#endif
