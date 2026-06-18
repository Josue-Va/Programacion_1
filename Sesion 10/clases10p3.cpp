
// Definición de todas las clases del sistema


#include <iostream>
#include <string>
using namespace std;

//  CLASE PACIENTE ...........
class Paciente {
private:
    int id;
    string dni;
    string nombres;
    string ap_paterno;
    string ap_materno;
    string telefono;
    string direccion;

public:
    // Constructor por defecto
    Paciente() {
        id = 0;
        dni = "";
        nombres = "";
        ap_paterno = "";
        ap_materno = "";
        telefono = "";
        direccion = "";
    }


    // Constructor con parámetros
    Paciente(int _id, string _dni, string _nombres, string _ap_paterno, 
             string _ap_materno, string _telefono, string _direccion) {
        id = _id;
        dni = _dni;
        nombres = _nombres;
        ap_paterno = _ap_paterno;
        ap_materno = _ap_materno;
        telefono = _telefono;
        direccion = _direccion;
    }

    // Getters (const para usarlos en funciones constantes)
    int getId() const { return id; }
    string getDni() const { return dni; }
    string getNombres() const { return nombres; }
    string getApPaterno() const { return ap_paterno; }
    string getApMaterno() const { return ap_materno; }
    string getTelefono() const { return telefono; }
    string getDireccion() const { return direccion; }

    // Setters
    void setId(int _id) { id = _id; }
    void setDni(string _dni) { dni = _dni; }
    void setNombres(string _nombres) { nombres = _nombres; }
    void setApPaterno(string _ap_paterno) { ap_paterno = _ap_paterno; }
    void setApMaterno(string _ap_materno) { ap_materno = _ap_materno; }
    void setTelefono(string _telefono) { telefono = _telefono; }
    void setDireccion(string _direccion) { direccion = _direccion; }

    // Registrar un nuevo paciente (pide datos al usuario)
    void registrarPaciente() {
        cout << "\n--- REGISTRO DE PACIENTE ---" << endl;
        cout << "DNI: "; cin >> dni;
        cout << "Nombres: "; cin >> nombres;
        cout << "Apellido Paterno: "; cin >> ap_paterno;
        cout << "Apellido Materno: "; cin >> ap_materno;
        cout << "Telefono: "; cin >> telefono;
        cout << "Direccion: "; cin.ignore(); getline(cin, direccion);
        // El ID se asigna automáticamente desde el main
    }

    // Mostrar datos del paciente
    void mostrarPaciente() const {
        cout << "ID: " << id << endl;
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombres << " " << ap_paterno << " " << ap_materno << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "------------------------" << endl;
    }
};

//  CLASE MEDICO .............
class Medico {
private:
    int id;
    string dni;
    string nombres;
    string ap_paterno;
    string ap_materno;
    string especialidad;
    string telefono;

public:
    Medico() {
        id = 0;
        dni = "";
        nombres = "";
        ap_paterno = "";
        ap_materno = "";
        especialidad = "";
        telefono = "";
    }

    Medico(int _id, string _dni, string _nombres, string _ap_paterno,
           string _ap_materno, string _especialidad, string _telefono) {
        id = _id;
        dni = _dni;
        nombres = _nombres;
        ap_paterno = _ap_paterno;
        ap_materno = _ap_materno;
        especialidad = _especialidad;
        telefono = _telefono;
    }

    // Getters
    int getId() const { return id; }
    string getDni() const { return dni; }
    string getNombres() const { return nombres; }
    string getApPaterno() const { return ap_paterno; }
    string getApMaterno() const { return ap_materno; }
    string getEspecialidad() const { return especialidad; }
    string getTelefono() const { return telefono; }

    // Setters
    void setId(int _id) { id = _id; }
    void setDni(string _dni) { dni = _dni; }
    void setNombres(string _nombres) { nombres = _nombres; }
    void setApPaterno(string _ap_paterno) { ap_paterno = _ap_paterno; }
    void setApMaterno(string _ap_materno) { ap_materno = _ap_materno; }
    void setEspecialidad(string _especialidad) { especialidad = _especialidad; }
    void setTelefono(string _telefono) { telefono = _telefono; }

    void registrarMedico() {
        cout << "\n--- REGISTRO DE MEDICO ---" << endl;
        cout << "DNI: "; cin >> dni;
        cout << "Nombres: "; cin >> nombres;
        cout << "Apellido Paterno: "; cin >> ap_paterno;
        cout << "Apellido Materno: "; cin >> ap_materno;
        cout << "Especialidad: "; cin >> especialidad;
        cout << "Telefono: "; cin >> telefono;
    }

    void mostrarMedico() const {
        cout << "ID: " << id << endl;
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombres << " " << ap_paterno << " " << ap_materno << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "------------------------" << endl;
    }
};

//  CLASE SERVICIO ..............
class Servicio {
private:
    int id;
    string nombre;
    string descripcion;
    double precio;

public:
    Servicio() {
        id = 0;
        nombre = "";
        descripcion = "";
        precio = 0.0;
    }

    Servicio(int _id, string _nombre, string _descripcion, double _precio) {
        id = _id;
        nombre = _nombre;
        descripcion = _descripcion;
        precio = _precio;
    }

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }
    double getPrecio() const { return precio; }

    void setId(int _id) { id = _id; }
    void setNombre(string _nombre) { nombre = _nombre; }
    void setDescripcion(string _descripcion) { descripcion = _descripcion; }
    void setPrecio(double _precio) { precio = _precio; }

    void registrarServicio() {
        cout << "\n--- REGISTRO DE SERVICIO ---" << endl;
        cout << "Nombre: "; cin >> nombre;
        cout << "Descripcion: "; cin.ignore(); getline(cin, descripcion);
        cout << "Precio: "; cin >> precio;
    }

    void mostrarServicio() const {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio: S/" << precio << endl;
        cout << "------------------------" << endl;
    }
};

// CLASE CITA .......
class Cita {
private:
    int id;
    int idPaciente;
    int idMedico;
    int idServicio;
    string fecha;   // formato dd/mm/aaaa
    string hora;    // formato hh:mm

public:
    Cita() {
        id = 0;
        idPaciente = 0;
        idMedico = 0;
        idServicio = 0;
        fecha = "";
        hora = "";
    }

    Cita(int _id, int _idPaciente, int _idMedico, int _idServicio, 
         string _fecha, string _hora) {
        id = _id;
        idPaciente = _idPaciente;
        idMedico = _idMedico;
        idServicio = _idServicio;
        fecha = _fecha;
        hora = _hora;
    }

    // Getters
    int getId() const { return id; }
    int getIdPaciente() const { return idPaciente; }
    int getIdMedico() const { return idMedico; }
    int getIdServicio() const { return idServicio; }
    string getFecha() const { return fecha; }
    string getHora() const { return hora; }

    // Setters
    void setId(int _id) { id = _id; }
    void setIdPaciente(int _id) { idPaciente = _id; }
    void setIdMedico(int _id) { idMedico = _id; }
    void setIdServicio(int _id) { idServicio = _id; }
    void setFecha(string _fecha) { fecha = _fecha; }
    void setHora(string _hora) { hora = _hora; }

    void asignarCita() {
        cout << "\n--- ASIGNAR CITA ---" << endl;
        cout << "ID del paciente: "; cin >> idPaciente;
        cout << "ID del medico: "; cin >> idMedico;
        cout << "ID del servicio: "; cin >> idServicio;
        cout << "Fecha (dd/mm/aaaa): "; cin >> fecha;
        cout << "Hora (hh:mm): "; cin >> hora;
    }

    void mostrarCita() const {
        cout << "ID Cita: " << id << endl;
        cout << "ID Paciente: " << idPaciente << endl;
        cout << "ID Medico: " << idMedico << endl;
        cout << "ID Servicio: " << idServicio << endl;
        cout << "Fecha: " << fecha << " Hora: " << hora << endl;
        cout << "------------------------" << endl;
    }
};