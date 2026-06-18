#include <iostream>
#include <string>
#include <limits>   // limpiar el buffer 
using namespace std;

class Persona {
private:
    int id;
    string dni;
    string nombre;
    string ap_paterno;
    string ap_materno;
    string fecha_nacimiento;
    string direccion;
    string telefono;
    int edad;

public:
    Persona() {
        // Inicializamos id = 0 
        id = 0;
    }

    Persona(int _id, string _dni, string _nombre, string _ap_paterno, string _ap_materno,
            string _fecha_nacimiento, string _direccion, string _telefono, int _edad) {
        id = _id;
        dni = _dni;
        nombre = _nombre;
        ap_paterno = _ap_paterno;
        ap_materno = _ap_materno;
        fecha_nacimiento = _fecha_nacimiento;
        direccion = _direccion;
        telefono = _telefono;
        edad = _edad;
    }

    // Getters
    int getId() { return id; }
    string getDni() { return dni; }
    string getNombre() { return nombre; }
    string getApPaterno() { return ap_paterno; }
    string getApMaterno() { return ap_materno; }
    string getFechaNacimiento() { return fecha_nacimiento; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    int getEdad() { return edad; }

    // Setters
    void setId(int _id) { id = _id; }
    void setDni(string _dni) { dni = _dni; }
    void setNombre(string _nombre) { nombre = _nombre; }
    void setApPaterno(string _ap_paterno) { ap_paterno = _ap_paterno; }
    void setApMaterno(string _ap_materno) { ap_materno = _ap_materno; }
    void setFechaNacimiento(string _fecha) { fecha_nacimiento = _fecha; }
    void setDireccion(string _direccion) { direccion = _direccion; }
    void setTelefono(string _telefono) { telefono = _telefono; }
    void setEdad(int _edad) { edad = _edad; }

    void Saludar() {
        cout << "Hola, mi nombre es " << nombre << " " << ap_paterno << " " << ap_materno << endl;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n ..GESTION DE ESTUDIANTES.. " << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Eliminar estudiante" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Función para registrar un estudiante
void registrarEstudiante(Persona estudiantes[], int &cantidad) {
    if (cantidad >= 5) {
        cout << "No se pueden registrar (Maximo 5) " << endl;
        return;
    }

    // Buscar la primera posición vacía (id == 0)
    int pos = -1;
    for (int i = 0; i < 5; i++) {
        if (estudiantes[i].getId() == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "No hay espacio disponible." << endl;
        return;
    }

    int nuevoId = pos + 1;  // ID automático según posición (1 a 5)
    string dni, nombre, ap_paterno, ap_materno, fecha_nac, direccion, telefono;
    int edad;

    cout << "\n .Registrar nuevo estudiante (ID " << nuevoId << ")." << endl;
    cout << "DNI: "; cin >> dni;
    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido Paterno: "; cin >> ap_paterno;
    cout << "Apellido Materno: "; cin >> ap_materno;
    cout << "Fecha de nacimiento (dd/mm/aaaa): "; cin >> fecha_nac;
    cout << "Direccion: "; cin.ignore();  // Limpiar buffer antes de getline
    getline(cin, direccion);
    cout << "Telefono: ";
    getline(cin, telefono);
    cout << "Edad: "; cin >> edad;

    // Asignar los datos al objeto
    estudiantes[pos].setId(nuevoId);
    estudiantes[pos].setDni(dni);
    estudiantes[pos].setNombre(nombre);
    estudiantes[pos].setApPaterno(ap_paterno);
    estudiantes[pos].setApMaterno(ap_materno);
    estudiantes[pos].setFechaNacimiento(fecha_nac);
    estudiantes[pos].setDireccion(direccion);
    estudiantes[pos].setTelefono(telefono);
    estudiantes[pos].setEdad(edad);

    cantidad++;
    cout<<endl;
    cout << "Estudiante registrado exitosamente con ID " << nuevoId << "." << endl;
}

// Función para mostrar estudiantes
void mostrarEstudiantes(Persona estudiantes[], int cantidad) {
    if (cantidad == 0) {
        cout<<endl;
        cout<< "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < 5; i++) {
        if (estudiantes[i].getId() != 0) {
            cout << "ID: " << estudiantes[i].getId() << endl;
            cout << "DNI: " << estudiantes[i].getDni() << endl;
            cout << "Nombre: " << estudiantes[i].getNombre() << " "<< estudiantes[i].getApPaterno() << " "<< estudiantes[i].getApMaterno() << endl;
            cout << "Fecha nacimiento.: " << estudiantes[i].getFechaNacimiento() << endl;
            cout << "Direccion: " << estudiantes[i].getDireccion() << endl;
            cout << "Telefono: " << estudiantes[i].getTelefono() << endl;
            cout << "Edad: " << estudiantes[i].getEdad() << endl;
            cout << endl;
        }
    }
}

// Función para eliminar un estudiante por ID
void eliminarEstudiante(Persona estudiantes[], int &cantidad) {
    if (cantidad == 0) {
        cout<<endl;
        cout << "No hay estudiantes para eliminar." << endl;
        return;
    }

    int idEliminar;
    cout<<endl;
    cout << "Ingrese el ID del estudiante a eliminar (1 a 5): ";
    cin >> idEliminar;

    if (idEliminar < 1 || idEliminar > 5) {
        cout << "ID inválido." << endl;
        return;
    }

    int pos = idEliminar - 1;
    if (estudiantes[pos].getId() == 0) {
        cout<<endl;
        cout << "No existe un estudiante con ID " << idEliminar << "." << endl;
        return;
    }

    // Eliminar reiniciando el objeto a valores por defecto (id = 0)
    estudiantes[pos] = Persona();  // usa el constructor por defecto que pone id=0
    cantidad--;
    cout<<endl;
    cout << "Estudiante con ID " << idEliminar << " eliminado " << endl;
}

int main() {
    Persona estudiantes[5];  // Arreglo de 5 estudiantes 
    int cantidad = 0;        // Contador de estudiantes registrados

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                eliminarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                cout<<endl;
                cout << "Saliendo del programa .." << endl;
                break;
            default:
                cout<<endl;
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}