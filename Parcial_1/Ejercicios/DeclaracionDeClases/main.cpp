#include <iostream>
#include "Punto.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//Declaracion estatica
	Punto p(2,3);
	//Operador de acceso punto
	std::cout<<p.obtenerCoordenadaX()<<", "<<p.obtenerCoordenadaY()<<" )"<<std::endl;
	
	//Declaracion dinamica
	Punto* p2 = new Punto(4,5);
	//Operador de acceso flecha(->)
	std::cout<<"Las cordenadas del punto son: ( "<<p2->obtenerCoordenadaX()<<", "<<p2->obtenerCoordenadaY()<<" )"<<std::endl;
	//liberacion del objeto
	delete p2;
	return 0;
}
