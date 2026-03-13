#include <iostream>
#include "Carro.h"
#include "Moto.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Vehiculo* a1 = new Carro();
	Vehiculo* a2 = new Moto();
	
	a1 -> hacerSonido();
	a2 -> hacerSonido();
	
	delete a1;
	delete a2;
	
	return 0;
};
