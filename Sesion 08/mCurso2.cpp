/*
 programa que almacena notas de 5 estudiantes, permitir registrar las notas (4),
  calcular el promedio por cada estudiante, identifique al
  estudiante con mayor promedio, mostrar estudiantes aprobados y desaprobados. 
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int ESTUDIANTES = 5;
    const int NOTAS_POR_EST = 4;
    const int APROBADO = 11;     

    int notas[ESTUDIANTES][NOTAS_POR_EST];  
    double promedios[ESTUDIANTES];         
    int mayorPromedioIndex = 0;             

    // 1. Registrar las notas 
    for (int i = 0; i < ESTUDIANTES; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        int suma = 0;
        for (int j = 0; j < NOTAS_POR_EST; j++) {
            cout << "  Nota " << j + 1 << " (0-20): ";
            cin >> notas[i][j];
            // Validación opcional
            suma += notas[i][j];
        }
        promedios[i] = suma / (double)NOTAS_POR_EST;  // promedio 
    }

    // 2. Identificar al estudiante con mayor promedio
    for (int i = 1; i < ESTUDIANTES; i++) {
        if (promedios[i] > promedios[mayorPromedioIndex]) {
            mayorPromedioIndex = i;
        }
    }

    // 3. Mostrar resultados
    cout << "\n=== RESULTADOS ===\n";
    for (int i = 0; i < ESTUDIANTES; i++) {
        cout << "Estudiante " << i + 1
             << " - Promedio: " << promedios[i]
             << " - " << (promedios[i] >= APROBADO ? "APROBADO" : "DESAPROBADO") << endl;
    }

    cout << "\n--- Estudiante con mayor promedio ---\n";
    cout << "Estudiante " << mayorPromedioIndex + 1
         << " con promedio: " << promedios[mayorPromedioIndex] << endl;

    cout << "\n--- Lista de aprobados (nota >= 11) ---\n";
    for (int i = 0; i < ESTUDIANTES; i++) {
        if (promedios[i] >= APROBADO)
            cout << "Estudiante " << i + 1 << " (promedio " << promedios[i] << ")\n";
    }

    cout << "\n--- Lista de desaprobados (nota < 11) ---\n";
    for (int i = 0; i < ESTUDIANTES; i++) {
        if (promedios[i] < APROBADO)
            cout << "Estudiante " << i + 1 << " (promedio " << promedios[i] << ")\n";
    }

    return 0;
}