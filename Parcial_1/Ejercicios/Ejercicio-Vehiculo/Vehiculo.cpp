#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    anioLanzamiento = 0;
    precio = 0;
    marca = "Desconocida";
}

void Vehiculo::hacerSonido() {
    std::cout << "Sonido de vehiculo" << std::endl;
}
