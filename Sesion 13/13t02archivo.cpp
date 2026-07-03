/*
Crear un programa que lea un archivo .txt y que maneje excepciones si
el archivo no existe.
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo .txt: ";
    std::getline(std::cin, nombreArchivo);

    try {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            throw std::string("No se pudo abrir el archivo: " + nombreArchivo);
        }

        std::cout << "Contenido del archivo:\n";
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }

        archivo.close();
    } catch (const std::string& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
