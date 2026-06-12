#include <iostream>
using namespace std;

 
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n CALCULADORA \n";
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "3. Multiplicar\n";
    cout << "4. Dividir\n";
    cout << "5. Salir\n";
    cout << "   \n";
    cout << "Elige una opcion: ";
}

// Función para pedir un número con validación
float pedirNumero(string mensaje) {
    float numero;
    cout << mensaje;
    cin >> numero;
    
    // Verificar si el usuario ingresó un número válido
    while(cin.fail()) {
        cin.clear(); // Limpiar el error
        cin.ignore(1000, '\n'); // Ignorar entrada incorrecta
        cout << "Error: Debes ingresar un numero valido. \n";
        cout << mensaje;
        cin >> numero;
    }
    
    return numero;
}

int main() {
    float num1, num2, resultado;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        // Validar que la opción sea un número
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Opcion no valida.\n";
            continue;
        }
        
        // Salir del progrma si el usuario eligió 5
        if(opcion == 5) {
            cout << " \n";
            break;
        }
        
        // Validar que la opción esté entre 1 y 4
        if(opcion < 1 || opcion > 4) {
            cout << "Error: Opcion no valida. Elige entre 1 y 5.\n";
            continue;
        }
        
        // Pedir los dos números
        cout << "\n";
        num1 = pedirNumero("Ingresa el primer numero: ");
        num2 = pedirNumero("Ingresa el segundo numero: ");
        
        // Realizar la operación elegida
        switch(opcion) {
            case 1:
                resultado = sumar(num1, num2);
                cout << "\nResultado: " << num1 << " + " << num2 << " = " << resultado << "\n";
                break;
                
            case 2:
                resultado = restar(num1, num2);
                cout << "\nResultado: " << num1 << " - " << num2 << " = " << resultado << "\n";
                break;
                
            case 3:
                resultado = multiplicar(num1, num2);
                cout << "\nResultado: " << num1 << " x " << num2 << " = " << resultado << "\n";
                break;
                
            case 4:
                // Validar división entre cero
                if(num2 == 0) {
                    cout << "\nError: No se puede dividir entre cero!\n";
                } else {
                    resultado = dividir(num1, num2);
                    cout << "\nResultado: " << num1 << " / " << num2 << " = " << resultado << "\n";
                }
                break;
        }
        
       
    } while(opcion != 5);
    
    return 0;
}