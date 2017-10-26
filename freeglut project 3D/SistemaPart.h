#pragma once
#include "particula.h"
class SistemaPart
{
public:
	SistemaPart();
	~SistemaPart();

	void addPar(particula* pr) { sp.push_back(*pr); };
	void updateSP();

private:
	std::vector<particula> sp;

};

