#include "PSystem.h"
#include <iostream>
#include <time.h>

PSystem::PSystem()
{
	location.set(0.f, 0.f, 0.f);
	radius = 1.0f;
	Vector nSpeed(0.f, -2.f, 0.f);
	speed = nSpeed;
	setup(nSpeed);
	np = 5;
	gravity = false;
	debug = false;
}


PSystem::~PSystem()
{
}

void PSystem::setup(Vector speed) {
	if (gravity) gForce = -9.8f;
	else gForce = 0.f;

	srand(time(0));
	Vector nSpeed;
		sistema.resize(np);
	int rX, rY, rZ;
	Vector finalDir;

	//std::cout << "Speed: (" << speed.getX() << ", " << speed.getY() << ", " << speed.getZ() << ")\n";

	//Obtener un porcentaje de direccion en cada eje
	for (int i = 0; i < sistema.size(); i++) {
		//Hacemos un random de la dirección (-0.5~0.5)
		finalDir.setX(((rand() % 100) / 100.f) - 0.5f);
		finalDir.setY(((rand() % 100) / 100.f) - 0.5f);
		finalDir.setZ(((rand() % 100) / 100.f) - 0.5f);
		//std::cout << "Final dir: (" << finalDir.getX() << ", " << finalDir.getY() << ", " << finalDir.getZ() << ");\n";
		//Aplicamos el modificador 
		nSpeed.setX(finalDir.getX()*speed.getX());
		nSpeed.setY(finalDir.getY()*speed.getY());
		nSpeed.setZ(finalDir.getZ()*speed.getZ());
		//std::cout << "nSpeed: (" << nSpeed.getX() << ", " << nSpeed.getY() << ", " << nSpeed.getZ() << ");\n";
		//Metemos la velocidad modificada a las particulas
		sistema[i] = new Ball(location, nSpeed, 0.0001f, radius);
		//system("Pause");
	}

}

void PSystem::update(double dt) {
	
	//llamamos al update de cada objeto
	for (int i = 0; i < sistema.size(); i++) {
		sistema[i]->update(dt);
	}

	calcV(dt);
	if(debug) debugMessage();
}

void PSystem::draw() {
	for (int i = 0; i < sistema.size(); i++) {
		sistema[i]->draw();
	}
}

void PSystem::calcV(double dt) {
	float nvz;
	if (gravity) {
		for (int i = 0; i < sistema.size(); i++) {
			nvz = sistema[i]->velocity.getZ();
			nvz += dt*gForce*50;
			sistema[i]->velocity.setZ(nvz);
		}
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