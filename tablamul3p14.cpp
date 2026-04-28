#include <iostream>
using namespace std;

int main() {
    int numero;

    cout <<endl;
    cout << "Ingrese un numero del 1 al 99: ";
    cin >> numero;
    
    // Rangos para validación 
    if (numero < 1 || numero > 99) {
        cout << "Numero invalido. Debe ser entre 1 y 99." << endl;
        return 1;
    }
    
    // Generar tabla de multiplicar
    cout << "\nTabla de multiplicar del :" << numero << ":" << endl;
    
    // codigo para generar el codigo
    for (int i = 2; i <= 12; i++) {
        cout << numero << " x " << i << " = " << numero * i << endl;
    }
    cout <<endl;
    return 0;
}