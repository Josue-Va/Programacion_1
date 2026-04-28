#include <iostream>
using namespace std;

int main() {
    int numeroSecreto = 42;
    int numeroUsuario;
    
    cout << "Adivina el numero (4 intentos): ";
    
    for(int i = 1; i <= 4; i++) {
        cin >> numeroUsuario;
        
        if(numeroUsuario == numeroSecreto) {
            cout << "¡Felicidades! Adivinaste." << endl;
            return 0;
        }
        
        if(i < 4) {
            cout << "Fallaste. Intento " << i+1 << " de 4: ";
        }
    }
    
    cout << "No lograste adivinar. El numero era: " << numeroSecreto << endl;
    
    return 0;
}