#include <iostream>
using namespace std;

int main() {
    int numero;

    cout <<endl;
    cout << "Ingrese un numero del 1 al 99: ";
    cin >> numero;
    
    // Rangos de para validación básica
    if (numero < 1 || numero > 99) {
        cout << "Numero invalido. Debe ser entre 1 y 99." << endl;
        return 1;
    }
    
    // Generar tabla de multiplicar
    cout << "\nTabla de multiplicar del :" << numero << ":" << endl;
    cout << "-----------------------" << endl;
    
    // codigo para generar el codigo
    for (int i = 1; i <= 13; i++) {
        cout << numero << " x " << i << " = " << numero * i << endl;
    }
    cout <<endl;
    return 0;
}