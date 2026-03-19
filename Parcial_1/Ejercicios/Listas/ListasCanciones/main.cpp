#include <iostream>
#include <string>

using namespace std;

// Clase Cancion que actúa como el nodo
class Cancion {
public:
    string titulo;
    string artista;
    Cancion* next;
    Cancion* prev;

    // Constructor
    Cancion(string t, string a) {
        titulo = t;
        artista = a;
        next = 0; // Usando 0 por compatibilidad con tu compilador
        prev = 0;
    }
};

// Clase Playlist que maneja la lista doblemente enlazada
class Playlist {
private:
    Cancion* head;
    Cancion* tail;
    Cancion* actual; // Puntero a la canción "reproduciéndose" actualmente

public:
    Playlist() {
        head = 0;
        tail = 0;
        actual = 0;
    }

    // Destructor estricto para liberar la memoria
    ~Playlist() {
        Cancion* temp = head;
        Cancion* siguiente = 0;
        while (temp != 0) {
            siguiente = temp->next;
            delete temp;
            temp = siguiente;
        }
    }

    void agregarFinal(string titulo, string artista) {
        Cancion* nueva = new Cancion(titulo, artista);
        
        if (head == 0) { // Si la lista está vacía
            head = nueva;
            tail = nueva;
            actual = nueva; // La primera canción agregada pasa a ser la "actual"
        } else {
            tail->next = nueva;
            nueva->prev = tail;
            tail = nueva;
        }
        cout << "-> Cancion agregada exitosamente.\n";
    }

    // Método auxiliar para mover el puntero 'actual' y probar la inserción en medio
    void fijarActual(string tituloBusqueda) {
        Cancion* temp = head;
        while (temp != 0) {
            if (temp->titulo == tituloBusqueda) {
                actual = temp;
                cout << "-> La cancion actual ahora es: " << actual->titulo << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "-> Error: No se encontro la cancion en la playlist.\n";
    }

    void insertarDespuesActual(string titulo, string artista) {
        if (actual == 0) {
            cout << "-> Error: La playlist esta vacia, no hay cancion actual.\n";
            return;
        }

        Cancion* nueva = new Cancion(titulo, artista);
        Cancion* siguiente = actual->next;

        // Conectar el nuevo nodo con el nodo 'actual'
        nueva->prev = actual;
        nueva->next = siguiente;
        actual->next = nueva;

        // Conectar el nodo 'siguiente' (si existe) con el nuevo nodo
        if (siguiente != 0) {
            siguiente->prev = nueva;
        } else {
            // Si estábamos en la última canción, el tail debe actualizarse
            tail = nueva;
        }
        cout << "-> Cancion insertada despues de '" << actual->titulo << "'.\n";
    }

    void mostrarInicioFin() {
        if (head == 0) {
            cout << "-> La playlist esta vacia.\n";
            return;
        }
        Cancion* temp = head;
        cout << "\n--- PLAYLIST (INICIO A FIN) ---\n";
        while (temp != 0) {
            // Ponemos un marcador visual (>>>) para saber cuál es la canción actual
            cout << (temp == actual ? " >>> " : "     ");
            cout << temp->titulo << " - " << temp->artista << "\n";
            temp = temp->next;
        }
        cout << "-------------------------------\n";
    }

    void mostrarFinInicio() {
        if (tail == 0) {
            cout << "-> La playlist esta vacia.\n";
            return;
        }
        Cancion* temp = tail;
        cout << "\n--- PLAYLIST (FIN A INICIO) ---\n";
        while (temp != 0) {
            cout << (temp == actual ? " >>> " : "     ");
            cout << temp->titulo << " - " << temp->artista << "\n";
            temp = temp->prev;
        }
        cout << "-------------------------------\n";
    }
};

int main() {
    Playlist miPlaylist;
    int opcion;
    string titulo, artista;

    do {
        cout << "\n=== MENU SPOTIFY C++ ===\n";
        cout << "1. Agregar cancion al final\n";
        cout << "2. Insertar cancion despues de la actual\n";
        cout << "3. Mostrar playlist (Inicio a Fin)\n";
        cout << "4. Mostrar playlist (Fin a Inicio)\n";
        cout << "5. Cambiar cancion actual (Buscar por titulo)\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Limpiamos el buffer del cin. Esto es OBLIGATORIO en C++ antes de usar getline
        // si previamente leíste un número con cin >>, de lo contrario se saltará la lectura.
        cin.ignore(10000, '\n'); 

        switch (opcion) {
            case 1:
                cout << "Titulo de la cancion: ";
                getline(cin, titulo);
                cout << "Artista: ";
                getline(cin, artista);
                miPlaylist.agregarFinal(titulo, artista);
                break;
            case 2:
                cout << "Titulo de la nueva cancion: ";
                getline(cin, titulo);
                cout << "Artista: ";
                getline(cin, artista);
                miPlaylist.insertarDespuesActual(titulo, artista);
                break;
            case 3:
                miPlaylist.mostrarInicioFin();
                break;
            case 4:
                miPlaylist.mostrarFinInicio();
                break;
            case 5:
                cout << "Ingrese el titulo de la cancion que desea establecer como actual: ";
                getline(cin, titulo);
                miPlaylist.fijarActual(titulo);
                break;
            case 6:
                cout << "Cerrando reproductor...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
