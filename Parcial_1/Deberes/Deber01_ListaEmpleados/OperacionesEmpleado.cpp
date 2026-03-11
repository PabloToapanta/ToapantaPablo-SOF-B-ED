#include <iostream>
#include <vector>
#include <string>
#include "OperacionesEmpleado.h"

void cargarDatosIniciales(std::vector<Empleado>& nomina) {
    nomina.push_back(Empleado("Ana Gomez", "Gerente General", 3500.00));
    nomina.push_back(Empleado("Luis Perez", "Desarrollador Backend", 1800.50));
    nomina.push_back(Empleado("Maria Lopez", "Desarrollador Frontend", 1750.00));
    nomina.push_back(Empleado("Carlos Ruiz", "Analista de Sistemas", 1500.00));
    nomina.push_back(Empleado("Sofia Castro", "Disenadora UX", 1600.00));
    nomina.push_back(Empleado("Jorge Torres", "Administrador BD", 1900.00));
    nomina.push_back(Empleado("Laura Suarez", "Ingeniera DevOps", 2100.00));
    nomina.push_back(Empleado("Pedro Mendoza", "Auditor Seguridad", 2200.00));
    nomina.push_back(Empleado("Elena Rojas", "Scrum Master", 1850.00));
    nomina.push_back(Empleado("Diego Ramirez", "Soporte Tecnico", 950.00));
}

void mostrarEmpleados(const std::vector<Empleado>& nomina) {
    if (nomina.empty()) {
        std::cout << "-> La lista esta vacia.\n";
        return;
    }
    std::cout << "\n--- LISTA DE EMPLEADOS ---\n";
    for(size_t i = 0; i < nomina.size(); i++) {
        std::cout << "ID: " << nomina[i].id 
                  << " | Nombre: " << nomina[i].nombre 
                  << " | Cargo: " << nomina[i].cargo 
                  << " | Salario: $" << nomina[i].salario << "\n";
    }
}

void registrarEmpleado(std::vector<Empleado>& nomina) {
    std::string nombre, cargo;
    double salario;
    
    std::cout << "\n--- REGISTRAR EMPLEADO ---\n";
    std::cin.ignore(); // Crucial para limpiar el buffer antes de leer textos
    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);
    std::cout << "Cargo: ";
    std::getline(std::cin, cargo);
    std::cout << "Salario: ";
    std::cin >> salario;
    
    try {
        Empleado nuevo(nombre, cargo, salario);
        nomina.push_back(nuevo);
        std::cout << "-> Exito: Empleado registrado con el ID " << nuevo.id << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "-> Error: " << e.what() << "\n";
    }
}

void buscarEmpleado(const std::vector<Empleado>& nomina) {
    int idBuscar;
    std::cout << "\n--- BUSCAR EMPLEADO ---\n";
    std::cout << "Ingrese ID: ";
    std::cin >> idBuscar;

    for (size_t i = 0; i < nomina.size(); i++) {
        if (nomina[i].id == idBuscar) {
            std::cout << "-> Encontrado: " << nomina[i].nombre 
                      << " | Cargo: " << nomina[i].cargo 
                      << " | Salario: $" << nomina[i].salario << "\n";
            return;
        }
    }
    std::cout << "-> Error: No existe el ID " << idBuscar << "\n";
}

void modificarEmpleado(std::vector<Empleado>& nomina) {
    int idBuscar;
    std::cout << "\n--- MODIFICAR SALARIO ---\n";
    std::cout << "Ingrese ID del empleado: ";
    std::cin >> idBuscar;

    for (size_t i = 0; i < nomina.size(); i++) {
        if (nomina[i].id == idBuscar) {
            std::cout << "Empleado: " << nomina[i].nombre << " (Actual: $" << nomina[i].salario << ")\n";
            std::cout << "Ingrese nuevo salario: ";
            double nuevoSalario;
            std::cin >> nuevoSalario;
            
            if (nuevoSalario >= 0) {
                nomina[i].salario = nuevoSalario;
                std::cout << "-> Exito: Salario actualizado.\n";
            } else {
                std::cout << "-> Error: El salario no puede ser negativo.\n";
            }
            return;
        }
    }
    std::cout << "-> Error: No existe el ID " << idBuscar << "\n";
}

void eliminarEmpleado(std::vector<Empleado>& nomina) {
    int idBuscar;
    std::cout << "\n--- ELIMINAR EMPLEADO ---\n";
    std::cout << "Ingrese ID del empleado: ";
    std::cin >> idBuscar;

    for (size_t i = 0; i < nomina.size(); i++) {
        if (nomina[i].id == idBuscar) {
            nomina.erase(nomina.begin() + i);
            std::cout << "-> Exito: Empleado eliminado del sistema.\n";
            return;
        }
    }
    std::cout << "-> Error: No existe el ID " << idBuscar << "\n";
}

void generarReporte(const std::vector<Empleado>& nomina) {
    std::cout << "\n--- REPORTE FINAL DE NOMINA ---\n";
    double totalGasto = 0;
    for (size_t i = 0; i < nomina.size(); i++) {
        totalGasto += nomina[i].salario;
    }
    std::cout << "Total de empleados registrados: " << nomina.size() << "\n";
    std::cout << "Gasto mensual total en salarios: $" << totalGasto << "\n";
}
