#include <iostream>
using namespace std;

int main() {
    int numero = 15;

    if (numero >= 10 && numero <= 20) {
        cout << "El numero " << numero << " esta dentro del rango 10-20." << endl;
    } else {
        cout << "El numero " << numero << " esta fuera del rango." << endl;
    }

    return 0;
}