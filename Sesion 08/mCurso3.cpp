/*
programa sobre, un numero es considerado especial si la suma de sus dígitos puede
calcularse hasta obtener un digito, solicite ingresar un numero por teclado,
desarrolle una función para hallar
el numero especial, se debe obtener el resultado de un digito.
*/

#include <iostream>
using namespace std;

// Función que calcula el número especial (raíz digital)
int calcularNumeroEspecial(int numero) {
    // Asegurar que trabajamos con valor absoluto (por si el número es negativo)
    if (numero < 0) numero = -numero;
    
    // Mientras el número tenga más de un dígito
    while (numero >= 10) {
        int suma = 0;
        // Sumar los dígitos del número actual
        while (numero > 0) {
            suma += numero % 10;
            numero /= 10;
        }
        numero = suma; // Reemplazar número con la suma de sus dígitos
    }
    return numero;
}

int main() {
    int numero;
    
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    
    int resultado = calcularNumeroEspecial(numero);
    
    cout << "El numero especial es: " << resultado << endl;
    
    return 0;
}