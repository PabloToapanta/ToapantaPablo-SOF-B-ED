#include <iostream>

// --- FUNCIONES ---

// Muestra el contenido actual del arreglo
void mostrar(int arreglo[], int tamanoActual) {
    if (tamanoActual == 0) {
        std::cout << "El arreglo esta vacio." << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < tamanoActual; i++) {
        std::cout << arreglo[i] << (i < tamanoActual - 1 ? ", " : "");
    }
    std::cout << " ]" << std::endl;
}

// Busca un valor y retorna su índice
int buscar(int arreglo[], int n, int valor) {
    for(int i = 0; i < n; i++) {
        if(arreglo[i] == valor) {
            return i; 
        }
    }
    return -1; 
}

// Inserta un valor en una posición desplazando los demás
void insertar(int arreglo[], int &tamanoActual, int capacidad, int valor, int pos) {
    if (tamanoActual >= capacidad) {
        std::cout << "Error: Arreglo lleno" << std::endl;
        return;
    }
    if (pos < 0 || pos > tamanoActual) {
        std::cout << "Error: Posicion invalida" << std::endl;
        return;
    }
    for (int i = tamanoActual; i > pos; i--) {
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[pos] = valor;
    tamanoActual++;
}

// Elimina un valor en una posición desplazando los demás hacia la izquierda
void eliminar(int arreglo[], int &tamanoActual, int pos) {
    if (tamanoActual <= 0) {
        std::cout << "Error: El arreglo esta vacio." << std::endl;
        return;
    }
    if (pos < 0 || pos >= tamanoActual) {
        std::cout << "Error: Posicion invalida." << std::endl;
        return;
    }
    for (int i = pos; i < tamanoActual - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    tamanoActual--;
}

// --- MAIN ÚNICO ---

int main(int argc, char** argv) {
    const int CAPACIDAD = 10;
    int notas[CAPACIDAD] = {12, 18, 25};
    int tamano = 3;

    std::cout << "--- ESTADO INICIAL ---" << std::endl;
    mostrar(notas, tamano);

    // 1. Probando BUSCAR
    std::cout << "\n--- BUSQUEDA ---" << std::endl;
    int valorBusqueda = 18;
    int indice = buscar(notas, tamano, valorBusqueda);
    std::cout << "Buscando el numero " << valorBusqueda << "..." << std::endl;
    if(indice != -1) 
        std::cout << "Encontrado en el indice: " << indice << std::endl;
    else 
        std::cout << "No se encontro el valor." << std::endl;

    // 2. Probando INSERTAR
    std::cout << "\n--- INSERCION ---" << std::endl;
    std::cout << "Insertando el numero 20 en la posicion 1..." << std::endl;
    insertar(notas, tamano, CAPACIDAD, 20, 1);
    mostrar(notas, tamano);

    // 3. Probando ELIMINAR
    std::cout << "\n--- ELIMINACION ---" << std::endl;
    std::cout << "Eliminando el elemento en la posicion 2 (el 18)..." << std::endl;
    eliminar(notas, tamano, 2);
    mostrar(notas, tamano);

    std::cout << "\n--- ESTADO FINAL ---" << std::endl;
    mostrar(notas, tamano);

    return 0;
}
