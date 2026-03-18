#include "Punto.h"

int Punto::obtenerCoordenadaX() const{
return x;
}
int Punto::obtenerCoordenadaY() const{
return y;
}

void Punto::fijarX(int valorX){
	x=valorX;
}
void Punto::fijarY(int valorY){
	y=valorY;
}
