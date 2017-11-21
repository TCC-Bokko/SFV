#include "PhysicComponent.h"



PhysicComponent::PhysicComponent(Entity_Type type, void* args)
{
	switch (type)
	{
	case Entity_Type::Particle:

		this->phyObj = new Particle((PuntoVector3D*)args);
		break;
	default:
		break;
	}
}


PhysicComponent::~PhysicComponent()
{
	delete phyObj;
}

void PhysicComponent::update(long long deltaTime)
{
	phyObj->update(deltaTime);
}
