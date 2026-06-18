#include <string>
#include <iostream>

using namespace std;

class Persona
{
private:
    int id;
    string dni;
    string nombres;
    string ap_paterno;
    string ap_materno;
    string fecha_nacimiento;
    string direccion;
    string telefono;
    int edad;

public:
    Persona()
    {
    }
    Persona(string _dni, string _nombre, string _paterno, string _materno)
    {
        this->dni = _dni;
        this->nombres = _nombre;
        this->ap_paterno = _paterno;
        this->ap_materno = _materno;
    }

    int get_id()
    {
        return this->id;
    }
    void set_id(int _id)
    {
        this->id = _id;
    }
    string get_dni()
    {
        return this->dni;
    }
    void set_dni(string _dni)
    {
        this->dni = _dni;
    }
    string get_nombre()
    {
        return this->nombres;
    }
    void set_nombre(string _nombre)
    {
        this->nombres = _nombre;
    }
    string get_paterno()
    {
        return this->ap_paterno;
    }
    void set_paterno(string _paterno)
    {
        this->ap_paterno = _paterno;
    }
    string get_materno()
    {
        return this->ap_materno;
    }
    void set_materno(string _materno)
    {
        this->ap_materno = _materno;
    }

    void saludar()
    {
        cout << "Hola:  " << this->nombres << " ," << this->ap_paterno << " " << this->ap_materno << endl;
    }
};