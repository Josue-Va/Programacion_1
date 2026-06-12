#include <iostream>
using namespace std;

int main() {
    int num, mayor, menor;
    bool iguales = false;
    
    cout << "Ingrese 5 numeros: " << endl;
    
    // Primer número
    cin >> num;
    mayor = menor = num;
    
    // Leer los 4 números restantes
    for(int i = 2; i <= 5; i++) {
        cin >> num;
        
        if(num > mayor) mayor = num;
        if(num < menor) menor = num;
        if(num == mayor || num == menor) iguales = true;
    }
    
    // Resultados
    cout << "\nMayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    
    if(iguales)
        cout << "Hay numeros iguales" << endl;
    else
        cout << "No hay numeros iguales" << endl;
    
    return 0;
}







/*


#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    int mayor, menor;
    bool hayIguales = false;
    
    cout << "Ingrese 5 numeros: " << endl;
    
    // Leer y guardar los 5 números
    for(int i = 0; i < 5; i++) {
        cin >> numeros[i];
    }
    
    // Inicializar mayor y menor con el primer número
    mayor = menor = numeros[0];
    
    // Encontrar mayor y menor
    for(int i = 1; i < 5; i++) {
        if(numeros[i] > mayor) mayor = numeros[i];
        if(numeros[i] < menor) menor = numeros[i];
    }
    
    // Mostrar resultados básicos
    cout << "\nMayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    
    // Buscar y mostrar números repetidos
    cout << "Numeros que se repiten: ";
    bool hayRepetido = false;
    
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(numeros[i] == numeros[j]) {
                cout << numeros[i] << " ";
                hayRepetido = true;
                break; // Evita mostrar el mismo número varias veces
            }
        }
    }
    
    if(!hayRepetido) {
        cout << "Ninguno";
    }
    cout << endl;
    
    return 0;
}*/