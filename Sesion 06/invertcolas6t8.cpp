#include <iostream>
#include <stack>    // Para usar la pila (LIFO)
#include <queue>    // Para usar la cola (FIFO)
using namespace std;

// Función para imprimir el contenido de una cola (sin modificarla)
// Se pasa por valor para trabajar con una copia y no vaciar la original
void imprimirCola(queue<int> cola) {
    cout << "[ ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << "]" << endl;
}

int main() {
    // Declarar una cola de enteros
    queue<int> cola;
    // Declarar una pila auxiliar para la inversión
    stack<int> pila_aux;

    // Agregar elementos a la cola (en orden: 12, 13, 14, 15)
    cola.push(12);
    cola.push(13);
    cola.push(14);
    cola.push(15);   // Agregamos un cuarto para ver mejor la inversión

    cout << "=== COLA ORIGINAL ===" << endl;
    cout << "Contenido (frente a la izquierda): ";
    imprimirCola(cola);

    // --- Invertir la cola usando una pila ---
    // 1. Mover todos los elementos de la cola a la pila
    while (!cola.empty()) {
        pila_aux.push(cola.front());   // Tomamos el frente de la cola
        cola.pop();                     // Eliminamos el frente de la cola
    }

    // 2. Mover todos los elementos de la pila de vuelta a la cola
    while (!pila_aux.empty()) {
        cola.push(pila_aux.top());     // Tomamos el tope de la pila
        pila_aux.pop();                // Eliminamos el tope de la pila
    }

    cout << "\n=== COLA INVERTIDA ===" << endl;
    cout << "Contenido (frente a la izquierda): ";
    imprimirCola(cola);

    return 0;
}