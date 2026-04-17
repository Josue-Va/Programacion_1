#include <iostream>
using namespace std;

int main() {
    double lado1, lado2, lado3;
    
    // Solicitar los tres lados del triángulo
    cout << "Ingrese la longitud del primer lado: ";
    cin >> lado1;
    cout << "Ingrese la longitud del segundo lado: ";
    cin >> lado2;
    cout << "Ingrese la longitud del tercer lado: ";
    cin >> lado3;
    
    // Verificar si los lados forman un triángulo válido
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        // Clasificar el triángulo
        if (lado1 == lado2 && lado2 == lado3) {
            cout << "El triángulo es EQUILÁTERO (todos los lados iguales)." << endl;
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            cout << "El triángulo es ISÓSCELES (dos lados iguales)." << endl;
        }
        else {
            cout << "El triángulo es ESCALENO (todos los lados diferentes)." << endl;
        }
    }
    else {
        cout << "Los lados ingresados NO forman un triángulo válido." << endl;
    }
    
    return 0;
}