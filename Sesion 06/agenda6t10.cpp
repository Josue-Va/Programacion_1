#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para agrupar datos de un evento
struct Evento {
    int id;
    string nombre, fecha;
    int prioridad; // 1=Alta, 2=Media, 3=Baja
};

int main() {
    vector<Evento> agenda;  // Contenedor dinámico (lista)
    int codigo = 1, opcion;

    do {
        cout << "\n=== AGENDA ===\n1Agregar 2Listar 3ModifPrior 4Eliminar 5Salir\nOpcion: ";
        cin >> opcion;

        if (opcion == 1) {  // AGREGAR: crear evento y anadir al vector
            Evento e;
            e.id = codigo++;
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, e.nombre);
            cout << "Fecha (DD/MM/AAAA): ";
            getline(cin, e.fecha);
            cout << "Prioridad (1Alta 2Media 3Baja): ";
            cin >> e.prioridad;
            agenda.push_back(e);
            cout << "Agregado ID " << e.id << endl;
        }
        else if (opcion == 2) {  // LISTAR: recorrer vector
            if (agenda.empty()) cout << "Vacio\n";
            else for (auto &ev : agenda) {
                cout << "ID:" << ev.id << " " << ev.nombre << " " << ev.fecha << " Prioridad:" << ev.prioridad;
                if (ev.prioridad == 1) cout << "(Alta)";
                else if (ev.prioridad == 2) cout << "(Media)";
                else cout << "(Baja)";
                cout << endl;
            }
        }
        else if (opcion == 3) {  // MODIFICAR PRIORIDAD: buscar por id
            int id, np;
            cout << "ID a modificar: ";
            cin >> id;
            bool ok = false;
            for (auto &ev : agenda)
                if (ev.id == id) {
                    cout << "Nueva prioridad (1,2,3): ";
                    cin >> np;
                    ev.prioridad = np;
                    cout << "Actualizado\n";
                    ok = true;
                    break;
                }
            if (!ok) cout << "No existe\n";
        }
        else if (opcion == 4) {  // ELIMINAR: buscar por id y borrar con iterador
            int id;
            cout << "ID a eliminar: ";
            cin >> id;
            bool ok = false;
            for (auto it = agenda.begin(); it != agenda.end(); ++it)
                if (it->id == id) {
                    agenda.erase(it);
                    cout << "Eliminado\n";
                    ok = true;
                    break;
                }
            if (!ok) cout << "No existe\n";
        }
    } while (opcion != 5);

    cout << "Saliendo\n";
    return 0;
}