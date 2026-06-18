/*
programa que registra vendas diarias de una tienda durante 30 dias.  permite registrar
 las ventas, calcular el promedio de ventas,
 contar que dias tuvieron las mayores ventas, mostrar los resultados obtenidos.
*/

#include <iostream>
using namespace std;

int main() {
    const int DIAS = 30;
    double ventas[DIAS];
    double suma = 0.0;
    double mayorVenta;
    int contadorMayores = 0;

    // Registrar las ventas de cada día
    cout << "Registro de ventas diarias durante " << DIAS << " dias\n";
    for (int i = 0; i < DIAS; i++) {
        cout << "Ingrese ventas del dia " << i + 1 << ": ";
        cin >> ventas[i];
        suma += ventas[i];
    }

    // Calcular el promedio
    double promedio = suma / DIAS;

    // Encontrar la mayor venta
    mayorVenta = ventas[0];
    for (int i = 1; i < DIAS; i++) {
        if (ventas[i] > mayorVenta) {
            mayorVenta = ventas[i];
        }
    }

    // Contar cuántos días tuvieron la mayor venta
    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] == mayorVenta) {
            contadorMayores++;
        }
    }

    // Mostrar resultados
    cout << "\n--- RESULTADOS ---\n";
    cout << "Ventas por dia:\n";
    for (int i = 0; i < DIAS; i++) {
        cout << "Dia " << i + 1 << ": " << ventas[i] << endl;
    }

    cout << "\nPromedio de ventas: " << promedio << endl;
    cout << "Mayor venta registrada: " << mayorVenta << endl;
    cout << "Cantidad de dias con la mayor venta: " << contadorMayores << endl;

    if (contadorMayores > 0) {
        cout << "Dias con mayores ventas: dia ";
        for (int i = 0; i < DIAS; i++) {
            if (ventas[i] == mayorVenta) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}