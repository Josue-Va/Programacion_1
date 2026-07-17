#include <iostream>
#include <stack>    // Para la pila (LIFO)
#include <queue>    // Para la cola auxiliar (FIFO)
using namespace std;

// Función para mostrar el contenido de una pila sin modificarla
// (se pasa por valor para trabajar con una copia)
void imprimirPila(stack<int> pila) {
    cout << "[ ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << "]" << endl;
}

int main() {
    // Declarar la pila original
    stack<int> pila_original;

    // Agregar elementos (el tope será 14)
    pila_original.push(12);
    pila_original.push(13);
    pila_original.push(14);

    cout << "=== PILA ORIGINAL (tope a la izquierda) ===" << endl;
    imprimirPila(pila_original);   // Salida: [14 13 12]

    // --- Invertir la pila usando una cola auxiliar ---
    queue<int> cola_aux;

    // 1. Mover todos los elementos de la pila a la cola
    //    (la cola guarda el orden de salida de la pila)
    while (!pila_original.empty()) {
        cola_aux.push(pila_original.top());   // encolamos el tope
        pila_original.pop();                  // lo eliminamos de la pila
    }

    // 2. Mover todos los elementos de la cola de vuelta a la pila
    //    (el orden FIFO de la cola invierte nuevamente el orden)
    while (!cola_aux.empty()) {
        pila_original.push(cola_aux.front()); // tomamos el frente de la cola
        cola_aux.pop();                       // lo eliminamos de la cola
    }

    cout << "\n=== PILA INVERTIDA (tope a la izquierda) ===" << endl;
    imprimirPila(pila_original);   // Salida: [12 13 14]

    return 0;
}