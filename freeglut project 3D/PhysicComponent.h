#pragma once
#include "Entity.h"
#include "PhysicObject.h"
#include "Particle.h"
#include <vector>
#include <string>

using PVec3D = PuntoVector3D;
using namespace std;
class PhysicComponent
{
public:
	PhysicComponent(Entity_Type type, void* args);
	~PhysicComponent();

	void update(long long deltaTime);
	PVec3D getPosition();
	PVec3D getRotation();
private:
	PhysicObject* phyObj;
	PVec3D position;
	PVec3D rotation;
};

