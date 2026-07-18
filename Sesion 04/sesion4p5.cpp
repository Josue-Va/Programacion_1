#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre, apellido, respuesta;

    do {
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Apellido: ";
        getline(cin, apellido);

        cout << "\nConfirmar datos:\n";
        cout << "Nombre: " << nombre << "\nApellido: " << apellido << "\n";
        cout << " Correctos ? (s/n): ";
        cin >> respuesta;
        cin.ignore(); // limpiar buffer

        if (respuesta != "s" && respuesta != "S")
            cout << "Vuelva a ingresar.\n\n";
    } while (respuesta != "s" && respuesta != "S");

    cout << "\nRegistro completado. Bienvenido!\n";
    return 0;
}