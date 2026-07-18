#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;
    int stock;

public:
    Producto() : id(0), nombre(""), precio(0.0), stock(0) {}

    void registrar(int nuevoId) {
        id = nuevoId;
        cout << "Nombre: "; cin >> nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Stock: "; cin >> stock;
    }

    void mostrar() const {
        cout << "ID: " << id << " | " << nombre
             << " | S/" << precio << " | Stock: " << stock << endl;
    }

    // Getters y setters básicos
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
    void setPrecio(double p) { precio = p; }
    void setStock(int s) { stock = s; }
};