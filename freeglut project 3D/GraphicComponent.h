#pragma once
#include "ObjetoCompuesto.h"
class GraphicComponent
{
public:

	GraphicComponent(int type);

	virtual ~GraphicComponent() { delete obj3D; }

	void draw();

private:
	Objeto3D* obj3D;
};

