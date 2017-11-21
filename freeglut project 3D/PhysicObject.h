#pragma once
class PhysicObject
{
public:

	PhysicObject() {};
	virtual ~PhysicObject() {};
	virtual void update(long long deltaTime) = 0;
};

