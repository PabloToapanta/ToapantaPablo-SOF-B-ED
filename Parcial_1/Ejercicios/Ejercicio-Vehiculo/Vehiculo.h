#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo
{
public:
    int anioLanzamiento;
    double precio;
    std::string marca;

public:
    Vehiculo();
    virtual void hacerSonido();
};

#endif
