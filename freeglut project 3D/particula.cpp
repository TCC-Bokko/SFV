#include "particula.h"

particula::particula() {
	pos = { 0, 0, 0 };
	vel = { 0, 0, 0 };
	acl = { 0, 0, 0 };
	mas = 1;
	//vida = 10;
}

particula::particula(std::vector<float> p)
{
	pos = p;
	vel = { 0, 0, 0 };
	acl = { 0, 0, 0 };
	mas = 1;
	//vida = 10;
}


particula::~particula()
{
}

void particula::update() {
	vel = sumVec(vel, acl);
	pos = sumVec(pos, vel);
	//vida--;
}

std::vector<float> particula::sumVec(std::vector<float> a, std::vector<float> b) {
	std::vector<float> sol;
	sol = {0,0,0};

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			sol[i] = a[i] + b[i];
		}
		return sol;
	}
	else return sol;
}