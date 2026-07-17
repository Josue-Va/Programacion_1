#include <iostream>
using namespace std;

int main() {
    int anio = 2024;

    // Regla: (Divisible entre 400) o (Divisible entre 4 y NO divisible entre 100)
    if ((anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0)) {
        cout << "El año " << anio << " es BISIESTO." << endl;
    } else {
        cout << "El año " << anio << " NO es bisiesto." << endl;
    }

    return 0;
}