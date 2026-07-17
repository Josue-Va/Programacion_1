#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main() {
    tuple<int, string, double> estudiante;
    estudiante = make_tuple(1, "Pedro", 14);

    tuple<int, string, double> estudiante2(2, "Carlos", 15.4);

    cout << get<0>(estudiante) << endl;   // Muestra el ID 1
    cout << get<0>(estudiante2) << endl;  // Muestra el ID 2
    cout << get<1>(estudiante) << endl;   // Muestra el nombre: Pedro

    get<0>(estudiante) = 24;              // Modifica el primer elemento
    cout << get<0>(estudiante) << endl;   // Muestra 24

    return 0;
}