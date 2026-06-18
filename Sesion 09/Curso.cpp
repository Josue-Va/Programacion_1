#include <iostream>
#include <string>
#include <fstream>      // para manejo de archivos
#include <sstream>      // para conversiones
#include "Persona.cpp"

using namespace std;

class Curso
{
private:
    int id;
    string nombre;
    int credito;
    Persona docente;
    Persona estudiantes[5];
    int total_alumnos;
    int next_id_alumno;   // para asignar IDs únicos a nuevos alumnos

    // Guarda todos los datos en un archivo de texto
    void guardarDatos() {
        ofstream archivo("datos.txt");
        if (!archivo.is_open()) {
            cout << "Error al guardar los datos del curso." << endl;
            return;
        }
        // 1. Datos del curso
        archivo << id << endl;
        archivo << nombre << endl;
        archivo << credito << endl;
        // 2. Docente (solo si tiene DNI no vacío)
        if (docente.get_dni() != "") {
            archivo << 1 << endl;
            archivo << docente.get_dni() << endl;
            archivo << docente.get_nombre() << endl;
            archivo << docente.get_paterno() << endl;
            archivo << docente.get_materno() << endl;
        } else {
            archivo << 0 << endl;
        }
        // 3. Alumnos
        archivo << total_alumnos << endl;
        archivo << next_id_alumno << endl;
        for (int i = 0; i < 5; i++) {
            if (estudiantes[i].get_dni() != "") {
                archivo << 1 << endl;
                archivo << estudiantes[i].get_id() << endl;
                archivo << estudiantes[i].get_dni() << endl;
                archivo << estudiantes[i].get_nombre() << endl;
                archivo << estudiantes[i].get_paterno() << endl;
                archivo << estudiantes[i].get_materno() << endl;
            } else {
                archivo << 0 << endl;
            }
        }
        archivo.close();
    }

    // Carga los datos desde el archivo (si existe)
    void cargarDatos() {
        ifstream archivo("datos.txt");
        if (!archivo.is_open()) return;  // no hay datos previos

        // 1. Curso
        archivo >> id; archivo.ignore();
        getline(archivo, nombre);
        archivo >> credito; archivo.ignore();

        // 2. Docente
        int tieneDocente;
        archivo >> tieneDocente; archivo.ignore();
        if (tieneDocente) {
            string dni, nom, pater, mater;
            getline(archivo, dni);
            getline(archivo, nom);
            getline(archivo, pater);
            getline(archivo, mater);
            docente = Persona(dni, nom, pater, mater);
        } else {
            docente = Persona();  // vacío
        }

        // 3. Alumnos
        archivo >> total_alumnos; archivo.ignore();
        archivo >> next_id_alumno; archivo.ignore();
        for (int i = 0; i < 5; i++) {
            int tieneAlumno;
            archivo >> tieneAlumno; archivo.ignore();
            if (tieneAlumno) {
                int idAlum; string dni, nom, pater, mater;
                archivo >> idAlum; archivo.ignore();
                getline(archivo, dni);
                getline(archivo, nom);
                getline(archivo, pater);
                getline(archivo, mater);
                Persona alumno(dni, nom, pater, mater);
                alumno.set_id(idAlum);
                estudiantes[i] = alumno;
            } else {
                estudiantes[i] = Persona(); // vacío
            }
        }
        archivo.close();
    }

public:
    // Constructor por defecto: intenta cargar datos previos
    Curso() {
        total_alumnos = 0;
        next_id_alumno = 1;
        cargarDatos();
    }

    Curso(int _id, string _nombre, int _credito) {
        this->id = _id;
        this->nombre = _nombre;
        this->credito = _credito;
        total_alumnos = 0;
        next_id_alumno = 1;
        cargarDatos();
    }

    // Destructor: guarda automáticamente al finalizar el programa
    ~Curso() {
        guardarDatos();
    }

    /*getter and setter*/
    int get_id() { return this->id; }
    void set_id(int _id) { this->id = _id; }
    string get_nombre() { return this->nombre; }
    void set_nombre(string _nombre) { this->nombre = _nombre; }
    int get_credito() { return this->credito; }
    void set_credito(int _credito) { this->credito = _credito; }

    /*metodos*/
    void registrar_curso() {
        int _id, _credito;
        string _nombre;
        cout << "Ingrese el identificador del curso" << endl;
        cin >> _id;
        cout << "Ingrese el nombre curso" << endl;
        cin >> _nombre;
        cout << "Ingrese los creditos" << endl;
        cin >> _credito;
        this->set_id(_id);
        this->set_nombre(_nombre);
        this->set_credito(_credito);
        // Al registrar un nuevo curso, se resetean los alumnos y docente
        total_alumnos = 0;
        next_id_alumno = 1;
        for (int i = 0; i < 5; i++) estudiantes[i] = Persona();
        docente = Persona();
        guardarDatos();
    }

    void agregar_docente() {
        string _dni, _nombre, _apPaterno, apMaterno;
        cout << "Ingrese el dni del docente" << endl;
        cin >> _dni;
        cout << "Ingrese el nombre del docente" << endl;
        cin >> _nombre;
        cout << "Ingrese el apellido paterno del docente" << endl;
        cin >> _apPaterno;
        cout << "Ingrese el apellido materno del docente" << endl;
        cin >> apMaterno;
        this->docente = Persona(_dni, _nombre, _apPaterno, apMaterno);
        guardarDatos();
    }

    void agregar_alumno() {
        if (total_alumnos < 5) {
            string _dni, _nombre, _apPaterno, apMaterno;
            cout << "Ingrese el dni del alumno" << endl;
            cin >> _dni;
            cout << "Ingrese el nombre del alumno" << endl;
            cin >> _nombre;
            cout << "Ingrese el apellido paterno del alumno" << endl;
            cin >> _apPaterno;
            cout << "Ingrese el apellido materno del alumno" << endl;
            cin >> apMaterno;
            Persona alumno = Persona(_dni, _nombre, _apPaterno, apMaterno);
            alumno.set_id(next_id_alumno);   // asignar ID único
            estudiantes[total_alumnos] = alumno;
            total_alumnos++;
            next_id_alumno++;
            guardarDatos();
        } else {
            cout << "No hay capacidad para registrar mas alumnos";
        }
    }

    void listar_alumnos() {
        for (int i = 0; i < 5; i++) {
            if (estudiantes[i].get_dni() != "") {
                estudiantes[i].saludar();
            }
        }
    }

    void eliminar_alumno() {
        int _idEliminar;
        cout << "Ingrese el id del alumno a eliminar" << endl;
        cin >> _idEliminar;
        for (int i = 0; i < 5; i++) {
            if (estudiantes[i].get_id() == _idEliminar) {
                estudiantes[i] = Persona();
                total_alumnos--;
                guardarDatos();
                return;
            }
        }
        cout << "Alumno no encontrado." << endl;
    }

    void imprimir() {
        cout << "===========================" << endl;
        cout << "Nombre del curso: " << this->nombre << endl;
        cout << "Creditos: " << this->credito << endl;
        cout << "Docente del curso " << this->docente.get_nombre() << " " << this->docente.get_paterno() << " " << this->docente.get_materno() << endl;
        cout << "========Alumnos=========" << endl;
        this->listar_alumnos();
        cout << "========================" << endl;
    }
};