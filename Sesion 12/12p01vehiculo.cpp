#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase abstracta Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidad;

public:
    Vehiculo(string _marca, string _modelo) : marca(_marca), modelo(_modelo), velocidad(0) {}
    virtual ~Vehiculo() {}

    virtual void acelerar(int incremento) = 0;
    virtual void frenar(int decremento) = 0;
    virtual void mostrarInfo() const = 0;

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getVelocidad() const { return velocidad; }
    void setVelocidad(int v) { velocidad = v; }
};

// Derivada: Moto
class Moto : public Vehiculo {
private:
    bool tieneSidecar;

public:
    Moto(string _marca, string _modelo, bool _sidecar = false)
        : Vehiculo(_marca, _modelo), tieneSidecar(_sidecar) {}

    void acelerar(int inc) override {
        velocidad += inc;
        if (velocidad > 180) velocidad = 180;
        cout << "Moto acelerando... Vel: " << velocidad << " km/h\n";
    }

    void frenar(int dec) override {
        velocidad -= dec;
        if (velocidad < 0) velocidad = 0;
        cout << "Moto frenando... Vel: " << velocidad << " km/h\n";
    }

    void mostrarInfo() const override {
        cout << "Moto: " << marca << " " << modelo
             << " | Sidecar: " << (tieneSidecar ? "Sí" : "No")
             << " | Vel: " << velocidad << " km/h\n";
    }
};

// Derivada: Coche
class Coche : public Vehiculo {
private:
    int numPuertas;

public:
    Coche(string _marca, string _modelo, int _puertas = 4)
        : Vehiculo(_marca, _modelo), numPuertas(_puertas) {}

    void acelerar(int inc) override {
        velocidad += inc;
        if (velocidad > 220) velocidad = 220;
        cout << "Coche acelerando... Vel: " << velocidad << " km/h\n";
    }

    void frenar(int dec) override {
        velocidad -= dec;
        if (velocidad < 0) velocidad = 0;
        cout << "Coche frenando... Vel: " << velocidad << " km/h\n";
    }

    void mostrarInfo() const override {
        cout << "Coche: " << marca << " " << modelo
             << " | Puertas: " << numPuertas
             << " | Vel: " << velocidad << " km/h\n";
    }
};

// Clase Garaje (agregación: contiene referencias a Vehiculo)
class Garaje {
private:
    vector<Vehiculo*> vehiculos;   // Agregación: los vehículos no son propiedad del garaje

public:
    void agregarVehiculo(Vehiculo* v) {
        if (v) {
            vehiculos.push_back(v);
            cout << "Vehiculo " << v->getMarca() << " " << v->getModelo() << " agregado al garaje.\n";
        }
    }

    void eliminarVehiculo(Vehiculo* v) {
        for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
            if (*it == v) {
                vehiculos.erase(it);
                cout << "Vehiculo eliminado del garaje.\n";
                return;
            }
        }
        cout << "Vehiculo no encontrado en el garaje.\n";
    }

    void listarVehiculos() const {
        if (vehiculos.empty()) {
            cout << "El garaje está vacio.\n";
            return;
        }
        cout << "\n--- VEHICULOS EN EL GARAJE ---\n";
        for (auto v : vehiculos) {
            v->mostrarInfo();
        }
    }

    void acelerarTodos(int incremento) {
        if (vehiculos.empty()) {
            cout << "No hay vehiculos en el garaje.\n";
            return;
        }
        cout << "\nAcelerando todos los vehiculos...\n";
        for (auto v : vehiculos) {
            v->acelerar(incremento);
        }
    }

    void frenarTodos(int decremento) {
        if (vehiculos.empty()) {
            cout << "No hay vehiculos en el garaje.\n";
            return;
        }
        cout << "\nFrenando todos los vehiculos...\n";
        for (auto v : vehiculos) {
            v->frenar(decremento);
        }
    }
};