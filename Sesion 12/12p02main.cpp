#include "12p01vehiculo.cpp"   // Incluye todas las clases
#include <iostream>
using namespace std;

int main() {
    // 1. Crear vehículos (independientes del garaje)
    Moto* moto1 = new Moto("Yamaha", "MT-07", false);
    Moto* moto2 = new Moto("Honda", "CBR500", true);
    Coche* coche1 = new Coche("Toyota", "Corolla", 4);
    Coche* coche2 = new Coche("Tesla", "Model S", 5);

    // 2. Crear garaje y agregar vehículos (AGREGACIÓN)
    Garaje miGaraje;
    miGaraje.agregarVehiculo(moto1);
    miGaraje.agregarVehiculo(coche1);
    miGaraje.agregarVehiculo(coche2);

    // 3. Listar vehículos en el garaje
    miGaraje.listarVehiculos();

    // 4. Acelerar y frenar todos
    miGaraje.acelerarTodos(30);
    miGaraje.frenarTodos(15);

    // 5. Eliminar un vehículo del garaje (sigue existiendo)
    miGaraje.eliminarVehiculo(coche1);
    miGaraje.listarVehiculos();

    // 6. Agregar otro vehículo que ya existía
    miGaraje.agregarVehiculo(moto2);
    miGaraje.listarVehiculos();

    // 7. Los vehículos pueden seguir usándose independientemente
    cout << "\n--- Usando moto1 fuera del garaje ---\n";
    moto1->acelerar(20);
    moto1->mostrarInfo();

    // 8. Liberar memoria (los vehículos son independientes)
    delete moto1;
    delete moto2;
    delete coche1;
    delete coche2;

    return 0;
}