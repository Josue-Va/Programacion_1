#include <iostream>
#include <iomanip>  // Para dar formato a los números
#include <cstdlib>  // Para system("clear")
using namespace std;

// Funciones matemáticas básicas
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n\n";
    cout << "     CALCULADORA       \n";
    cout << "\n";
    cout << "  1. Sumar (+)         \n";
    cout << "  2. Restar (-)        \n";
    cout << "  3. Multiplicar (*)   \n";
    cout << "  4. Dividir (/)       \n";
    cout << "  5. Limpiar pantalla  \n";
    cout << "  6. Salir             \n";
    cout << "\n";
    cout << "Elige una opcion: ";
}

// Función para mostrar la calculadora en pantalla
void mostrarCalculadora(float num1, float num2, char operador, float resultado, bool mostrarResultado) {
    limpiarPantalla();
    
    cout << "\n";
    cout << "         -- CALCULADORA --          \n";
    cout << "                                 \n";
    cout << setw(10) << num1 <<"       "<< operador <<""<< setw(9) << num2 << "\n";
    
    if(mostrarResultado) {
        cout <<endl;
        cout << "       " << setw(10) <<" :: "<< resultado << " ::    \n";
    } else {
        cout << "              ::::::::           \n";
    }   
}

// Función para pedir un número con validación y mostrarlo en pantalla
float pedirNumero(string mensaje, int &numActual, char &operador, float num1, bool esperandoOperador) {
    float numero;
    cout << mensaje;
    cin >> numero;
    
    // Verificar si el usuario ingresó un número válido
    while(cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Debes ingresar un numero valido.\n";
        cout << mensaje;
        cin >> numero;
    }
    
    return numero;
}

int main() {
    float num1 = 0, num2 = 0, resultado = 0;
    int opcion;
    bool continuar = true;
    bool mostrarResultado = false;
    char operador = ' ';
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        // Validar que la opción sea un número
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Opcion no valida.\n";
            continue;
        }
        
        // Salir del programa
        if(opcion == 6) {
            cout << "\nsaliendo......"<<endl;
            break;
        }
        
        // Limpiar pantalla
        if(opcion == 5) {
            limpiarPantalla();
            continue;
        }
        
        // Validar que la opción esté entre 1 y 4
        if(opcion < 1 || opcion > 4) {
            cout << "Error: Opcion no valida. Elige entre 1 y 6.\n";
            continue;
        }
        // Mostrar interfaz de calculadora
        mostrarCalculadora(num1, num2, operador, resultado, mostrarResultado);
        
        // Configurar operador según la opción
        switch(opcion) {
            case 1:
                operador = '+';
                break;
            case 2:
                operador = '-';
                break;
            case 3:
                operador = '*';
                break;
            case 4:
                operador = '/';
                break;
        }
        
        // Pedir el primer número con mejor visualización
        cout << "\n";
        cout << "  Ingresa el primer numero:      \n";
        cout << "\n";
        cout << "  => ";
        cin >> num1;
        
        // Validar entrada del primer número
        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Error: Numero inválido. Intenta de nuevo: ";
            cin >> num1;
        }
        
        // Actualizar pantalla con el primer número
        mostrarCalculadora(num1, num2, operador, resultado, false);
        
        // Pedir el segundo número
        cout << "\n";
        cout << "  Ingresa el segundo numero:     \n";
        cout << "\n";
        cout << "  => ";
        cin >> num2;
        
        // Validar entrada del segundo número
        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  Error: Numero inválido. Intenta de nuevo: ";
            cin >> num2;
        }
        
        // Realizar la operación elegida
        switch(opcion) {
            case 1:  // Suma
                resultado = sumar(num1, num2);
                mostrarResultado = true;
                mostrarCalculadora(num1, num2, operador, resultado, true);
                cout << "\n";
                cout << "  RESULTADO: " << num1 << " + " << num2 << " = " << resultado << "     \n";
                cout << "\n";
                break;
                
            case 2:  // Resta
                resultado = restar(num1, num2);
                mostrarResultado = true;
                mostrarCalculadora(num1, num2, operador, resultado, true);
                cout << "\n";
                cout << "  RESULTADO: " << num1 << " - " << num2 << " = " << resultado << "     \n";
                cout << "\n";
                break;
                
            case 3:  // Multiplicación
                resultado = multiplicar(num1, num2);
                mostrarResultado = true;
                mostrarCalculadora(num1, num2, operador, resultado, true);
                cout << "\n";
                cout << "  RESULTADO: " << num1 << " * " << num2 << " = " << resultado << "     \n";
                cout << "\n";
                break;
                
            case 4:  // División
                if(num2 == 0) {
                    mostrarCalculadora(num1, num2, operador, 0, false);
                    cout << "\n";
                    cout << "  ERROR: No se puede dividir     \n";
                    cout << "  entre cero                     \n";
                    cout << "\n";
                    mostrarResultado = false;
                } else {
                    resultado = dividir(num1, num2);
                    mostrarResultado = true;
                    mostrarCalculadora(num1, num2, operador, resultado, true);
                    cout << "\n";
                    cout << "  RESULTADO: " << num1 << " / " << num2 << " = " << resultado << " \n";
                    cout << "\n";
                }
                break;
        }
        
        cout << "\n";
        cout << "  Presiona Enter para continuar...";
        cin.ignore();
        cin.get();
        
    } while(opcion != 6);
      cout <<endl;
    return 0;
}