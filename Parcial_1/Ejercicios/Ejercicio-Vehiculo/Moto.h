#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

class Moto : public Vehiculo
{
	public:
		int velocidadMaxima;
	public:
		Moto();
		void hacerSonido() override{
		std::cout<<"SONIDO DE MOTO"<<std::endl;
	}
	
};

#endif
