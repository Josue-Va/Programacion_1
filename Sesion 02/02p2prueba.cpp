#include <iostream>
using namespace std;

int main() {
    double nota = 85.0;
    double asistencia = 80.0;

    if (nota >= 60.0 && asistencia >= 75.0) {
        cout << "Estado: APROBADO (Nota y asistencia suficientes)." << endl;
    } else {
        cout << "Estado: REPROBADO (Falta nota o asistencia)." << endl;
    }

    return 0;
}