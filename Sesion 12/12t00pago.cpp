#include <iostream>
#include <string>
using namespace std;

class IMetodoPago {
public:
    virtual ~IMetodoPago() {}
    virtual void procesarPago(float monto) const = 0;
    virtual string tipo() const = 0;
};

class MetodoPago : public IMetodoPago {
private:
    string nombreCliente;
    string referencia;

public:
    MetodoPago(string cliente, string ref) : nombreCliente(cliente), referencia(ref) {}
    virtual ~MetodoPago() {}

    string getNombreCliente() const {
        return nombreCliente;
    }

    string getReferencia() const {
        return referencia;
    }
};

class Tarjeta : public MetodoPago {
public:
    Tarjeta(string cliente, string ref) : MetodoPago(cliente, ref) {}

    void procesarPago(float monto) const override {
        cout << "Tarjeta Cliente: " << getNombreCliente() << endl;
        cout << "Referencia: " << getReferencia() << endl;
        cout << "Pago procesado por S/." << monto << endl;
    }

    string tipo() const override {
        return "Tarjeta";
    }
};

class Yape : public MetodoPago {
public:
    Yape(string cliente, string ref) : MetodoPago(cliente, ref) {}

    void procesarPago(float monto) const override {
        cout << "Yape Cliente: " << getNombreCliente() << endl;
        cout << "Celular: " << getReferencia() << endl;
        cout << "Pago procesado por S/." << monto << endl;
    }

    string tipo() const override {
        return "Yape";
    }
};

class Transferencia : public MetodoPago {
public:
    Transferencia(string cliente, string ref) : MetodoPago(cliente, ref) {}

    void procesarPago(float monto) const override {
        cout << "Transferencia Cliente: " << getNombreCliente() << endl;
        cout << "Cuenta: " << getReferencia() << endl;
        cout << "Pago procesado por S/." << monto << endl;
    }

    string tipo() const override {
        return "Transferencia";
    }
};

int main() {
    int opcion;
    float monto;

    cout << ".... Sistema de pagos ...." << endl;
    cout << "1. Tarjeta" << endl;
    cout << "2. Yape" << endl;
    cout << "3. Transferencia" << endl;
    cout << "4. Salir" << endl;

    do {
        cout << "\nElige una opcion: ";
        cin >> opcion;

        if (opcion == 4) {
            cout << "Saliendo..." << endl;
            continue;
        }

        cout << "Ingresa el monto a pagar: ";
        cin >> monto;

        switch (opcion) {
            case 1: {
                Tarjeta t("Ana", "1234 5678 9012 3456");
                cout << "Metodo: " << t.tipo() << endl;
                t.procesarPago(monto);
                break;
            }
            case 2: {
                Yape y("Luis", "987654321");
                cout << "Metodo: " << y.tipo() << endl;
                y.procesarPago(monto);
                break;
            }
            case 3: {
                Transferencia tr("Maria", "0021-456789");
                cout << "Metodo: " << tr.tipo() << endl;
                tr.procesarPago(monto);
                break;
            }
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);

    return 0;
}