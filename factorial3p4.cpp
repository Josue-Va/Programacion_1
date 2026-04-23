#include <iostream>
using namespace std;

int main() {
    int numero;
    long long factorial = 1;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    // Calcular factorial
    for (int i = 1; i <= numero; i++) {
        factorial = factorial * i;
    }
    cout << endl;
    cout << "- El factorial de " << numero << " es: " << factorial << endl;
    cout << endl;
    
    return 0;
}