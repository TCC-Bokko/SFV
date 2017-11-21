#ifndef H_ENTITY_H
#define H_ENTITY_H
#include "PuntoVector3D.h"
#include "PhysicComponent.h";
class GraphicComponent;

using PVec3D = PuntoVector3D;

enum Entity_Type
{
	Particle
};
class Entity
{
public:
	Entity();
	~Entity();

	void update(long long deltaTime);
	void draw();

private:
	PVec3D position;
	PVec3D rotation;
	Entity_Type type;

	PhysicComponent * phy;
	GraphicComponent* gra;
};

#endif // H_ENTITY_H
