#include <iostream>
using namespace std;

int main() {
    double saldo = 500.00;
    int opcion;
    double monto;
    
    cout <<endl;
    cout << "CAJERO AUTOMATICO" << endl;
    cout <<endl;
    
    do {
        cout << "- OPCIONES"<<endl;
        cout << "1. Ver saldo" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Retirar" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout <<endl;
        
        if (opcion == 1) {
            cout << "Saldo: $" << saldo <<  endl;
            cout <<endl;
        }
        else if (opcion == 2) {
            cout << "Monto a depositar: $";
            cin >> monto;
            if (monto > 0) {
                saldo = saldo + monto;
                cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
            } else {
                cout << "Monto invalido" << endl;
            }
        }
        else if (opcion == 3) {
            cout << "Monto a retirar: $";
            cin >> monto;
            if (monto > 0 && monto <= saldo) {
                saldo = saldo - monto;
                cout << "Retiro su dinero. Nuevo saldo: $" << saldo << endl;
            } else {
                cout << "Saldo insuficiente o monto invalido" << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Gracias por usar el cajero" << endl;
            cout << endl;
        }
        else {
            cout << "Opcion invalida" << endl;
        }
        
    } while(opcion != 4);
    
    return 0;
}