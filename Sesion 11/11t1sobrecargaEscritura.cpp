#include <iostream>
#include <string>
using namespace std;

// ==========================================================
// 1. POLIMORFISMO DE SOBRECARGA (estático, compilación)
//    Mismo nombre, PERO distintos parámetros.
//    Los SETTERS son perfectos para sobrecargarse.
// ==========================================================
class Contenedor {
private:
    double valor; // Atributo encapsulado

public:
    // --- SETTER SOBRECARGADO (mismo nombre, distinto tipo) 
    void setValor(int v) {          // Versión para enteros
        valor = v;
        cout << "  Setter int guardo: " << v << endl;
    }
    void setValor(double v) {       // Versión para decimales
        valor = v;
        cout << "  Setterdouble guardo: " << v << endl;
    }

    // --- GETTER normal (no se sobrecarga, solo lee) ---
    double getValor() const {
        return valor;
    }
};

// ==========================================================
// 2. POLIMORFISMO DE SOBREESCRITURA (dinámico, ejecución)
//    Misma firma, pero la SUBCLASE cambia la implementación.
//    Los GETTERS/SETTERS se heredan y funcionan igual.
// ==========================================================
class Animal {
private:
    string nombre;

public:
    // Getters y Setters normales (se heredan a las subclases)
    void setNombre(string n) { nombre = n; }
    string getNombre() const { return nombre; }

    // Método VIRTUAL: obligatorio para poder sobrescribir
    virtual void sonido() const {
        cout << "Sonido generico" << endl;
    }

    virtual ~Animal() {} // Destructor virtual (buena práctica)
};

class Perro : public Animal {
public:
    // Sobrescritura: cambia el comportamiento
    void sonido() const override {
        cout << "Guau! Soy " << getNombre() << endl; // getNombre() heredado
    }
};

class Gato : public Animal {
public:
    void sonido() const override {
        cout << "Miau! Soy " << getNombre() << endl;
    }
};


int main() {
    cout << "\n.. SOBRECARGA .." << endl;
    Contenedor c;
    c.setValor(10);      // El compilador elige la versión int
    c.setValor(3.14);    // El compilador elige la versión double
    cout << "Valor final: " << c.getValor() << endl;

    cout << "\n.. SOBREESCRITURA ..-" << endl;
    Perro perro;
    perro.setNombre("Rex");
    Gato gato;
    gato.setNombre("Luna");

    // Punteros de tipo Animal apuntan a objetos de las subclases
    Animal* a1 = &perro;
    Animal* a2 = &gato;

    // En tiempo de ejecución, el programa decide qué método ejecutar según el objeto real
    a1->sonido(); // Llamada a Perro::sonido()
    a2->sonido(); // Llamada a Gato::sonido()

    return 0;
}