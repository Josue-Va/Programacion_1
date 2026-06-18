#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    float acumulado = 0;
    int opcion;
    bool primeraOperacion = true;

    do {
        // Mostrar menú
        cout << "\n\n";
        cout << "   . CALCULADORA .      \n";
        cout << "   Acumulado actual: " << acumulado << "\n";
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

        if(opcion == 5) {
            break;
        }

        // Pedir los dos números para la operación actual
        cout << "\nIngresa el primer numero: ";
        cin >> num1;
        cout << "Ingresa el segundo numero: ";
        cin >> num2;

        float resultadoOperacion;  // resultado de num1 (operación) num2
        bool error = false;

        // Calcular el resultado de la operación actual (sin afectar aún el acumulado)
        switch(opcion) {
            case 1:
                resultadoOperacion = num1 + num2;
                break;
            case 2:
                resultadoOperacion = num1 - num2;
                break;
            case 3:
                resultadoOperacion = num1 * num2;
                break;
            case 4:
                if(num2 == 0) {
                    cout << "ERROR: No se puede dividir entre cero. Operacion cancelada.\n";
                    error = true;
                } else {
                    resultadoOperacion = num1 / num2;
                }
                break;
        }

        if(error) continue;  // si hay error en división, no se actualiza el acumulado

        // Mostrar el resultado de la operación actual
        cout << "\n--- RESULTADO DE LA OPERACION ---\n";
        switch(opcion) {
            case 1: cout << num1 << " + " << num2 << " = " << resultadoOperacion << endl; break;
            case 2: cout << num1 << " - " << num2 << " = " << resultadoOperacion << endl; break;
            case 3: cout << num1 << " * " << num2 << " = " << resultadoOperacion << endl; break;
            case 4: cout << num1 << " / " << num2 << " = " << resultadoOperacion << endl; break;
        }

        // Se actualiza el resultado acumulado aplicando la misma operación del ultimo primer resultado
        if(primeraOperacion) {
            acumulado = resultadoOperacion;
            primeraOperacion = false;
        } else {
            switch(opcion) {
                case 1:
                    acumulado = acumulado + resultadoOperacion;
                    cout << "\nAcumulado: " << acumulado - resultadoOperacion << " + " << resultadoOperacion << " = " << acumulado << endl;
                    break;
                case 2:
                    acumulado = acumulado - resultadoOperacion;
                    cout << "\nAcumulado: " << acumulado + resultadoOperacion << " - " << resultadoOperacion << " = " << acumulado << endl;
                    break;
                case 3:
                    acumulado = acumulado * resultadoOperacion;
                    cout << "\nAcumulado: " << acumulado / resultadoOperacion << " * " << resultadoOperacion << " = " << acumulado << endl;
                    break;
                case 4:
                    acumulado = acumulado / resultadoOperacion;
                    cout << "\nAcumulado: " << acumulado * resultadoOperacion << " / " << resultadoOperacion << " = " << acumulado << endl;
                    break;
            }
        }

    } while(opcion != 5);

    cout << "\n RESULTADO ACUMULADO FINAL \n";
    cout << "Resultado: " << acumulado << endl;
    cout << "Saliendo...\n";
    return 0;
}