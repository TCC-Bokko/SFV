#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::update(long long deltaTime)
{
	phy->update(deltaTime);
	this->position = phy->getRotation();
	this->rotation = phy->getRotation();

}

void Entity::draw()
{
	gra->draw();
}
