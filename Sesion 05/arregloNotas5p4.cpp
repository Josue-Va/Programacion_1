#include <iostream>
using namespace std;

// Variables globales
int suma = 0, promedio, mayor;
float notas[3];  \

// Función que procesa las calificaciones 
int calificaciones() {
    suma = 0;  // inicializar suma dentro de la función
    // Calcular suma y encontrar la mayor
    for(int i = 0; i < 3; i++) 
    {
        suma = suma + notas[i];
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    promedio = suma / 3;
    cout << "El promedio es: " << promedio << endl;
    return 0;   
}

int main()
{
    // Asignar valores al arreglo global
    notas[0] = 12;
    notas[1] = 13;
    notas[2] = 7;  

    // Llamar a la función 
    calificaciones();

    // Mostrar también la nota mayor
    cout << "La nota mayor es: " << mayor << endl;

    return 0;  
}