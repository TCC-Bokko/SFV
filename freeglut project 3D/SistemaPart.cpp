#include "SistemaPart.h"

SistemaPart::SistemaPart()
{
}


SistemaPart::~SistemaPart()
{
}

void SistemaPart::updateSP() {
	for (int i = 0; i < sp.size(); i++) {
		sp[i].update();
		sp[i].Pstatus();
	}
}