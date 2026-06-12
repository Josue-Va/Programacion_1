
#include <iostream>
using namespace std;

int main() {
    // Declarar variables para los 4 números
    double num1, num2, num3, num4;
    
    // Pedir los 4 números al usuario
    cout << "Ingrese primer numero: ";
    cin >> num1;
    cout << "Ingrese segundo numero: ";
    cin >> num2;
    cout << "Ingrese tercer numero: ";
    cin >> num3;
    cout << "Ingrese cuarto numero: ";
    cin >> num4;
    
    // 1. Número mayor
    double mayor = num1;
    if (num2 > mayor) mayor = num2;
    if (num3 > mayor) mayor = num3;
    if (num4 > mayor) mayor = num4;
    
    // 2. Número menor
    double menor = num1;
    if (num2 < menor) menor = num2;
    if (num3 < menor) menor = num3;
    if (num4 < menor) menor = num4;
    
    // 3. Sumatoria
    double suma = num1 + num2 + num3 + num4;
    
    // 4. Promedio
    double promedio = suma / 4;
    
    // 5. Lista ordenada de menor a mayor
    // Crear un arreglo con los 4 números
    double numeros[4] = {num1, num2, num3, num4};
    
    // Ordenar usando método de burbuja (simple)
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (numeros[i] > numeros[j]) {
                // Intercambiar valores
                double temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
    
    // Mostrar resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Numero mayor: " << mayor << endl;
    cout << "Numero menor: " << menor << endl;
    cout << "Sumatoria: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Lista ordenada de menor a mayor: ";
    cout << numeros[0] << ", " << numeros[1] << ", " << numeros[2] << ", " << numeros[3] << endl;
    
    return 0;
} 