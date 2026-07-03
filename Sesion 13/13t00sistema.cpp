/*
Desarrolle un programa que simule un sistema Bancario,
que lance una exepcion, si se supera el saldo a retirar.
*/

#include <iostream>
#include <string>

int main() {
    double saldo = 1000.0;
    double retiro = 0.0;

    std::cout << "Saldo actual: " << saldo << std::endl;
    std::cout << "Ingrese el monto a retirar: ";
    std::cin >> retiro;

    try {
        if (retiro > saldo) {
            throw std::string("Error: saldo insuficiente para el retiro.");
        }
        if (retiro < 0.0) {
            throw std::string("Error: el monto a retirar no puede ser negativo.");
        }

        saldo -= retiro;
        std::cout << "Retiro exitoso." << std::endl;
        std::cout << "Saldo restante: " << saldo << std::endl;
    } catch (const std::string& error) {
        std::cerr << error << std::endl;
        return 1;
    }

    return 0;
}
