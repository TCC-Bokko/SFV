#include "Explosion_SP.h"
#include <iostream>
#include <time.h>

Explosion_SP::Explosion_SP()
{
	location.set(0.f, 0.f, 0.f);
	radius = 1.0f;
	Physics::Vector nSpeed(0.f, -2.f, 0.f);
	speed = nSpeed;
	setup(nSpeed);
	np = 5;
	gravity = false;
	debug = false;
}


Explosion_SP::~Explosion_SP()
{
	for (auto p : sistema) delete p;
}

void Explosion_SP::setup(Physics::Vector speed) {
	if (gravity) gForce = -9.8f;
	else gForce = 0.f;

	srand(time(0));


	for (int i = 0; i < np; i++) {
		double randAngle = degrees2radians(rand() % 360);
		Physics::Vector vel(speed.getX()*cos(randAngle) + speed.getX()*0.5, speed.getY(), speed.getZ()*sin(randAngle));
		sistema.emplace_back(new Ball(location, vel, 0.0001f, radius, Vector(1,0,0)));
	}
	//printf("Seting up paticles...\n");
}

void Explosion_SP::update(double dt) {

	//llamamos al update de cada objeto
	life -= dt;
	if (life > 0) {
		for (auto particula : sistema) {
			particula->update(dt);
		}
		calcV(dt);
		if (debug) debugMessage();
	}
}

void Explosion_SP::draw() {
	if (life > 0) {
		for (auto particula : sistema) {
			particula->color[0] = (float)life/(float)maxlife;
			particula->color[1] = (float)life / (float)maxlife;
			particula->color[2] = ((float)life / (float)maxlife)*0.5 + 0.5;
			particula->draw();
		}
	}
}

void Explosion_SP::calcV(double dt) {
	float nvz;
	if (gravity) {
		for (auto par : sistema) {
			nvz = par->velocity.getZ();
			nvz += dt * gForce * 50;
			par->velocity.setZ(nvz);
		}
	}

}

void Explosion_SP::debugMessage() {
	system("cls");
	std::cout << "SP Location: ( " << location.getX() << ", " << location.getY() << ", " << location.getZ() << ") \n";
	std::cout << "Particles: " << np << "\n";
	std::cout << "Particle Radious: " << radius << "\n";
	std::cout << "Base speed: (" << speed.getX() << ", " << speed.getY() << ", " << speed.getZ() << ") \n";
	std::cout << "///////////////////////////////////////////////////////\n";
	int i = 0;
	for (auto particula : sistema) {
		std::cout << "P" << i << " Pos(" << particula->location.getX() << ", " << particula->location.getY() << ", " << particula->location.getZ() << ")"
			<< " P1 Speed(" << particula->velocity.getX() << ", " << particula->velocity.getY() << ", " << particula->velocity.getZ() << ")\n";
		i++;
	}

}