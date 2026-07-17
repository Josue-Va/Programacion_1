#include <iostream>
using namespace std;

// Plantilla para imprimir un arreglo unidimensional de cualquier tipo
template <typename T>
void imprimir(const T arreglo[], int tamanyo) {
    for (int i = 0; i < tamanyo; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Función para modificar un arreglo de enteros (multiplicar cada elemento por 2)
void modificar_arreglo(int arreglo[], int tamanyo) {
    for (int i = 0; i < tamanyo; i++) {
        arreglo[i] *= 2;
    }
}

// Plantilla para recorrer una matriz de dimensiones fijas (tamaño conocido en compilación)
template<size_t FILAS, size_t COLUMNAS>
void recorrer_matriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Arreglo de enteros
    int numeros[5] = {10, 20, 30, 40, 50};
    int tamanyo1 = 5;

    // Arreglo de flotantes
    float valores[] = {3.5, 4.6, 8.8};
    int tamanyo2 = 3;

    // Arreglo de strings
    string nombre[3] = {"Juana", "Marcela", "Maria"};
    int tamanyo3 = 3;

    // Imprimir arreglos originales
    cout << "Arreglo numeros: ";
    imprimir(numeros, tamanyo1);
    cout << "Arreglo valores: ";
    imprimir(valores, tamanyo2);
    cout << "Arreglo nombres: ";
    imprimir(nombre, tamanyo3);

    cout << ".." << endl;

    // Modificar arreglo numeros (multiplicar por 2) y mostrarlo
    modificar_arreglo(numeros, tamanyo1);
    cout << "Arreglo numeros modificado: ";
    imprimir(numeros, tamanyo1);

    cout << ".." << endl;

    // Matriz 3x3
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Mostrar elemento [2][2] (fila 2, columna 2) -> valor 9
    cout << "matriz[2][2] = " << matriz[2][2] << endl;

    // Recorrer toda la matriz
    cout << "Recorrido completo de la matriz:" << endl;
    recorrer_matriz<3, 3>(matriz);  // se pasan los tamaños como argumentos template

    return 0;
}