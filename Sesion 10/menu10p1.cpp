// Programa principal para la gestión de citas de una clínica.

// main.cpp
#include "clases10p3.cpp" // Incluye las definiciones de las clases (Paciente, Medico, Servicio, Cita)
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Capacidades máximas
const int MAX_PACIENTES = 20;
const int MAX_MEDICOS = 10;
const int MAX_SERVICIOS = 10;
const int MAX_CITAS = 30;

// Variables globales
Paciente pacientes[MAX_PACIENTES];
Medico medicos[MAX_MEDICOS];
Servicio servicios[MAX_SERVICIOS];
Cita citas[MAX_CITAS];

// Contadores de elementos actualmente registrados
int totalPacientes = 0;
int totalMedicos = 0;
int totalServicios = 0;
int totalCitas = 0;

// Función para limpiar pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ---------- Permanencia de Datos ----------

// Guardar todos los datos en clinica.txt
void guardarDatos() {
    ofstream archivo("clinica.txt");
    if (!archivo.is_open()) {   // verificacion, abrio correctamente
        cout << "Error: No se pudo crear clinica.txt" << endl;
        return;
    }
    // Guardar pacientes
    archivo << totalPacientes << endl;
    for (int i = 0; i < totalPacientes; i++) {
        archivo << pacientes[i].getId() << endl;
        archivo << pacientes[i].getDni() << endl;
        archivo << pacientes[i].getNombres() << endl;
        archivo << pacientes[i].getApPaterno() << endl;
        archivo << pacientes[i].getApMaterno() << endl;
        archivo << pacientes[i].getTelefono() << endl;
        archivo << pacientes[i].getDireccion() << endl;
    }
    // Guardar médicos
    archivo << totalMedicos << endl;
    for (int i = 0; i < totalMedicos; i++) {
        archivo << medicos[i].getId() << endl;
        archivo << medicos[i].getDni() << endl;
        archivo << medicos[i].getNombres() << endl;
        archivo << medicos[i].getApPaterno() << endl;
        archivo << medicos[i].getApMaterno() << endl;
        archivo << medicos[i].getEspecialidad() << endl;
        archivo << medicos[i].getTelefono() << endl;
    }
    // Guardar servicios
    archivo << totalServicios << endl;
    for (int i = 0; i < totalServicios; i++) {
        archivo << servicios[i].getId() << endl;
        archivo << servicios[i].getNombre() << endl;
        archivo << servicios[i].getDescripcion() << endl;
        archivo << servicios[i].getPrecio() << endl;
    }
    // Guardar citas
    archivo << totalCitas << endl;
    for (int i = 0; i < totalCitas; i++) {
        archivo << citas[i].getId() << endl;
        archivo << citas[i].getIdPaciente() << endl;
        archivo << citas[i].getIdMedico() << endl;
        archivo << citas[i].getIdServicio() << endl;
        archivo << citas[i].getFecha() << endl;
        archivo << citas[i].getHora() << endl;
    }
    archivo.close();
    cout << "Datos guardados en clinica.txt" << endl;
}

// Cargar datos desde clinica.txt
void cargarDatos() {
    ifstream archivo("clinica.txt");
    if (!archivo.is_open()) {
        // No existe el archivo, empezar vacío
        return;
    }
    // Cargar pacientes
    archivo >> totalPacientes;
    archivo.ignore();
    for (int i = 0; i < totalPacientes; i++) {
        int id; string dni, nombres, apPaterno, apMaterno, telefono, direccion;
        archivo >> id; archivo.ignore();
        getline(archivo, dni);
        getline(archivo, nombres);
        getline(archivo, apPaterno);
        getline(archivo, apMaterno);
        getline(archivo, telefono);
        getline(archivo, direccion);
        pacientes[i] = Paciente(id, dni, nombres, apPaterno, apMaterno, telefono, direccion);
    }
    // Cargar médicos
    archivo >> totalMedicos;
    archivo.ignore();
    for (int i = 0; i < totalMedicos; i++) {
        int id; string dni, nombres, apPaterno, apMaterno, especialidad, telefono;
        archivo >> id; archivo.ignore();
        getline(archivo, dni);
        getline(archivo, nombres);
        getline(archivo, apPaterno);
        getline(archivo, apMaterno);
        getline(archivo, especialidad);
        getline(archivo, telefono);
        medicos[i] = Medico(id, dni, nombres, apPaterno, apMaterno, especialidad, telefono);
    }
    // Cargar servicios
    archivo >> totalServicios;
    archivo.ignore();
    for (int i = 0; i < totalServicios; i++) {
        int id; string nombre, descripcion; double precio;
        archivo >> id; archivo.ignore();
        getline(archivo, nombre);
        getline(archivo, descripcion);
        archivo >> precio; archivo.ignore();
        servicios[i] = Servicio(id, nombre, descripcion, precio);
    }
    // Cargar citas
    archivo >> totalCitas;
    archivo.ignore();
    for (int i = 0; i < totalCitas; i++) {
        int id, idPac, idMed, idServ;
        string fecha, hora;
        archivo >> id; archivo.ignore();
        archivo >> idPac; archivo.ignore();
        archivo >> idMed; archivo.ignore();
        archivo >> idServ; archivo.ignore();
        getline(archivo, fecha);
        getline(archivo, hora);
        citas[i] = Cita(id, idPac, idMed, idServ, fecha, hora);
    }
    archivo.close();
    cout << "Datos cargados desde clinica.txt" << endl;
}

// crear nombre de archivo válido, reemplaza caracteres problemáticos  por guiones bajos
string sanitizarNombreArchivo(string nombre) {
    string resultado = nombre;
    replace(resultado.begin(), resultado.end(), ' ', '_');
    replace(resultado.begin(), resultado.end(), '/', '_');
    replace(resultado.begin(), resultado.end(), '\\', '_');
    return resultado + ".txt";
}

// Guardar citas por servicio (cada servicio tiene su archivo)
void guardarCitasPorServicio() {
    if (totalServicios == 0) {
        cout << "No hay servicios registrados para exportar citas." << endl;
        return;
    }
    for (int s = 0; s < totalServicios; s++) {
        string nombreServicio = servicios[s].getNombre();
        string nombreArchivo = sanitizarNombreArchivo(nombreServicio);
        ofstream archivo(nombreArchivo.c_str());
        if (!archivo.is_open()) {
            cout << "Error al crear archivo para servicio: " << nombreServicio << endl;
            continue;
        }

        // encabezado del servicio
        archivo << "SERVICIO: " << nombreServicio << endl;
        archivo << "PRECIO: S/" << servicios[s].getPrecio() << endl;
        archivo << "============.............===============" << endl;
        
        // Recopilar citas de este servicio
        bool hayCitas = false;
        // Recorrer todas las citas y filtrar por idServicio
        for (int c = 0; c < totalCitas; c++) {
            if (citas[c].getIdServicio() == servicios[s].getId()) {
                hayCitas = true;

                // Obtener datos de médico
                int idMed = citas[c].getIdMedico();
                string nombreMedico = "Desconocido", especialidad = "";
                for (int m = 0; m < totalMedicos; m++) {
                    if (medicos[m].getId() == idMed) {
                        nombreMedico = medicos[m].getNombres() + " " + medicos[m].getApPaterno() + " " + medicos[m].getApMaterno();
                        especialidad = medicos[m].getEspecialidad();
                        break;
                    }
                }
                // Obtener datos de paciente
                int idPac = citas[c].getIdPaciente();
                string nombrePaciente = "Desconocido";
                for (int p = 0; p < totalPacientes; p++) {
                    if (pacientes[p].getId() == idPac) {
                        nombrePaciente = pacientes[p].getNombres() + " " + pacientes[p].getApPaterno() + " " + pacientes[p].getApMaterno();
                        break;
                    }
                }

                // Escribir la información de la cita
                archivo << "MEDICO: " << nombreMedico << " (Especialidad: " << especialidad << ")" << endl;
                archivo << "PACIENTE: " << nombrePaciente << endl;
                archivo << "FECHA: " << citas[c].getFecha() << " HORA: " << citas[c].getHora() << endl;
                archivo << "-----------------------------------------" << endl;
            }
        }
        if (!hayCitas) {
            archivo << "No hay citas asignadas para este servicio." << endl;
        }
        archivo.close();
        cout << "Exportadas citas de " << nombreServicio << " a " << nombreArchivo << endl;
    }
}

// ---------- Funciones del menú (iguales a las anteriores) ----------
void mostrarMenuPrincipal() {
    cout << "\n....... SISTEMA DE GESTION DE CITAS - CLINICA ........." << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Listar Pacientes" << endl;
    cout << "3. Registrar Medico" << endl;
    cout << "4. Listar Medicos" << endl;
    cout << "5. Registrar Servicio" << endl;
    cout << "6. Listar Servicios" << endl;
    cout << "7. Asignar Cita" << endl;
    cout << "8. Listar Citas" << endl;
    cout << "9. Cancelar Cita" << endl;
    cout << "10. Exportar citas por servicio a archivos" << endl;
    cout << "11. Salir" << endl;
    cout << "................................" << endl;
    cout << "Seleccione una opcion: ";
}

void registrarPaciente() {
    if (totalPacientes >= MAX_PACIENTES) {
        cout << "\nNo se pueden registrar mas pacientes. Limite alcanzado." << endl;
        return;
    }
    pacientes[totalPacientes].registrarPaciente(); // Pide los datos al usuario

    pacientes[totalPacientes].setId(totalPacientes + 1); // Asigna ID automático (1..n)
    totalPacientes++;
    cout << "\nPaciente registrado exitosamente con ID " << totalPacientes << "." << endl;
}

void listarPacientes() {
    if (totalPacientes == 0) {
        cout << "\nNo hay pacientes registrados." << endl;
        return;
    }
    cout << "\n--- LISTA DE PACIENTES ---" << endl;
    for (int i = 0; i < totalPacientes; i++) {
        pacientes[i].mostrarPaciente();
    }
}

void registrarMedico() {
    if (totalMedicos >= MAX_MEDICOS) {
        cout << "\nNo se pueden registrar mas medicos. Limite alcanzado." << endl;
        return;
    }
    medicos[totalMedicos].registrarMedico();
    medicos[totalMedicos].setId(totalMedicos + 1);
    totalMedicos++;
    cout << "\nMedico registrado exitosamente con ID " << totalMedicos << "." << endl;
}

void listarMedicos() {
    if (totalMedicos == 0) {
        cout << "\nNo hay medicos registrados." << endl;
        return;
    }
    cout << "\n--- LISTA DE MEDICOS ---" << endl;
    for (int i = 0; i < totalMedicos; i++) {
        medicos[i].mostrarMedico();
    }
}

void registrarServicio() {
    if (totalServicios >= MAX_SERVICIOS) {
        cout << "\nNo se pueden registrar mas servicios. Limite alcanzado." << endl;
        return;
    }
    servicios[totalServicios].registrarServicio();
    servicios[totalServicios].setId(totalServicios + 1);
    totalServicios++;
    cout << "\nServicio registrado exitosamente con ID " << totalServicios << "." << endl;
}

void listarServicios() {
    if (totalServicios == 0) {
        cout << "\nNo hay servicios registrados." << endl;
        return;
    }
    cout << "\n--- LISTA DE SERVICIOS ---" << endl;
    for (int i = 0; i < totalServicios; i++) {
        servicios[i].mostrarServicio();
    }
}

void asignarCita() {
    // Verificar que existan al menos un paciente, médico y servicio
    if (totalPacientes == 0 || totalMedicos == 0 || totalServicios == 0) {
        cout << "\nDebe haber al menos un paciente, un medico y un servicio para asignar una cita." << endl;
        return;
    }
    if (totalCitas >= MAX_CITAS) {
        cout << "\nNo se pueden asignar mas citas. Limite alcanzado." << endl;
        return;
    }
    citas[totalCitas].asignarCita(); // Pide al usuario los datos de la cita (IDs, fecha, hora)
    citas[totalCitas].setId(totalCitas + 1); // Asigna ID único a la cita
    totalCitas++;
    cout << "\nCita asignada exitosamente con ID " << totalCitas << "." << endl;
}

int buscarPacientePorId(int id) {
    for (int i = 0; i < totalPacientes; i++)
        if (pacientes[i].getId() == id) return i;
    return -1;
}
int buscarMedicoPorId(int id) {
    for (int i = 0; i < totalMedicos; i++)
        if (medicos[i].getId() == id) return i;
    return -1;
}
int buscarServicioPorId(int id) {
    for (int i = 0; i < totalServicios; i++)
        if (servicios[i].getId() == id) return i;
    return -1;
}

void listarCitas() {
    if (totalCitas == 0) {
        cout << "\nNo hay citas asignadas." << endl;
        return;
    }
    // Agrupar por servicio
    cout << "\n--- LISTA DE CITAS (Agrupadas por Servicio) ---" << endl;
    // Recorremos cada servicio
    for (int s = 0; s < totalServicios; s++) {
        cout << "\nSERVICIO: " << servicios[s].getNombre() << " - Precio: S/" << servicios[s].getPrecio() << endl;
        cout << "--------------------------------------------------" << endl;
        bool hay = false;

        // Buscar citas que pertenezcan a este servicio
        for (int c = 0; c < totalCitas; c++) {
            if (citas[c].getIdServicio() == servicios[s].getId()) {
                hay = true;

                // Obtener nombre del médico
                int idMed = citas[c].getIdMedico();
                int idxMed = buscarMedicoPorId(idMed);
                string medicoNombre = (idxMed != -1) ? (medicos[idxMed].getNombres() + " " + medicos[idxMed].getApPaterno() + " " + medicos[idxMed].getApMaterno() + " (Esp: " + medicos[idxMed].getEspecialidad() + ")") : "Medico no encontrado";
                
                // Obtener nombre del paciente
                int idPac = citas[c].getIdPaciente();
                int idxPac = buscarPacientePorId(idPac);
                string pacienteNombre = (idxPac != -1) ? (pacientes[idxPac].getNombres() + " " + pacientes[idxPac].getApPaterno() + " " + pacientes[idxPac].getApMaterno()) : "Paciente no encontrado";
                cout << "Medico: " << medicoNombre << endl;
                cout << "   Paciente: " << pacienteNombre << " - Fecha: " << citas[c].getFecha() << " Hora: " << citas[c].getHora() << endl;
            }
        }
        if (!hay) cout << "No hay citas para este servicio." << endl;
    }
}

void cancelarCita() {
    if (totalCitas == 0) {
        cout << "\nNo hay citas para cancelar." << endl;
        return;
    }
    int idCancelar;
    cout << "\nIngrese el ID de la cita a cancelar: ";
    cin >> idCancelar;

    // Buscar posición de la cita en el arreglo
    int pos = -1;
    for (int i = 0; i < totalCitas; i++) {
        if (citas[i].getId() == idCancelar) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "No existe una cita con ID " << idCancelar << "." << endl;
        return;
    }

    // Eliminar desplazando todos los elementos siguientes una posición atrás
    for (int i = pos; i < totalCitas - 1; i++) {
        citas[i] = citas[i + 1];
    }
    totalCitas--;
    cout << "Cita con ID " << idCancelar << " cancelada correctamente." << endl;
}

// ................. Main ................
int main() {
    cargarDatos();  // Cargar datos existentes al inicio
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        switch (opcion) {
            case 1: registrarPaciente(); break;
            case 2: listarPacientes(); break;
            case 3: registrarMedico(); break;
            case 4: listarMedicos(); break;
            case 5: registrarServicio(); break;
            case 6: listarServicios(); break;
            case 7: asignarCita(); break;
            case 8: listarCitas(); break;
            case 9: cancelarCita(); break;
            case 10: guardarCitasPorServicio(); break;
            case 11:
                guardarDatos();             // Guardar todo en clinica.txt
                guardarCitasPorServicio();     // También exportar por servicio antes de salir
                cout << "\nSaliendo del sistema. Datos guardados." << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 11);
    return 0;
}