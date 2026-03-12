#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <stdexcept>
class Empleado{
	private:
		static int contador_id;
	public:
		int id;
		std::string nombre;
		std::string cargo;
		double salario;
		Empleado( std::string n, std::string c, double s){
			if (s < 0) {
            throw std::invalid_argument("Error: El salario no puede ser negativo.");
        }
        if (n.empty() || c.empty()) {
            throw std::invalid_argument("Error: El nombre y el cargo no pueden estar vacíos.");
        }
        id = contador_id++;         
        nombre = n;
        cargo = c;
        salario = s;
		}
		
};

#endif
