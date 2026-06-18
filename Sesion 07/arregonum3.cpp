#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <algorithm> 

using namespace std;

const int TAM = 10;       // Tamaño del arreglo
const int LIMITE = 100;   // Números menores a 100 (0-99)

// Función para llenar el arreglo con números aleatorios
void llenarConAleatorios(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        arreglo[i] = rand() % LIMITE;   // Genera números entre 0 y 99
    }
}

// Función para mostrar el arreglo
void mostrarArreglo(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Función para ordenar de menor a mayor 
void ordenarArreglo(int arreglo[], int tamanio) {
    sort(arreglo, arreglo + tamanio);
    cout << endl;
}

// Función para obtener el número máximo (después de ordenar es el último)
int obtenerMaximo(int arreglo[], int tamanio) {
    return arreglo[tamanio - 1];
    cout << endl;
}

int main() {
    // Inicializar la semilla para números aleatorios diferentes cada vez
    srand(time(0));

    int numeros[TAM];

    // 1. Llenar el arreglo con números aleatorios
    llenarConAleatorios(numeros, TAM);

    cout << endl;
    cout << "Arreglo original (generado aleatoriamente):" << endl;
    mostrarArreglo(numeros, TAM);

    // 2. Ordenar de menor a mayor
    ordenarArreglo(numeros, TAM);

    cout << "Arreglo ordenado de menor a mayor:" << endl;
    mostrarArreglo(numeros, TAM);
    cout << endl;

    // 3. Obtener e indicar el número máximo
    int maximo = obtenerMaximo(numeros, TAM);
    cout << "El numero maximo es: " << maximo << endl;

    return 0;
}