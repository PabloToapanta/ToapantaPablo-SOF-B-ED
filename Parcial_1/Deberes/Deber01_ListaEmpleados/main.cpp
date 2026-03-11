#include <iostream>
#include <iostream>
#include <vector>
#include "Empleado.h"
#include "OperacionesEmpleado.h"

// Inicialización del ID
int Empleado::contador_id = 1;

int main() {
    std::vector<Empleado> nominaEmpresa;
    
    std::cout << "Cargando sistema...\n";
    cargarDatosIniciales(nominaEmpresa);

    int opcion;
    do {
        std::cout << "\n====== MENU PRINCIPAL ======\n";
        std::cout << "1. Mostrar todos los registros\n";
        std::cout << "2. Registrar nuevo empleado\n";
        std::cout << "3. Buscar empleado por ID\n";
        std::cout << "4. Modificar registro (Salario)\n";
        std::cout << "5. Eliminar registro\n";
        std::cout << "6. Generar reporte final\n";
        std::cout << "7. Salir del sistema\n";
        std::cout << "============================\n";
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1: mostrarEmpleados(nominaEmpresa); break;
            case 2: registrarEmpleado(nominaEmpresa); break;
            case 3: buscarEmpleado(nominaEmpresa); break;
            case 4: modificarEmpleado(nominaEmpresa); break;
            case 5: eliminarEmpleado(nominaEmpresa); break;
            case 6: generarReporte(nominaEmpresa); break;
            case 7: std::cout << "Saliendo... Hasta luego.\n"; break;
            default: std::cout << "-> Error: Opcion no valida.\n"; break;
        }
    } while (opcion != 7);

    return 0;
}
