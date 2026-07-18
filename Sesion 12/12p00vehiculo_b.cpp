#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ....... CLASE VEHICULO (abstracta) ..........
class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadActual;

public:
    Vehiculo(string _marca, string _modelo) 
        : marca(_marca), modelo(_modelo), velocidadActual(0) {}

    virtual ~Vehiculo() {}

    // Métodos virtuales puros (clase abstracta)
    virtual void acelerar(int incremento) = 0;
    virtual void frenar(int decremento) = 0;
    virtual void mostrarInfo() const = 0;

    // Getters comunes
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getVelocidad() const { return velocidadActual; }

    // Método concreto para establecer velocidad (usado por derivados)
    void setVelocidad(int v) { velocidadActual = v; }
};

// ============ CLASE MOTO (hereda de Vehiculo) ============
class Moto : public Vehiculo {
private:
    bool tieneSidecar;

public:
    Moto(string _marca, string _modelo, bool _sidecar = false)
        : Vehiculo(_marca, _modelo), tieneSidecar(_sidecar) {}

    void acelerar(int incremento) override {
        velocidadActual += incremento;
        if (velocidadActual > 180) velocidadActual = 180;  // límite
        cout << "Moto acelerando... Velocidad: " << velocidadActual << " km/h\n";
    }

    void frenar(int decremento) override {
        velocidadActual -= decremento;
        if (velocidadActual < 0) velocidadActual = 0;
        cout << "Moto frenando... Velocidad: " << velocidadActual << " km/h\n";
    }

    void mostrarInfo() const override {
        cout << ".... MOTO ....\n";
        cout << "Marca: " << marca << ", Modelo: " << modelo << "\n";
        cout << "Velocidad actual: " << velocidadActual << " km/h\n";
        cout << "Sidecar: " << (tieneSidecar ? "Si" : "No") << "\n";
    }
};

// ============ CLASE COCHE (hereda de Vehiculo) ============
class Coche : public Vehiculo {
private:
    int numPuertas;

public:
    Coche(string _marca, string _modelo, int _puertas = 4)
        : Vehiculo(_marca, _modelo), numPuertas(_puertas) {}

    void acelerar(int incremento) override {
        velocidadActual += incremento;
        if (velocidadActual > 220) velocidadActual = 220;
        cout << "Coche acelerando... Velocidad: " << velocidadActual << " km/h\n";
    }

    void frenar(int decremento) override {
        velocidadActual -= decremento;
        if (velocidadActual < 0) velocidadActual = 0;
        cout << "Coche frenando... Velocidad: " << velocidadActual << " km/h\n";
    }

    void mostrarInfo() const override {
        cout << "=== COCHE ===\n";
        cout << "Marca: " << marca << ", Modelo: " << modelo << "\n";
        cout << "Velocidad actual: " << velocidadActual << " km/h\n";
        cout << "Puertas: " << numPuertas << "\n";
    }
};

// ============ CLASE CONDUCTOR (asociación con Vehiculo) ============
class Conductor {
private:
    string nombre;
    Vehiculo* vehiculoAsignado;   // Asociación: el conductor TIENE un vehículo

public:
    Conductor(string _nombre) : nombre(_nombre), vehiculoAsignado(nullptr) {}

    void asignarVehiculo(Vehiculo* v) {
        vehiculoAsignado = v;
        cout << nombre << " ahora conduce un " << v->getMarca() << " " << v->getModelo() << "\n";
    }

    void conducir(int aceleracion) {
        if (vehiculoAsignado) {
            cout << nombre << " acelera el vehiculo.\n";
            vehiculoAsignado->acelerar(aceleracion);
        } else {
            cout << nombre << " no tiene vehiculo asignado.\n";
        }
    }

    void frenar(int decremento) {
        if (vehiculoAsignado) {
            cout << nombre << " frena el vehiculo.\n";
            vehiculoAsignado->frenar(decremento);
        } else {
            cout << nombre << " no tiene vehiculo asignado.\n";
        }
    }

    void mostrarInfo() const {
        cout << "Conductor: " << nombre << "\n";
        if (vehiculoAsignado) {
            cout << "Vehiculo asignado: ";
            vehiculoAsignado->mostrarInfo();
        } else {
            cout << "Sin vehiculo asignado.\n";
        }
    }
};

// ============ CLASE TALLER (asociación con Vehiculo) ============
class Taller {
private:
    vector<Vehiculo*> vehiculosEnReparacion;   // Asociación: el taller REPARA vehículos

public:
    void recibirVehiculo(Vehiculo* v) {
        vehiculosEnReparacion.push_back(v);
        cout << "Vehiculo " << v->getMarca() << " " << v->getModelo() 
             << " ingresó al taller.\n";
    }

    void repararTodos() {
        if (vehiculosEnReparacion.empty()) {
            cout << "No hay vehiculos en el taller.\n";
            return;
        }
        cout << "Reparando todos los vehiculos...\n";
        for (auto v : vehiculosEnReparacion) {
            // Simulación: se frena a 0 y se muestra info
            v->frenar(v->getVelocidad());
            cout << "Reparacion completada para: ";
            v->mostrarInfo();
        }
        vehiculosEnReparacion.clear();
    }

    void listarVehiculos() const {
        if (vehiculosEnReparacion.empty()) {
            cout << "Taller vacio.\n";
            return;
        }
        cout << "Vehiculos en el taller:\n";
        for (auto v : vehiculosEnReparacion) {
            v->mostrarInfo();
        }
    }
};

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // 1. Crear algunos vehículos
    Moto* moto1 = new Moto("Yamaha", "MT-07", false);
    Coche* coche1 = new Coche("Toyota", "Corolla", 4);
    Coche* coche2 = new Coche("Tesla", "Model 3", 4);

    // 2. Crear conductores y asignar vehículos (ASOCIACIÓN)
    Conductor juan("Juan");
    Conductor maria("Maria");

    juan.asignarVehiculo(moto1);
    maria.asignarVehiculo(coche1);

    // 3. Acciones de conducción
    juan.conducir(30);
    juan.conducir(20);
    maria.conducir(50);
    maria.frenar(30);

    // 4. Mostrar información de conductores
    juan.mostrarInfo();
    maria.mostrarInfo();

    // 5. Taller (ASOCIACIÓN con vehículos)
    Taller taller;
    taller.recibirVehiculo(coche2);
    taller.recibirVehiculo(moto1);   // la moto también puede entrar al taller
    taller.listarVehiculos();
    taller.repararTodos();

    // 6. Liberar memoria
    delete moto1;
    delete coche1;
    delete coche2;

    return 0;
}