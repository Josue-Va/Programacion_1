#include <iostream>
#include <string>
#include "TeoObjetos9p1.cpp"  
using namespace std;

int main(){
    // Crear objetos usando constructores
    Persona estudiante = Persona();
    Persona estudiante2 = Persona(2, "87654321", "Maria", "Lopez", "Diaz","02/02/2001", "Calle Falsa 456", "123456789", 23);

    // Asignar valores con setters (usando los nombres correctos)
    estudiante.setDni("123");
    estudiante.setNombre("Luis");
    estudiante.setApPaterno("Julca");
    estudiante.setApMaterno("Rodriguez");

    // Llamar al método Saludar 
    estudiante.Saludar();
    estudiante2.Saludar();

    // Mostrar datos con getters
    cout << "hola: " << estudiante.getDni() << " " << estudiante2.getNombre() << endl;

    // Arreglo de 5 estudiantes
    Persona estudiantes[5];
    string dni, nombre, paterno, materno;

    for (int i = 0; i < 5; i++) {
        cout << "\n--- Estudiante " << (i + 1) << " ---" << endl;
        cout << "DNI : ";          cin >> dni;
        cout << "Nombre : ";       cin >> nombre;
        cout << "Apellido Paterno : "; cin >> paterno;
        cout << "Apellido Materno : "; cin >> materno;

        // Asignar los datos al arreglo usando setters
        estudiantes[i].setDni(dni);
        estudiantes[i].setNombre(nombre);
        estudiantes[i].setApPaterno(paterno);
        estudiantes[i].setApMaterno(materno);
    }

    // Mostrar todos los estudiantes guardados
    cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < 5; i++) {
        estudiantes[i].Saludar();
    }

    return 0;
}