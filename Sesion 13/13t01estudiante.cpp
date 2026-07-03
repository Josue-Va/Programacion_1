/* 
Crear una clase estudiante que contenga un atributo promedio y que 
genere una exepcion si la nota esta fuera del rango [0 - 20]
*/

#include <iostream>
#include <string>

class estudiante {
private:
    double promedio;

public:
    estudiante(double promedio) {
        setPromedio(promedio);
    }

    double getPromedio() const {
        return promedio;
    }

    void setPromedio(double valor) {
        if (valor < 0.0 || valor > 20.0) {
            throw std::string("El promedio debe estar en el rango [0 - 20]");
        }
        promedio = valor;
    }
};

int main() {
    try {
        std::cout << "Ingrese el promedio del estudiante: ";
        double valor;
        std::cin >> valor;

        estudiante est(valor);
        std::cout << "Promedio guardado: " << est.getPromedio() << '\n';
    } catch (const std::string& e) {
        std::cerr << "Error: " << e << '\n';
        return 1;
    }

    return 0;
}
