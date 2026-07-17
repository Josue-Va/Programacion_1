#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Declarar un mapa (diccionario) que asocia strings (nombres) con enteros (edades)
    map<string, int> edades;  

    // Insertar valores usando el operador corchete []
    edades["Ana"] = 25;
    edades["Maria"] = 35;
    edades["Josefa"] = 20;

    // Acceder al valor asociado a una clave
    cout << "La edad de Josefa es: " << edades["Josefa"] << endl;

    // Si la clave no existe, el operador [] la crea con valor 0 (por defecto)
    cout << "La edad de Carlos es: " << edades["Carlos"] << endl;  // Carlos se añade con edad 0

    // Insertar usando el método insert() y una lista.
    edades.insert({"Pedro", 15});
    edades.insert({"Analucia", 18});

    // Recorrer el mapa usando un bucle for con desestructuración 
        // El mapa se ordena automáticamente por las clave, alfabético
    for (auto &[nombre, edad] : edades) {
        cout << nombre << ": " << edad << endl;
    }

    // Buscar si existe una clave usando find()
    // find() devuelve un iterador al elemento, o end() si no lo encuentra
    if (edades.find("Luis") != edades.end()) {
        cout << "Luis existe en el diccionario" << endl;
    } else {
        cout << "Luis no existe en el diccionario" << endl;  
    }

    return 0;
}