#include <iostream>
using namespace std;

int main() {
    int opcion;
    float num1, num2, resultado;

    do {
        cout << "\n.. CALCULADORA V1 ..\n";
        cout << "1. Sumar\n";
        cout << "2. Restar\n";
        cout << "3. Multiplicar\n";
        cout << "4. Dividir\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingresa dos numeros: ";cin >> num1 >> num2;
        }

        switch (opcion) {
            case 1:
                resultado = num1 + num2;
                cout << "Resultado: " << resultado << endl;
                break;
            case 2:
                resultado = num1 - num2;
                cout << "Resultado: " << resultado << endl;
                break;
            case 3:
                resultado = num1 * num2;
                cout << "Resultado: " << resultado << endl;
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    cout << "Resultado: " << resultado << endl;
                } else {
                    cout << "Error: division entre cero\n";
                }
                break;
            case 5:
                cout << "Saliendo\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
    } while (opcion != 5);

    return 0;
}