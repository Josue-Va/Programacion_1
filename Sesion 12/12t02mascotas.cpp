#include <iostream>
#include <string>
using namespace std;

class IMascota {
public:
    virtual ~IMascota() {}
    virtual void emitirSonido() const = 0;
    virtual string tipo() const = 0;
};

class Mascota : public IMascota {
private:
    string nombre;

public:
    Mascota(string n) : nombre(n) {}
    virtual ~Mascota() {}

    string getNombre() const {
        return nombre;
    }
};

class Perro : public Mascota {
public:
    Perro(string n) : Mascota(n) {}

    void emitirSonido() const override {
        cout << "Guau guau";
    }

    string tipo() const override {
        return "Perro";
    }
};

class Gato : public Mascota {
public:
    Gato(string n) : Mascota(n) {}

    void emitirSonido() const override {
        cout << "Miau";
    }

    string tipo() const override {
        return "Gato";
    }
};

class Conejo : public Mascota {
public:
    Conejo(string n) : Mascota(n) {}

    void emitirSonido() const override {
        cout << "Rrrr";
    }

    string tipo() const override {
        return "Conejo";
    }
};

int main() {
    int opcion;

    cout << "..... Clasificador de mascotas ....." << endl;
    cout << "1. Perro" << endl;
    cout << "2. Gato" << endl;
    cout << "3. Conejo" << endl;
    cout << "4. Salir" << endl;

    do {
        cout << "\nElige una opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Perro m("Firulais");
                cout << "Clasificacion: " << m.tipo() << endl;
                cout << "Nombre: " << m.getNombre() << endl;
                cout << "Sonido: ";
                m.emitirSonido();
                cout << endl;
                break;
            }
            case 2: {
                Gato m("Michi");
                cout << "Clasificacion: " << m.tipo() << endl;
                cout << "Nombre: " << m.getNombre() << endl;
                cout << "Sonido: ";
                m.emitirSonido();
                cout << endl;
                break;
            }
            case 3: {
                Conejo m("Toto");
                cout << "Clasificacion: " << m.tipo() << endl;
                cout << "Nombre: " << m.getNombre() << endl;
                cout << "Sonido: ";
                m.emitirSonido();
                cout << endl;
                break;
            }
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);

    return 0;
}