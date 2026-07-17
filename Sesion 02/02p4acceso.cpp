#include <iostream>
using namespace std;

int main() {
    bool usuarioLogeado = false; // Cambia a 'true' para probar el otro caso

    if (!usuarioLogeado) {
        cout << "Acceso DENEGADO. Por favor, inicia sesion primero." << endl;
    } else {
        cout << "Acceso PERMITIDO. Bienvenido al sistema." << endl;
    }

    return 0;
}