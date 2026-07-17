#include <iostream>
using namespace std;

int main() {
    int op;
    float x, y;
    do {
        cout << "\n1.Sumar 2.Restar 3.Multiplicar 4.Dividir 5.Salir: ";
        cin >> op;
        if (op >= 1 && op <= 4) {
            cout << "Ingresa dos numeros: ";
            cin >> x >> y;
        }
        switch (op) {
            case 1: cout << "= " << x + y << endl; break;
            case 2: cout << "= " << x - y << endl; break;
            case 3: cout << "= " << x * y << endl; break;
            case 4: 
                if (y != 0) cout << "= " << x / y << endl;
                else cout << "Error: division entre cero\n";
                break;
            case 5: cout << "Adios\n"; break;
            default: cout << "Opción no valida\n";
        }
    } while (op != 5);
    return 0;
}