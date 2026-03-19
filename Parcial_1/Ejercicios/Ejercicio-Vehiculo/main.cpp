#include <iostream>
#include <string>

// ==========================================
// CLASE BASE: Vehiculo
// ==========================================
class Vehiculo {
public:
    int anioLanzamiento;
    double precio;
    std::string marca;

public:
    Vehiculo() {
        anioLanzamiento = 0;
        precio = 0;
        marca = "Desconocida";
    }
    virtual void hacerSonido() {
        std::cout << "Sonido de vehiculo" << std::endl;
    }
    // Agregamos un destructor virtual porque estamos usando herencia y polimorfismo
    virtual ~Vehiculo() {} 
};

// ==========================================
// CLASE DERIVADA: Carro
// ==========================================
class Carro : public Vehiculo {
public:
    int numeroPuertas;

public:
    Carro() : Vehiculo() {
        numeroPuertas = 4;
    }
    void hacerSonido() override {
        std::cout << "SONIDO DE CARRO" << std::endl;
    }
};

// ==========================================
// CLASE DERIVADA: Moto
// ==========================================
class Moto : public Vehiculo {
public:
    int velocidadMaxima;
public:
    Moto() : Vehiculo() {
        velocidadMaxima = 185;
    }
    void hacerSonido() override {
        std::cout << "SONIDO DE MOTO" << std::endl;
    }
};

// ==========================================
// MAIN
// ==========================================
int main(int argc, char** argv) {
    Vehiculo* a1 = new Carro();
    Vehiculo* a2 = new Moto();
    
    a1->hacerSonido();
    a2->hacerSonido();
    
    delete a1;
    delete a2;
    
    return 0;
}
