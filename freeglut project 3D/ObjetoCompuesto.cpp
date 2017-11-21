#include "ObjetoCompuesto.h"
#include "Particle.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	_o = gluNewQuadric();
}


ObjetoCompuesto::~ObjetoCompuesto()
{
	for (auto o : componentes){
		delete o;
	}
}
void ObjetoCompuesto::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	for (auto o : componentes)
		o->dibuja();
	glPopMatrix();
}

