#include <iostream>
#include <string>

// --- FUNCIONES ---

// Muestra los puestos del aula y quién los ocupa
void mostrar(std::string aula[], int tamanoActual) {
    if (tamanoActual == 0) {
        std::cout << "El aula esta vacia." << std::endl;
        return;
    }
    
    for (int i = 0; i < tamanoActual; i++) {
        // Usamos i + 1 para que los puestos se enumeren desde el 1 en adelante
        std::cout << "Puesto " << (i + 1) << ": [ " << aula[i] << " ]" << std::endl;
    }
}

// Busca a un estudiante por su nombre y retorna en qué índice está
int buscar(std::string aula[], int n, std::string estudiante) {
    for(int i = 0; i < n; i++) {
        if(aula[i] == estudiante) {
            return i; 
        }
    }
    return -1; 
}

// Inserta a un estudiante en un puesto específico, desplazando a los demás
void insertar(std::string aula[], int &tamanoActual, int capacidad, std::string estudiante, int pos) {
    if (tamanoActual >= capacidad) {
        std::cout << "Error: El aula esta llena. No hay mas puestos." << std::endl;
        return;
    }
    if (pos < 0 || pos > tamanoActual) {
        std::cout << "Error: El puesto indicado es invalido." << std::endl;
        return;
    }
    
    // Desplazar a los estudiantes hacia atrás para hacer espacio
    for (int i = tamanoActual; i > pos; i--) {
        aula[i] = aula[i - 1];
    }
    
    // Asignar el puesto al nuevo estudiante
    aula[pos] = estudiante;
    tamanoActual++;
}

// Elimina a un estudiante de un puesto, adelantando a los que están detrás
void eliminar(std::string aula[], int &tamanoActual, int pos) {
    if (tamanoActual <= 0) {
        std::cout << "Error: El aula ya esta vacia." << std::endl;
        return;
    }
    if (pos < 0 || pos >= tamanoActual) {
        std::cout << "Error: El puesto indicado no existe." << std::endl;
        return;
    }
    
    // Desplazar a los estudiantes hacia adelante para llenar el espacio vacío
    for (int i = pos; i < tamanoActual - 1; i++) {
        aula[i] = aula[i + 1];
    }
    
    tamanoActual--;
}

// --- MAIN ÚNICO ---

int main(int argc, char** argv) {
    const int CAPACIDAD_AULA = 10;
    // Arreglo de strings para guardar nombres en lugar de números
    std::string puestos[CAPACIDAD_AULA] = {"Ana", "Carlos", "Beatriz"};
    int ocupacionActual = 3; // Hay 3 estudiantes actualmente

    std::cout << "--- ESTADO INICIAL DEL AULA ---" << std::endl;
    mostrar(puestos, ocupacionActual);

    // 1. Probando BUSCAR
    std::cout << "\n--- BUSQUEDA DE ESTUDIANTE ---" << std::endl;
    std::string aBuscar = "Carlos";
    int indice = buscar(puestos, ocupacionActual, aBuscar);
    std::cout << "Buscando a " << aBuscar << "..." << std::endl;
    if(indice != -1) {
        // Le sumamos 1 al índice para mostrar el número de puesto real al usuario
        std::cout << aBuscar << " esta sentado en el Puesto " << (indice + 1) << std::endl;
    } else {
        std::cout << "El estudiante no se encuentra en el aula." << std::endl;
    }

    // 2. Probando INSERTAR
    std::cout << "\n--- INSERCION (NUEVO ESTUDIANTE) ---" << std::endl;
    std::cout << "Sentando a 'David' en el Puesto 2 (indice 1)..." << std::endl;
    // Pasamos el índice 1, que equivale al Puesto 2
    insertar(puestos, ocupacionActual, CAPACIDAD_AULA, "David", 1);
    mostrar(puestos, ocupacionActual);

    // 3. Probando ELIMINAR
    std::cout << "\n--- ELIMINACION (ESTUDIANTE SE RETIRA) ---" << std::endl;
    std::cout << "Retirando al estudiante del Puesto 3 (indice 2, que es Carlos)..." << std::endl;
    eliminar(puestos, ocupacionActual, 2);
    mostrar(puestos, ocupacionActual);

    std::cout << "\n--- ESTADO FINAL DEL AULA ---" << std::endl;
    mostrar(puestos, ocupacionActual);

    return 0;
} 
