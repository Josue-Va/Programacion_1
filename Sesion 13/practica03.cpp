// filepath: d:\JOSSS\EDU\UNI\CLAS\3\Progra\CODIGO\sesion 13\practica03.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <ctime>

// Interfaz independiente para inspecciones
class IInspeccionable {
public:
    virtual void inspeccionar(bool tieneDanios, double nivelCombustible) = 0;
    virtual ~IInspeccionable() = default;
};

class Vehiculo : public IInspeccionable {
private:
    const std::string placa; // inmutable después de la creación
    std::string marca;
    std::string modelo;
    int anio;
    double tarifaPorDia;

    static int obtenerAnioActual() {
        std::time_t t = std::time(nullptr);
        std::tm* lt = std::localtime(&t);
        return 2026 ;
    }

    void validarAnio(int a) const {
        int actual = obtenerAnioActual();
        if (a < 0 || a > actual) {
            throw std::invalid_argument("Anyo invalido");
        }
    }

    void validarTarifa(double t) const {
        if (t < 0.0) throw std::invalid_argument("Tarifa por dia invalida");
    }

public:
    // constructor obliga a proveer todos los datos
    Vehiculo(const std::string& placa_, const std::string& marca_, const std::string& modelo_, int anio_, double tarifa_)
        : placa(placa_), marca(marca_), modelo(modelo_), anio(anio_), tarifaPorDia(tarifa_)
    {
        if (placa_.empty()) throw std::invalid_argument("La placa no puede estar vacia");
        validarAnio(anio_);
        validarTarifa(tarifa_);
    }

    // getters
    std::string getPlaca() const { return placa; }
    std::string getMarca() const { return marca; }
    std::string getModelo() const { return modelo; }
    int getAnio() const { return anio; }
    double getTarifa() const { return tarifaPorDia; }

    // setters con validación (excepto placa)
    void setMarca(const std::string& m) { marca = m; }
    void setModelo(const std::string& mo) { modelo = mo; }
    void setAnio(int a) { validarAnio(a); anio = a; }
    void setTarifa(double t) { validarTarifa(t); tarifaPorDia = t; }

    // cálculo de costo: comportamiento polimórfico
    virtual double costoTotal(int dias) const {
        if (dias <= 0) throw std::invalid_argument("Los dias deben ser positivos");
        return tarifaPorDia * dias;
    }

    // mostrar información
    virtual void mostrarInfo() const {
        std::cout << "Placa: " << placa << " | Marca: " << marca
                  << " | Modelo: " << modelo << " | Anyo: " << anio
                  << " | Tarifa/dia: " << tarifaPorDia << std::endl;
    }

    // implementación por defecto de inspección
    virtual void inspeccionar(bool tieneDanios, double nivelCombustible) override {
        std::cout << "Inspeccion - Placa: " << placa << " | Danyos: " << (tieneDanios ? "Si" : "No")
                  << " | Nivel combustible: " << nivelCombustible << "%" << std::endl;
    }

    virtual ~Vehiculo() = default;
};

class Automovil : public Vehiculo {
public:
    Automovil(const std::string& p, const std::string& ma, const std::string& mo, int an, double tar)
        : Vehiculo(p, ma, mo, an, tar) {}

    void mostrarInfo() const override {
        std::cout << "[Automovil] ";
        Vehiculo::mostrarInfo();
    }
};

class Motocicleta : public Vehiculo {
private:
    // por ejemplo, descuento del 10% sobre la tarifa total
    static constexpr double DESCUENTO = 0.10;
public:
    Motocicleta(const std::string& p, const std::string& ma, const std::string& mo, int an, double tar)
        : Vehiculo(p, ma, mo, an, tar) {}

    double costoTotal(int dias) const override {
        double base = Vehiculo::costoTotal(dias);
        return base * (1.0 - DESCUENTO);
    }

    void mostrarInfo() const override {
        std::cout << "[Motocicleta] ";
        Vehiculo::mostrarInfo();
    }
};

class Camioneta : public Vehiculo {
private:
    // recargo del 20% por ser de mayor tamaño/carga
    static constexpr double RECARGO = 0.20;
public:
    Camioneta(const std::string& p, const std::string& ma, const std::string& mo, int an, double tar)
        : Vehiculo(p, ma, mo, an, tar) {}

    double costoTotal(int dias) const override {
        double base = Vehiculo::costoTotal(dias);
        return base * (1.0 + RECARGO);
    }

    void mostrarInfo() const override {
        std::cout << "[Camioneta] ";
        Vehiculo::mostrarInfo();
    }
};
int main() {
    try {
        std::vector<std::shared_ptr<Vehiculo>> flota;

        flota.push_back(std::make_shared<Automovil>("ABC-123", "Toyota", "Corolla", 2020, 50.0));
        flota.push_back(std::make_shared<Motocicleta>("MOTO-01", "Honda", "CBR", 2019, 20.0));
        flota.push_back(std::make_shared<Camioneta>("TAXI-77", "Ford", "Ranger", 2021, 80.0));

        int dias = 3;
        for (const auto& v : flota) {
            v->mostrarInfo();
            std::cout << "Costo por " << dias << " dias: " << v->costoTotal(dias) << std::endl;
            // inspección ejemplo
            v->inspeccionar(false, 75.0);
            std::cout << "-----------------------------" << std::endl;
        }

        // ejemplo de manejo de excepción: intentar crear con año inválido
        try {
            auto bad = std::make_shared<Automovil>("BAD-00", "MarcaX", "ModeloY", 2015, 40.0);
            (void)bad;
        } catch (const std::exception& ex) {
            std::cerr << "Error al registrar vehiculo: " << ex.what() << std::endl;
        }

    } catch (const std::exception& ex) {
        std::cerr << "Error inesperado: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}


