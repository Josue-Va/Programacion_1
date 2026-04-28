#include <iostream>
using namespace std;

int main() {
    float num1, num2, resultado;
    int opcion;
    
    do {
        // Mostrar menú
        cout << "\n\n";
        cout << "     CALCULADORA       \n";
        cout << "\n";
        cout << "  1. Sumar (+)         \n";
        cout << "  2. Restar (-)        \n";
        cout << "  3. Multiplicar (*)   \n";
        cout << "  4. Dividir (/)       \n";
        cout << "  5. Salir             \n";
        cout << "\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        
        // Validar opción
        if(cin.fail() || (opcion < 1 || opcion > 5)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nOpcion no valida. Intenta de nuevo.\n";
            continue;
        }
        
        // Salir del programa
        if(opcion == 5) {
            cout << "\nSaliendo...\n";
            break;
        }
        
        // Pedir números
        cout << "\nIngresa el primer numero: ";
        cin >> num1;
        
        cout << "Ingresa el segundo numero: ";
        cin >> num2;
        
        // Realizar operación
        cout << "\n--- RESULTADO ---\n";
        
        switch(opcion) {
            case 1:  // Sumar
                resultado = num1 + num2;
                cout << num1 << " + " << num2 << " = " << resultado << endl;
                break;
                
            case 2:  // Restar
                resultado = num1 - num2;
                cout << num1 << " - " << num2 << " = " << resultado << endl;
                break;
                
            case 3:  // Multiplicar
                resultado = num1 * num2;
                cout << num1 << " * " << num2 << " = " << resultado << endl;
                break;
                
            case 4:  // Dividir
                if(num2 == 0) {
                    cout << "ERROR: No se puede dividir entre cero" << endl;
                } else {
                    resultado = num1 / num2;
                    cout << num1 << " / " << num2 << " = " << resultado << endl;
                }
                break;
        }
        
    } while(opcion != 5);
    
    return 0;
}