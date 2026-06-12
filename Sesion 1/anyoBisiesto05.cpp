#include <iostream>
using namespace std;

int main() {
    int año;
    
    cout << "=== DETERMINADOR DE AÑOS BISIESTO ===" << endl;
    cout << "Ingresa un año: ";
    cin >> año;
    
    // Validación de entrada
    while(cin.fail()) {
        cin.clear();
        cin.ignore(24, '\n');
        cout << "Error: Debes ingresar un numero valido." << endl;
        cout << "Ingresa un año: ";
        cin >> año;
    }
    
    // Lógica para determinar si es bisiesto
    if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) {
        cout << "\nEl año " << año << " ES bisiesto." << endl;
    } else {
        cout << "\nEl año " << año << " NO es bisiesto." << endl;
    }
    
    return 0;
}