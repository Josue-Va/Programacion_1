#include <iostream>
using namespace std;

int main() {
    const int TAM = 10;
    int numeros[TAM];
    int *ptr = numeros;  // puntero al primer elemento del arreglo

    // Leer 10 números usando aritmética de punteros
    cout << "Ingrese 10 numeros enteros:\n";
    for (int i = 0; i < TAM; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> *(ptr + i);   // equivalente a numeros[i]
    }

    // Encontrar el mayor usando punteros
    int mayor = *ptr;  // empezamos con el primer elemento
    for (int i = 1; i < TAM; i++) {
        if (*(ptr + i) > mayor) {
            mayor = *(ptr + i);
        }
    }

    cout << "\nEl numero mayor es: " << mayor << endl;
    return 0;
}