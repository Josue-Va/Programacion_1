#include <iostream>
#include <string>
using namespace std;

int main() {
    int numero;

    cout<< "Ingrese el valor de un numero"; cin >>numero;

    cout << "El valor del numero es : " <<numero<<endl;
    cout << "La direccion del numero es : " <<&numero<<endl;

    int *p  = &numero;
     cout << "El valor del numero es : " <<numero<<endl;
    cout << "La direccion del numero es : " <<&numero<<endl;


 }