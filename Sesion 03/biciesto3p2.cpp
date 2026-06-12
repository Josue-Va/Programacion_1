#include <iostream>
using namespace std;

int main() {
    int año;
    
    cout <<endl;
    cout << "Ingrese un anyo: ";
    cin >> año;
    
    // Fórmula compacta para año bisiesto
    bool esBisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
    
    cout << "\n -- RESULTADO -- " << endl;
    cout << "- El anyo " << año;
    
    if (esBisiesto) {
        cout << " : ES bisiesto ( tiene 366 dias )" << endl;
    } else {
        cout << " : NO es bisiesto ( tiene 365 dias )" << endl;
        cout <<endl;
    }  
    
    return 0;
}