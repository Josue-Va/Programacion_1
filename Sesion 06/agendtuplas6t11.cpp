#include <iostream>
#include <tuple>  
#include <string>   
#include <vector>  

using namespace std;

//  "Evento"
// Una tupla de 4 elementos: (codigo, nombre, fecha, prioridad)
// - codigo: entero unico 
// - nombre: string 
// - fecha: string 
// - prioridad
using Evento = tuple<int, string, string, int>;

// Funcion para mostrar un evento en pantalla
void mostrarEvento(const Evento& e) {
    //  → primer elemento de la tupla (codigo)
    //  → segundo (nombre)
    //  → tercero (fecha)
    //  → cuarto (prioridad)
    cout << "ID: " << get<0>(e)
         << "  Evento: " << get<1>(e)
         << "  Fecha: " << get<2>(e)
         << "  Prioridad: " << get<3>(e);
    
    // Mostrar texto segun el valor de prioridad
    if (get<3>(e) == 1) cout << " (Alta)";
    else if (get<3>(e) == 2) cout << " (Media)";
    else cout << " (Baja)";
    cout << endl;
}

int main() {
    // VECTOR que almacenara todos los eventos (lista dinamica)
    // vector<Evento> : una colección de tuplas de tipo Evento
    vector<Evento> agenda;
    
    int opcion;
    int codigo = 1;   // Contador para ID unicos

    do {
        // Mostrar menu principal
        cout << "\n.. AGENDA DE EVENTOS ..\n";
        cout << "1. Agregar evento\n";
        cout << "2. Listar eventos\n";
        cout << "3. Modificar prioridad de un evento\n";
        cout << "4. Eliminar evento\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        //  AGREGAR EVENTO 
        if (opcion == 1) {
            string nombre, fecha;
            int prioridad;
            
            // Pedir datos al usuario
            cout << "Nombre del evento: ";
            cin.ignore();               // Limpiar el buffer del teclado (por el cin anterior)
            getline(cin, nombre);       // Leer linea completa (permite espacios)
            
            cout << "Fecha (DD/MM/AAAA): ";
            getline(cin, fecha);
            
            cout << "Prioridad (1=Alta, 2=Media, 3=Baja): ";
            cin >> prioridad;
            
            // CREAR UNA TUPLA
            // make_tuple empaqueta los valores en una tupla del tipo Evento
            Evento nuevo = make_tuple(codigo++, nombre, fecha, prioridad);
            
            // AGREGAR al vector con push_back (final de lista)
            agenda.push_back(nuevo);
            
            cout << "Evento agregado con ID " << codigo-1 << endl;
        }
        
        // LISTAR EVENTOS 
        else if (opcion == 2) {
            if (agenda.empty()) {   // empty() devuelve true si el vector esta vacío
                cout << "No hay eventos registrados.\n";
            } else {
                cout << "\n--- LISTA DE EVENTOS ---\n";
                // Recorrer el vector usando un bucle for-rango 
                // asi se evita copiar la tupla y no se modifica accidentalmente
                for (const auto& ev : agenda) { // referencia constante a cada elemento
                    mostrarEvento(ev);   // Llamar a la funcion que imprime
                }
            }
        }
        
        //  MODIFICAR PRIORIDAD 
        else if (opcion == 3) {
            int id, nuevaPrioridad;
            cout << "ID del evento a modificar: ";
            cin >> id;
            
            bool encontrado = false;   // Bandera para saber si se encontro el ID
            
            // Recorrer el vector elemento por elemento
            for (auto& ev : agenda) {  // 'auto& ev' es referencia para poder modificar la tupla original
                if (get<0>(ev) == id) {   // Comparar el ID (primer elemento de la tupla) con el buscado
                    cout << "Prioridad actual: " << get<3>(ev) << ". ";
                    cout << "Nueva prioridad (1,2,3): ";
                    cin >> nuevaPrioridad;
                    
                    // Modificar el cuarto elemento de la tupla
                    get<3>(ev) = nuevaPrioridad;
                    
                    cout << "Prioridad actualizada.\n";
                    encontrado = true;
                    break;   // Salir del bucle 
                }
            }
            if (!encontrado) cout << "Evento no encontrado.\n";
        }
        
        //  ELIMINAR EVENTO 
        else if (opcion == 4) {
            int id;
            cout << "ID del evento a eliminar: ";
            cin >> id;
            
            bool encontrado = false;
            
            // Para eliminar necesitamos un iterador (posición dentro del vector)
            // En lugar de for-rango, usamos un bucle con iteradores explicitos
            for (auto it = agenda.begin(); it != agenda.end(); ++it) {  
                
                if (get<0>(*it) == id) {   // Para acceder al elemento usamos *it ('it' es un puntero)(direferenciar)

                    // erase(it) elimina el elemento apuntado por el iterador, el vector se reacomoda automáticamente
                    agenda.erase(it);
                    cout << "Evento eliminado.\n";
                    encontrado = true;
                    break;   // Salir del bucle (ya no hay más elementos con ese ID)
                }
            }
            if (!encontrado) cout << "Evento no encontrado.\n";
        }
        
    } while (opcion != 5);   // Repetir mientras no se elija Salir

    cout << "Saliendo de la agenda\n";
    return 0;
}