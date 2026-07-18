#include <iostream>
#include <string>
#include <limits>   // para limpiar el buffer de entrada

using namespace std;

const int MAX_INTENTOS = 3;

// Función que valida la contraseña ingresada contra la clave actual
bool validarClave(const string& claveActual) {
    string entrada;
    int intentos = 0;

    while (intentos < MAX_INTENTOS) {
        cout << "Ingrese la contrasenia (" << (MAX_INTENTOS - intentos) << " intentos restantes): ";
        getline(cin, entrada);  // permite espacios en la contraseña

        if (entrada == claveActual) {
            cout << "✅ Acceso autorizado.\n";
            return true;
        } else {
            intentos++;
            cout << " Contrasenia incorrecta.\n";
        }
    }

    cout << " Número mximo de intentos superado. Acceso denegado.\n";
    return false;
}

// Función para cambiar la contraseña (solicita la nueva dos veces para confirmar)
void cambiarClave(string& claveActual) {
    string nueva, confirmacion;
    cout << "\n--- Cambio de contrasenia ---\n";
    cout << "Ingrese la nueva contrasenia: ";
    getline(cin, nueva);
    cout << "Confirme la nueva contraseña: ";
    getline(cin, confirmacion);

    if (nueva == confirmacion && !nueva.empty()) {
        claveActual = nueva;
        cout << " Contraseña cambiada exitosamente.\n";
    } else {
        cout << " Las contrasenias no coinciden o estan vacias. No se realizo el cambio.\n";
    }
}

int main() {
    string clave = "123456";  // clave inicial

    cout << "=== SISTEMA DE AUTENTICACION ===\n";

    // Validar acceso
    if (validarClave(clave)) {
        // Una vez dentro, ofrecer cambiar la contraseña
        char opcion;
        cout << "\n¿Desea cambiar la contraseña? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // limpiar el buffer

        if (opcion == 's' || opcion == 'S') {
            cambiarClave(clave);
        }

        cout << "\nSesión finalizada. Gracias.\n";
    }

    return 0;
}