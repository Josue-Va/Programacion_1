#include <iostream>
#include <map>      // Para el diccionario asocia.
#include <stack>    // LIFO)
#include <queue>    // FIFO)
#include <string>   
using namespace std;

int main() {
    // --- DICCIONARIOS (map) ---
    // Un map asocia una clave con un valor. Aquí la clave es el código del producto.
    map<int, string> productos;   // Código -> nombre del producto
    map<int, int> stock;          // Código -> cantidad disponible

    // La pila guarda las ventas en orden inverso. Es útil para mostrar "últimas ventas" 
    stack<string> ventas;

    // La cola guarda los pedidos de reabastecimiento en orden. Se procesan en orden FIFO 
    queue<pair<int, int>> pedidos;

    // ARREGLO
    // Un arreglo simple de strings con categorías fijas (solo para mostrar un ejemplo).
    string categorias[3] = {"Basicos", "Limpieza", "Alimentos"};

    int opcion;
    do {
        // Menú principal
        cout << "\n=== INVENTARIO SIMPLE ===\n";
        cout << "1. Agregar producto\n2. Vender\n3. Reabastecer (encolar)\n";
        cout << "4. Mostrar inventario\n5. Ultimas ventas (pila)\n";
        cout << "6. Procesar reabastecimientos (cola)\n7. Ver categorias\n8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // Opción 1: Agregar un nuevo producto
        if (opcion == 1) {
            int cod, cant;
            string nom;
            cout << "Codigo: "; cin >> cod;
            // Verificar si ya existe un producto con ese código
            if (productos.count(cod)) {
                cout << "Ya existe.\n";
            } else {
                cout << "Nombre: "; cin >> nom;
                cout << "Stock inicial: "; cin >> cant;
                // Guardar en los dos diccionarios
                productos[cod] = nom;
                stock[cod] = cant;
                cout << "Producto agregado.\n";
            }
        }
        // Opción 2: Vender (reduce stock y apila la venta)
        else if (opcion == 2) {
            int cod, cant;
            cout << "Codigo: "; cin >> cod;
            if (!productos.count(cod)) {
                cout << "No existe.\n";
            } else {
                cout << "Cantidad a vender: "; cin >> cant;
                if (stock[cod] >= cant) {
                    stock[cod] -= cant;   // Restar del stock
                    // Crear mensaje de venta y apilarlo (push en la pila)
                    ventas.push("Venta: " + to_string(cant) + " de " + productos[cod]);
                    cout << "Vendido. Stock actual: " << stock[cod] << endl;
                } else {
                    cout << "Stock insuficiente.\n";
                }
            }
        }
        // Opción 3: Reabastecer (encolar un pedido)
        else if (opcion == 3) {
            int cod, cant;
            cout << "Codigo: "; cin >> cod;
            if (!productos.count(cod)) {
                cout << "Producto no existe.\n";
            } else {
                cout << "Cantidad a pedir: "; cin >> cant;
                // Encolar el pedido (código y cantidad)
                pedidos.push({cod, cant});
                cout << "Pedido encolado.\n";
            }
        }
        // Opción 4: Mostrar inventario (recorrer los diccionarios)
        else if (opcion == 4) {
            cout << "\n--- INVENTARIO ---\n";
            // Recorrer el map de productos (cada elemento es un par clave-valor)
            for (auto& p : productos) {
                int codigo = p.first;
                string nombre = p.second;
                int cantidad = stock[codigo];
                cout << codigo << " - " << nombre << " : " << cantidad << " unidades\n";
            }
        }
        // Opción 5: Mostrar últimas ventas (desapilar la pila, pero sin perderla)
        else if (opcion == 5) {
            cout << "\n--- ULTIMAS VENTAS ---\n";
            if (ventas.empty()) {
                cout << "Sin ventas.\n";
            } else {
                // Hacemos una copia de la pila para no destruir la original
                stack<string> temp = ventas;
                // La pila muestra desde el tope (venta más reciente) hasta el fondo
                while (!temp.empty()) {
                    cout << temp.top() << endl;  // top() es el último elemento apilado
                    temp.pop();                  // elimina el tope de la copia
                }
            }
        }
        // Opción 6: Procesar reabastecimientos (vaciar la cola)
        else if (opcion == 6) {
            cout << "\n--- PROCESAR REABASTECIMIENTOS ---\n";
            // Mientras la cola no esté vacía, sacar el frente y actualizar stock
            while (!pedidos.empty()) {
                auto ped = pedidos.front();   // Obtener el primer pedido encolado
                int cod = ped.first;
                int cant = ped.second;
                stock[cod] += cant;           // Aumentar el stock
                cout << "Reabastecido " << productos[cod] << " +" << cant << endl;
                pedidos.pop();                // Eliminar ese pedido de la cola
            }
        }
        // Opción 7: Mostrar el arreglo de categorías
        else if (opcion == 7) {
            cout << "\nCategorias: ";
            for (int i = 0; i < 3; i++) {
                cout << categorias[i] << " ";
            }
            cout << endl;
        }
    } while (opcion != 8);  // Repetir hasta que el usuario elija Salir

    return 0;
}