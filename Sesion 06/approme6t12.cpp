#include <iostream>
#include <map>      // diccionario
#include <tuple>    // tuplas
#include <string>   
using namespace std;

int main() {
    // Diccionario: clave = nombre del estudiante, valor = tupla con 3 notas
    map<string, tuple<int, int, int>> estudiantes;

    // Insertar estudiantes con sus calificaciones usando tuplas
    estudiantes["Ana"] = make_tuple(15, 16, 17);
    estudiantes["Luis"] = make_tuple(12, 14, 13);
    estudiantes["Maria"] = make_tuple(18, 19, 20);

    // Mostrar el promedio de cada estudiante
    cout << ".. PROMEDIO DE ESTUDIANTES ..\n";
    for (auto &[nombre, notas] : estudiantes) {
        // Obtener cada nota de la tupla
        int nota1 = get<0>(notas);
        int nota2 = get<1>(notas);
        int nota3 = get<2>(notas);

        // Calcular promedio
        double promedio = (nota1 + nota2 + nota3) / 3.0;

        // Mostrar resultado
        cout << nombre << " : " << promedio << endl;
    }

    return 0;
}