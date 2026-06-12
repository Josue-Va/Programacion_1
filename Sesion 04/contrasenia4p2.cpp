#include <iostream>
using namespace std;

int main() {
    string clave = "123456", clave2;

    do{
        cout << "Digite la contraseña : " ; cin >> clave2;
        if (clave2 != "123456")
        cout << "No es la contraseña correcta !!!!"<<endl;
        

    }while(clave2 != "123456");

    cout << "Acceso autorizado" << endl;

    return 0;
}