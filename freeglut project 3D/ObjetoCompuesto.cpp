#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	_o = gluNewQuadric();
}


ObjetoCompuesto::~ObjetoCompuesto()
{
	for (auto o : objetos){
		delete o;
	}
}
void ObjetoCompuesto::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mT->getm());
	for (auto o : objetos)
		o->dibuja();
	glPopMatrix();
}