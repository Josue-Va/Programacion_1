#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int notas[4];
};

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.notas[0] = 14;
    estudiante1.notas[1] = 16;
    estudiante1.notas[2] = 12;
    estudiante1.notas[3] = 18;

    int suma = 0;
    for (int i = 0; i < 4; i++) {
        suma += estudiante1.notas[i];
    }

    float promedio = (float)suma / 4;

    cout << "Estudiante: " << estudiante1.nombre << endl;
    cout << "Suma de notas: " << suma << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}