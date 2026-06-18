#include "curso.cpp"
#include "persona.cpp"
#include <limits>

using namespace std;

const int MAX_CURSOS = 10;

// Función para pedir datos de una persona (id se asigna después)
Persona pedirDatosPersona() {
    string dni, nombre, ap_paterno, ap_materno, fecha_nac, direccion, telefono;
    int edad;

    cout << "DNI: "; cin >> dni;
    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido Paterno: "; cin >> ap_paterno;
    cout << "Apellido Materno: "; cin >> ap_materno;
    cout << "Fecha de nacimiento (dd/mm/aaaa): "; cin >> fecha_nac;
    cout << "Direccion: "; cin.ignore();
    getline(cin, direccion);
    cout << "Telefono: "; getline(cin, telefono);
    cout << "Edad: "; cin >> edad;

    return Persona(0, dni, nombre, ap_paterno, ap_materno, fecha_nac, direccion, telefono, edad);
}

// Muestra la lista de cursos registrados
void listarCursos(Curso* cursos[], int numCursos) {
    if (numCursos == 0) {
        cout << "\nNo hay cursos registrados aun." << endl;
        return;
    }
    cout << "\n--- LISTA DE CURSOS REGISTRADOS ---" << endl;
    for (int i = 0; i < numCursos; i++) {
        cout << i + 1 << ". ID: " << cursos[i]->getId()
             << " | Nombre: " << cursos[i]->getNombre()
             << " | Creditos: " << cursos[i]->getCreditos() << endl;
    }
}

// Selecciona un curso por índice (0..numCursos-1)
int seleccionarCurso(Curso* cursos[], int numCursos) {
    if (numCursos == 0) {
        cout << "\nNo hay cursos disponibles. Registre un curso primero." << endl;
        return -1;
    }
    listarCursos(cursos, numCursos);
    int op;
    cout << "Seleccione el numero del curso: ";
    cin >> op;
    if (op < 1 || op > numCursos) {
        cout << "Opcion invalida." << endl;
        return -1;
    }
    return op - 1;   // índice base 0
}

void mostrarMenu() {
    cout << "\n===== SISTEMA DE GESTION DE CURSOS =====" << endl;
    cout << "1. Registrar un nuevo curso" << endl;
    cout << "2. Listar todos los cursos" << endl;
    cout << "3. Seleccionar un curso y gestionarlo" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarSubMenu() {
    cout << "\n--- GESTION DEL CURSO SELECCIONADO ---" << endl;
    cout << "1. Registrar docente" << endl;
    cout << "2. Agregar estudiante" << endl;
    cout << "3. Mostrar estudiantes" << endl;
    cout << "4. Eliminar estudiante" << endl;
    cout << "5. Mostrar datos del curso (curso + docente)" << endl;
    cout << "6. Volver al menu principal" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Curso* cursos[MAX_CURSOS];   // arreglo de punteros a cursos
    int numCursos = 0;            // cantidad actual de cursos

    int opcionPrincipal;
    do {
        mostrarMenu();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1: { // Registrar un nuevo curso
                if (numCursos >= MAX_CURSOS) {
                    cout << "\nNo se pueden registrar mas cursos. Maximo " << MAX_CURSOS << "." << endl;
                } else {
                    int idCurso, creditos;
                    string nombreCurso;
                    cout << "\n--- REGISTRAR NUEVO CURSO ---" << endl;
                    cout << "Ingrese ID del curso: "; cin >> idCurso;
                    cout << "Ingrese nombre del curso: "; cin.ignore(); getline(cin, nombreCurso);
                    cout << "Ingrese cantidad de creditos: "; cin >> creditos;
                    cursos[numCursos] = new Curso(idCurso, nombreCurso, creditos);
                    numCursos++;
                    cout << "\nCurso registrado exitosamente." << endl;
                }
                break;
            }
            case 2: { // Listar todos los cursos
                listarCursos(cursos, numCursos);
                break;
            }
            case 3: { // Seleccionar un curso y gestionarlo
                if (numCursos == 0) {
                    cout << "\nNo hay cursos registrados. Registre un curso primero." << endl;
                    break;
                }
                int idx = seleccionarCurso(cursos, numCursos);
                if (idx == -1) break;

                Curso* cursoActual = cursos[idx];
                int subOpcion;
                do {
                    mostrarSubMenu();
                    cin >> subOpcion;
                    switch (subOpcion) {
                        case 1: { // Registrar docente
                            cout << "\n--- REGISTRAR DOCENTE ---" << endl;
                            cout << "Ingrese los datos del docente:" << endl;
                            Persona docente = pedirDatosPersona();
                            docente.setId(99);
                            cursoActual->setDocente(docente);
                            cout << "\nDocente registrado y asignado al curso correctamente." << endl;
                            break;
                        }
                        case 2: { // Agregar estudiante
                            if (cursoActual->getNumEstudiantes() >= 5) {
                                cout << "\nEl curso ya tiene 5 estudiantes. No se puede agregar mas." << endl;
                            } else {
                                cout << "\n--- AGREGAR ESTUDIANTE ---" << endl;
                                cout << "Ingrese los datos del estudiante:" << endl;
                                Persona estudiante = pedirDatosPersona();
                                if (cursoActual->agregarEstudiante(estudiante)) {
                                    cout << "\nEstudiante agregado exitosamente." << endl;
                                }
                            }
                            break;
                        }
                        case 3: // Mostrar estudiantes
                            cursoActual->mostrarEstudiantes();
                            break;
                        case 4: { // Eliminar estudiante
                            cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;
                            int idEliminar;
                            cout << "Ingrese el ID del estudiante a eliminar (1 a 5): ";
                            cin >> idEliminar;
                            cursoActual->eliminarEstudiante(idEliminar);
                            break;
                        }
                        case 5: // Mostrar datos del curso (curso + docente)
                            cursoActual->mostrarCurso();
                            break;
                        case 6: // Volver al menu principal
                            cout << "\nRegresando al menu principal..." << endl;
                            break;
                        default:
                            cout << "\nOpcion no valida." << endl;
                    }
                } while (subOpcion != 6);
                break;
            }
            case 4: // Salir
                cout << "\nSaliendo del programa. BYE" << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 4);

    // Liberar memoria de todos los cursos
    for (int i = 0; i < numCursos; i++) {
        delete cursos[i];
    }
    return 0;
}