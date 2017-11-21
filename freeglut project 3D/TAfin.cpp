#include "TAfin.h"


TAfin::TAfin()
{
	for (int i = 0; i < 16; ++i) {
		//Esto es lo mismo
		m[i] = i % 5 == 0;
		//que esto, pero bastante más elegante
		/*if (i == 0 || i == 5 || i == 10 || i == 15) m[i] = 1;
		else m[i] = 0;*/
	}
}


TAfin::~TAfin()
{
}
void TAfin::translate(PuntoVector3D* v) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(v->getX(), v->getY(), v->getZ());
	GLfloat m1[16];
	//Dejar la matriz actual de modelado-vista en m1
	//Los 16 datos están enumerados por columnas
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::rotate(GLfloat ang, PuntoVector3D* v) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(ang, v->getX(), v->getY(), v->getZ());
	GLfloat m1[16];
	//Dejar la matriz actual de modelado-vista en m1
	//Los 16 datos están enumerados por columnas
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::scale(PuntoVector3D* v) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScalef(v->getX(), v->getY(), v->getZ());
	GLfloat m1[16];
	//Dejar la matriz actual de modelado-vista en m1
	//Los 16 datos están enumerados por columnas
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);
}

void TAfin::postMultiplica(GLfloat* m1) { //  post-multiplica (m= m * m1;)
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf(m); 	//Cargar m como matriz actual de modelado-vista
	glMultMatrixf(m1); 	//Post-multiplicar por m1
	glGetFloatv(GL_MODELVIEW_MATRIX, m); 	//Dejar el resultado en m
	glPopMatrix();
}

GLfloat *TAfin::getm() {
	return m;
}