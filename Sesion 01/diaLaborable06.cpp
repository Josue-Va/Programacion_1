#include <iostream>
using namespace std;

int main() {
    int numero;
    
    // Solicitar el número al usuario
    cout << "Ingrese un numero del 1 al 7: ";
    cin >> numero;
    
    // Validar rango
    if (numero >= 1 && numero <= 7) {
        
        // Usar if-else para determinar el día
        if (numero == 1) {
            cout << "Lunes -> Laborable" << endl;
        }
        else if (numero == 2) {
            cout << "Martes -> Laborable" << endl;
        }
        else if (numero == 3) {
            cout << "Miercoles -> Laborable" << endl;
        }
        else if (numero == 4) {
            cout << "Jueves -> Laborable" << endl;
        }
        else if (numero == 5) {
            cout << "Viernes -> Laborable" << endl;
        }
        else if (numero == 6) {
            cout << "Sabado -> No laborable" << endl;
        }
        else if (numero == 7) {
            cout << "Domingo -> No laborable" << endl;
        }
    }
    else {
        cout << "Error: El numero debe estar entre 1 y 7." << endl;
    }
    
    return 0;
}