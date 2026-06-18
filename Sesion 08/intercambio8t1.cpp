#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1, num2;

    cout << "Ingrese un primer numero: ";
    cin >> num1;
    cout << "Ingrese un segundo numero: ";
    cin >> num2;

    // Mostrar valores originales (no direcciones de memoria)
    cout << "Valor del primer numero: " << num1 << endl;
    cout << "Valor del segundo numero: " << num2 << endl;

    // Intercambio de valores utilizando punteros
    int *ptr1 = &num1;  // puntero que apunta a num1
    int *ptr2 = &num2;  // puntero que apunta a num2
    int temp = *ptr1;   // guardar el valor al que apunta ptr1
    *ptr1 = *ptr2;      // asignar a ptr1 el valor de ptr2
    *ptr2 = temp;       // asignar a ptr2 el valor temporal

    // Mostrar valores después del intercambio
    cout << "\nDespues del intercambio:" << endl;
    cout << "Valor del primer numero: " << num1 << endl;
    cout << "Valor del segundo numero: " << num2 << endl;

    return 0;
}