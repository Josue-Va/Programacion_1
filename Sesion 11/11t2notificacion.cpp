/*
Aplicacion que envia notificaciones a traves de diferentes canales 
(correo, sms, token), cada notificacion debe tener un mensaje y un destinatario.
El formato y la forma varian segun el canal.
*/

#include <iostream>
#include <string>
using namespace std;

                        // clase base.
class Notificacion {
protected:
    string destinatario;
    string mensaje;

public:
    Notificacion(string dest, string msg) 
        : destinatario(dest), mensaje(msg) {}

    virtual ~Notificacion() {}

    virtual void enviar() = 0;
    virtual void enviarPrioritario() = 0;
    virtual void reenviar() = 0;
};

                 // correo electronico.
class NotificacionCorreo : public Notificacion {
public:
    NotificacionCorreo(string dest, string msg) : Notificacion(dest, msg) {}

    void enviar() override {
        cout << "\nCORREO Enviando a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }

    void enviarPrioritario() override {
        cout << "\nCORREO PRIORITARIO *** URGENTE *** a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }

    void reenviar() override {
        cout << "\nCORREO REENVIO Reenviando a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }
};

                 // sms.
class NotificacionSMS : public Notificacion {
public:
    NotificacionSMS(string dest, string msg) : Notificacion(dest, msg) {}

    void enviar() override {
        cout <<endl;
        cout << "\nSMS Enviando a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje.substr(0, 160) << endl;
    }

    void enviarPrioritario() override {
        cout << "\nSMS URGENTE >>> ALERTA <<< a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje.substr(0, 160) << endl;
    }

    void reenviar() override {
        cout << "\nSMS REENVIO. Reenviando a: " << destinatario << endl;
        cout << "Mensaje: reenviado " << mensaje.substr(0, 160) << endl;
    }
};

                 // token (push)
class NotificacionToken : public Notificacion {
public:
    NotificacionToken(string dest, string msg) : Notificacion(dest, msg) {}

    void enviar() override {
        cout <<endl;
        cout << "\nTOKEN Enviando a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }

    void enviarPrioritario() override {
        cout << "\nTOKEN PRIORITARIO alerta a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }

    void reenviar() override {
        cout << "\nTOKEN REENVIADO. Reenviando a: " << destinatario << endl;
        cout << "Mensaje: " << mensaje << endl;
    }
};

// programa principal
int main() {
    cout << ".. NOTIFICACIONES correo, sms, token ..\n";

    // Crear notificaciones
    NotificacionCorreo correo("usuario@email.com", "Hola, tu pedido ha sido confirmado");
    NotificacionSMS sms("+34 600123456", "Tu codigo es: 123456");
    NotificacionToken token("user_001", "Tienes un nuevo mensaje");

    // Enviar correos
    correo.enviar();
    correo.enviarPrioritario();
    correo.reenviar();

    // Enviar SMS
    sms.enviar();
    sms.enviarPrioritario();
    sms.reenviar();

    // Enviar tokens
    token.enviar();
    token.enviarPrioritario();
    token.reenviar();

    cout << "\n ... \n";

    return 0;
}