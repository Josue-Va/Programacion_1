#include <iostream>
#include <stack>  // Para usar la pila (LIFO)
using namespace std;

int main() {
    stack<int> pila_nota;   // Declarar pila de enteros

    // Agregar elementos
    pila_nota.push(12);
    pila_nota.push(13);
    pila_nota.push(14);

    // top() muestra el elemento del tope
    cout << "Tope: " << pila_nota.top() << endl;   // 14
    pila_nota.pop();   // Elimina el tope
    cout << "Tope2: " << pila_nota.top() << endl;  // 13

    // Vaciar la pila mostrando cada elemento
    while (!pila_nota.empty()) {
        cout << "Valor pila: " << pila_nota.top() << endl;
        pila_nota.pop();   // Elimina el tope para avanzar
    }

    return 0;
}