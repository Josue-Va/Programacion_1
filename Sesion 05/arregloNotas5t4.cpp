 #include <iostream>
using namespace std;

// Variabes globales
float notas[3];
int suma = 0, mayor;
float promedio;

// Función que calcula suma, promedio y nota mayor
void calificaciones() {
    suma = 0;
    mayor = notas[0];  // inicializar con la primera nota

    for (int i = 0; i < 3; i++) {
        suma += notas[i];
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    promedio = (float)suma / 3;
}

// Funcion para ordenar y mostrar de menor a mayor
void ordenarMenorMayor() {
    float temp[3];
    // Copiar arreglo
    for (int i = 0; i < 3; i++) temp[i] = notas[i];
    // Ordenamiento burbuja simple
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (temp[i] > temp[j]) {
                float aux = temp[i];
                temp[i] = temp[j];
                temp[j] = aux;
            }
        }
    }
    cout << "\nNotas ordenadas de menor a mayor: \n";
    for (int i = 0; i < 3; i++) cout << temp[i] << " ";
    cout << endl;
    cout << endl;
}

// Funcion para ordenar y mostrar de mayor a menor
void ordenarMayorMenor() {
    float temp[3];
    for (int i = 0; i < 3; i++) temp[i] = notas[i];
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (temp[i] < temp[j]) {
                float aux = temp[i];
                temp[i] = temp[j];
                temp[j] = aux;
            }
        }
    }
    cout << "Notas ordenadas de mayor a menor: \n";
    for (int i = 0; i < 3; i++) cout << temp[i] << " ";
    cout << endl;
    cout << endl;
}

// Funcion para mostrar todas las notas que sean igual a la mayor
void mostrarNotasMayores() {
    cout << "La nota mayor: ";
    for (int i = 0; i < 3; i++) {
        if (notas[i] == mayor) {
            cout << notas[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Ingreso de datos por el usuario
    cout << "Ingrese las 3 calificaciones:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    // Calcular suma, promedio y mayor
    calificaciones();

    // Mostrar resultados
    cout << "\n . RESULTADOS . \n";
    cout << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Promedio: " << promedio << endl;

    mostrarNotasMayores();

    ordenarMenorMayor();
    ordenarMayorMenor();

    return 0;
}