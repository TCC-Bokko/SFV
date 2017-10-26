#include "particula.h"
#include <stdio.h>
#include <iostream>

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

void particula::Pstatus() {
	std::cout << "Pos: (" << pos[0] << ", " << pos[1] << ", " << pos[2] << ")\n";
}

void particula::update() {
	vel = sumVec(vel, acl);
	pos = sumVec(pos, vel);
	//vida--;
}

std::vector<float> particula::sumVec(std::vector<float> a, std::vector<float> b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			a[i] = a[i] + b[i];
		}
		return a;
	}
	else { 
		std::cout << "A =! B\n";
		return a; }
}