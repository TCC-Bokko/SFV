#include "PSystem.h"
#include <iostream>


PSystem::PSystem()
{
	location.set(0.f, 0.f, 0.f);
	radius = 1.0f;
	Vector nSpeed(0.f, -2.f, 0.f);
	speed = nSpeed;
	setup(nSpeed);
}


PSystem::~PSystem()
{
}

void PSystem::setup(Vector speed) {
	Vector nSpeed;
	//Vector direction(0,1,0);
	sistema.resize(np);
	
	for (int i = 0; i < sistema.size(); i++){
		nSpeed = speed;
		sistema[i] = new Ball(location, nSpeed, 0.00001f , radius);
	}
}

void PSystem::update(double dt) {
	
	//llamamos al update de cada objeto
	for (int i = 0; i < sistema.size(); i++) {
		sistema[i]->update(dt);
	}

	debugMessage();
}

void PSystem::draw() {
	for (int i = 0; i < sistema.size(); i++) {
		sistema[i]->draw();
	}
}

void PSystem::debugMessage() {
	system("cls");
	std::cout << "SP Location: ( " << location.getX() << ", " << location.getY() << ", " << location.getZ() << ") \n";
	std::cout << "Particles: " << np << "\n";
	std::cout << "Particle Radious: " << radius << "\n";
	std::cout << "Base speed: (" << speed.getX() << ", " << speed.getY() << ", " << speed.getZ() << ") \n";
	std::cout << "///////////////////////////////////////////////////////\n";
	for (int i = 0; i < sistema.size(); i++){
		std::cout << "P" << i <<" Pos(" << sistema[i]->location.getX() << ", " << sistema[i]->location.getY() << ", " << sistema[i]->location.getZ() << ")"
			  << " P1 Speed(" << sistema[i]->velocity.getX() << ", " << sistema[i]->velocity.getY() << ", " << sistema[i]->velocity.getZ() << ")\n";
	}

}