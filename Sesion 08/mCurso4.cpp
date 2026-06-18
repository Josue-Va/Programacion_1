/*
programa que administra la atención a clientes, registrar 5 cliente
mediante DNI y nombre, insertar cliente al final de la cola, atender al cliente,
mostrar el estado de la cola, indicar cuantos clientes queda. 
Utilizar opciones; Registrar cliente, atender cliente, mostrar cola, salir.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_CLIENTES = 5;

struct Cliente {
    string dni;
    string nombre;
};

// Cola circular 
Cliente cola[MAX_CLIENTES];
int frente = 0;       
int final = 0;       
int cantidad = 0;     
// Verifica si la cola está llena
bool estaLlena() {
    return cantidad == MAX_CLIENTES;
}

// Verifica si la cola está vacía
bool estaVacia() {
    return cantidad == 0;
}

// Insertar cliente al final de la cola
void registrarCliente() {
    if (estaLlena()) {
        cout << "No se puede registrar mas clientes. La cola esta llena.\n";
        return;
    }
    Cliente nuevo;
    cout << "Ingrese DNI del cliente: "; cin >> nuevo.dni;
    cout << "Ingrese nombre del cliente: "; cin >> nuevo.nombre;
    cola[final] = nuevo;
    final = (final + 1) % MAX_CLIENTES;
    cantidad++;
    cout << "Cliente registrado correctamente.\n";
}

    // Atender al primer cliente
void atenderCliente() {
    if (estaVacia()) {
        cout << "No hay clientes en espera.\n";
        return;
    }
    Cliente atendido = cola[frente];
    cout << "Atendiendo a: " << atendido.nombre << " (DNI: " << atendido.dni << ")\n";
    frente = (frente + 1) % MAX_CLIENTES;
    cantidad--;
}

       // Mostrar el estado actual de la cola
void mostrarCola() {
    if (estaVacia()) {
        cout << "La cola esta vacia.\n";
        return;
    }
    cout << "\n--- Estado de la cola (orden de atencion) ---\n";
    int idx = frente;
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << cola[idx].nombre << " (DNI: " << cola[idx].dni << ")\n";
        idx = (idx + 1) % MAX_CLIENTES;
    }
    cout << "Clientes en espera: " << cantidad << "/" << MAX_CLIENTES << "\n";
}

int main() {
    int opcion;
    do {
        cout << "\n.. MENU PRINCIPAL ..\n";
        cout << "1. Registrar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                atenderCliente();
                break;
            case 3:
                mostrarCola();
                break;
            case 4:
                cout << "Saliendo del programa . .\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}