#include <iostream>
#include <string>
using namespace std;

int main() {
    string usuario, pass;
    
    cout << "\n-- LOGIN --" << endl;
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Contrasenya: ";
    cin >> pass;
    
    if(usuario == "JosueV" && pass == "josuev") {
        cout << "\n¡Bienvenido al sistema!" << endl;
        cout <<endl;
    } else {
        cout << "\nAcceso denegado. Credenciales incorrectas." << endl;
        cout <<endl;
    }
    
    return 0;
}