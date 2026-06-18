
// Genear el id de manera automatica y unica para cada persona creada
#include <iostream>
#include <string>
using namespace std;

class Persona {
    private:
    // variables o atributos de tipo privado
        int id;
        string dni;
        string nombre;
        string ap_paterno;
        string ap_materno;
        string fecha_nacimiento;
        string direccion;
        string telefono;
        int edad;
    public:
    // constructor
        Persona(){

        }
        Persona(int _id, string _dni, string _nombre, string _ap_paterno, string _ap_materno, string _fecha_nacimiento, string _direccion, string _telefono, int _edad){
            this->id = _id;
            this->dni = _dni;
            this->nombre = _nombre;
            this->ap_paterno = _ap_paterno;
            this->ap_materno = _ap_materno;
            this->fecha_nacimiento = _fecha_nacimiento;
            this->direccion = _direccion;
            this->telefono = _telefono;
            this->edad = _edad;
        }
        //getters -> metodos para obtener el valor de las variables privadas , setters -> metodos para asignar un valor a las variables privadas
        int getId(){ // metodo para obtener el valor de id
            return id;
        }
        void setId(int _id){ // metodo para asignar un valor a id
            this->id = _id;
        }
        string getDni(){ // metodo para obtener el valor de dni
            return dni;
        }
        void setDni(string _dni){ // metodo para asignar un valor a dni
            this->dni = _dni;
        }
        string getNombre(){ // metodo para obtener el valor de nombre
            return nombre;
        }
        void setNombre(string _nombre){ // metodo para asignar un valor a nombre
            this->nombre = _nombre;
        }
        string getApPaterno(){ // metodo para obtener el valor de ap_paterno
            return ap_paterno;
        }
        void setApPaterno(string _ap_paterno){ // metodo para asignar un valor a ap_paterno
            this->ap_paterno = _ap_paterno;
        }
        string getApMaterno(){ // metodo para obtener el valor de ap_materno
            return ap_materno;
        }
        void setApMaterno(string _ap_materno){ // metodo para asignar un valor a ap_materno
            this->ap_materno = _ap_materno;
        }
        string getFechaNacimiento(){ // metodo para obtener el valor de fecha_nacimiento
            return fecha_nacimiento;
        }
        void setFechaNacimiento(string _fecha_nacimiento){ // metodo para asignar un valor a fecha_nacimiento
            this->fecha_nacimiento = _fecha_nacimiento;
        }
        string getDireccion(){ // metodo para obtener el valor de direccion
            return direccion;
        }
        void setDireccion(string _direccion){ // metodo para asignar un valor a direccion
            this->direccion = _direccion;
        }
        string getTelefono(){ // metodo para obtener el valor de telefono
            return telefono;
        }
        void setTelefono(string _telefono){ 
            this->telefono = _telefono;
        }
        int getEdad(){ // metodo para obtener el valor de edad
            return edad;
        }
        void setEdad(int _edad){ 
            this->edad = _edad;
        }

        void Saludar (){ // metodo para saludar
            cout << "Hola, mi nombre es " << this->nombre << " " << this->ap_paterno << " " << this->ap_materno << endl;
        }

};

