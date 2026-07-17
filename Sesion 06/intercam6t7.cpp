#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> pila1, pila2;
    pila1.push(1); pila1.push(2);
    pila2.push(9); pila2.push(8); pila2.push(7);

    swap(pila1, pila2);   // Intercambio directo O(1)

    // Mostrar resultados...
    return 0;
}