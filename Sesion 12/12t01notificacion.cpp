#include <iostream>
#include <string>
using namespace std;

class INotificacion {
public:
    virtual ~INotificacion() {}
    virtual void enviar() const = 0;
    virtual string tipo() const = 0;
};

class Notificacion : public INotificacion {
private:
    string destino;
    string mensaje;

public:
    Notificacion(string d, string m) : destino(d), mensaje(m) {}
    virtual ~Notificacion() {}

    string getDestino() const {
        return destino;
    }

    string getMensaje() const {
        return mensaje;
    }
};

class Correo : public Notificacion {
public:
    Correo(string d, string m) : Notificacion(d, m) {}

    void enviar() const override {
        cout << "Correo Para: " << getDestino() << "\n";
        cout << "Mensaje: " << getMensaje() << endl;
    }

    string tipo() const override {
        return "Correo";
    }
};

class SMS : public Notificacion {
public:
    SMS(string d, string m) : Notificacion(d, m) {}

    void enviar() const override {
        cout << "SMS Para: " << getDestino() << "\n";
        cout << "Mensaje: " << getMensaje() << endl;
    }

    string tipo() const override {
        return "SMS";
    }
};

class Whatsapp : public Notificacion {
public:
    Whatsapp(string d, string m) : Notificacion(d, m) {}

    void enviar() const override {
        cout << "WhatsApp Para: " << getDestino() << "\n";
        cout << "Mensaje: " << getMensaje() << endl;
    }

    string tipo() const override {
        return "WhatsApp";
    }
};

int main() {
    int opcion;

    cout << "... Sistema de Notificaciones ..." << endl;
    cout << "1. Correo" << endl;
    cout << "2. SMS" << endl;
    cout << "3. WhatsApp" << endl;
    cout << "4. Salir" << endl;

    do {
        cout << "\nElige una opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Correo c("josue@correo.com", "Hola, tienes un recordatorio");
                cout << "Tipo: " << c.tipo() << endl;
                c.enviar();
                break;
            }
            case 2: {
                SMS s("987654321", "Tu pedido ha sido confirmado");
                cout << "Tipo: " << s.tipo() << endl;
                s.enviar();
                break;
            }
            case 3: {
                Whatsapp w("+51 999 888 777", "Te enviamos una imagen");
                cout << "Tipo: " << w.tipo() << endl;
                w.enviar();
                break;
            }
            case 4:
                cout << "Saliendo...." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);

    return 0;
}