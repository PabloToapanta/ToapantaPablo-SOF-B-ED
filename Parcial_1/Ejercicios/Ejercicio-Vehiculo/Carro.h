#ifndef CARRO_H
#define CARRO_H

#include "Vehiculo.h"

class Carro : public Vehiculo
{
public:
    int numeroPuertas;

public:
    Carro();
    void hacerSonido() override {
        std::cout << "SONIDO DE CARRO" << std::endl;
    }
};

#endif
