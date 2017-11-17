#include "ObjetoCompuesto.h"
#include "particula.h"


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


void ObjetoCompuesto::update(long long deltaTime) {
	for (int i = 0; i < componentes.size(); i++)
		componentes[i]->update(deltaTime);
}
