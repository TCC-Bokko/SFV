#include "GraphicComponent.h"
/*
Por no declarar otro enum, ni incluir entity aquí, hacemos un casting
que es perfectamente posible
Aquí se deben añadir todos los tipos de entidades que hagamos, o sus reprensentaciones
Si queremos que en el caso de particula sea una esfera pues se hace aquí, si queremos un solido rígido
pero que sea una esfera se especifica aquí.
Podemos usar macros como Particle, o formas como Sphere.
En clase discutimos si hacemos un enum para esto o no
	
*/
const int Sphere = 0;
GraphicComponent::GraphicComponent(int type)
{
	switch (type)
	{
	case Sphere:
		//Rellenar vosotros la contructora que yo no lo tengo muy claro
		//pero creo que pillais la idea
		//obj3D = new ();
		break;
	default:
		break;
	}
}

void GraphicComponent::draw()
{
	obj3D->dibuja();
}
