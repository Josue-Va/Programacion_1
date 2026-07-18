#include "productos10p4.cpp"  // Incluye la clase
#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

Producto productos[MAX];
int total = 0;

void menu() {
    cout << "\n--- INVENTARIO ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar productos\n";
    cout << "3. Actualizar precio\n";
    cout << "4. Actualizar stock\n";
    cout << "5. Salir\n";
    cout << "Opción: ";
}

void agregar() {
    if (total >= MAX) {
        cout << "Límite alcanzado.\n";
        return;
    }
    productos[total].registrar(total + 1);
    total++;
    cout << "Producto agregado.\n";
}

void listar() {
    if (total == 0) {
        cout << "No hay productos.\n";
        return;
    }
    for (int i = 0; i < total; i++)
        productos[i].mostrar();
}

void actualizarPrecio() {
    int id; double nuevo;
    cout << "ID del producto: "; cin >> id;
    for (int i = 0; i < total; i++) {
        if (productos[i].getId() == id) {
            cout << "Nuevo precio: "; cin >> nuevo;
            productos[i].setPrecio(nuevo);
            cout << "Precio actualizado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void actualizarStock() {
    int id, nuevo;
    cout << "ID del producto: "; cin >> id;
    for (int i = 0; i < total; i++) {
        if (productos[i].getId() == id) {
            cout << "Nuevo stock: "; cin >> nuevo;
            productos[i].setStock(nuevo);
            cout << "Stock actualizado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

int main() {
    int op;
    do {
        menu();
        cin >> op;
        switch (op) {
            case 1: agregar(); break;
            case 2: listar(); break;
            case 3: actualizarPrecio(); break;
            case 4: actualizarStock(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (op != 5);
    return 0;
}