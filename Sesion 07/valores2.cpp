#include <iostream>
#include <stack>   // pila (LIFO)
#include <queue>   // cola (FIFO)

using namespace std;

int main() {
    stack<int> pila;      // Pila original
    queue<int> cola;      // Cola auxiliar para invertir
    int numero;

    // Pedir 7 números al usuario y guardarlos en la pila
    cout << "Ingresa 7 numeros enteros:\n";
    for (int i = 0; i < 7; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numero;
        pila.push(numero);
    }

    // Mostrar el contenido original de la pila (desde el tope hacia abajo)
    cout << "\nPila original (tope primero):\n";
    stack<int> temp = pila; // Copia temporal para mostrar sin destruir
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // PASO 1: Vaciar la pila y encolar todos sus elementos
    while (!pila.empty()) {
        cola.push(pila.top());  // Tomamos el tope de la pila y lo metemos a la cola
        pila.pop();             // Eliminamos el tope de la pila
    }

    // PASO 2: Vaciar la cola y volver a apilar los elementos
    // se invierte el orden porque la cola los entrega en el orden inverso al que se apilarán
    while (!cola.empty()) {
        pila.push(cola.front()); // Tomamos el frente de la cola
        cola.pop();              // Eliminamos el frente de la cola
    }

    // Mostrar la pila invertida
    cout << "\nPila invertida (tope primero):\n";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;

    return 0;
}