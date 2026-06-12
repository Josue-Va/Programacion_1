#include <iostream>
using namespace std;

int main() {
    
    string clave = "2026", clave2, tarjeta = "4578", tarjeta2, opcion;
    int saldo = 500, retiro, deposito; 
    
    do{
        do{
            cout << "Digite la tarjeta : "; cin >> tarjeta2;
            if (tarjeta2 != tarjeta)
                cout << "No existe dicha tarjeta !!!!" << endl;
        } while(tarjeta2 != tarjeta);
        
        cout << "Tarjeta encontrada" << endl;
        
        cout << "Digite la contrasenya : "; cin >> clave2;
        if (clave2 != clave)
            cout << "No es la contrasenya correcta !!!!" << endl;
        
    } while(clave2 != clave);
    
    cout << "Acceso autorizado" << endl;
    cout << endl;
    
    do{
        cout << endl;
        cout << "-----OPCIONES DE MENU------\n\n";
        cout << "1. Consultar Saldo\n";
        cout << "2. Realizar Retiro\n";
        cout << "3. Realizar Deposito\n";
        cout << "4. Cambio de Contrasenia\n";
        cout << "5. Autentificarse Nuevamente\n";
        cout << "6. Salir\n\n";
        
        cout << "Elija una opcion => : ";cin >> opcion;
        
        if(opcion == "1")      //opcion 1
        {
            cout << "\nConsultar Saldo...." << endl;
            cout << "\nSaldo : " << saldo << " soles" << endl;
        }
        
        else if(opcion == "2")   //opcion 2
        {
            cout << "\nRealizar Retiro..." << endl;
            do{
                cout << "Digite el monto a retirar : ";cin >> retiro;
                
                if(retiro <= 0)
                    cout << "Monto invalido. Digite un monto positivo." << endl;
                else if(retiro > saldo)
                    cout << "Saldo insuficiente. Su saldo actual es: " << saldo << " soles" << endl;
                else{
                    saldo = saldo - retiro;
                    cout << "\nRetiro exitoso. Nuevo saldo: " << saldo << " soles" << endl;
                }
            } while(retiro <= 0 || retiro > saldo);
        }
        
        else if(opcion == "3")    //opcion 3
        {
            cout << "\nRealizar Deposito..." << endl;
            do{
                cout << "Digite el monto a depositar : ";cin >> deposito;
                
                if(deposito <= 0)
                    cout << "Monto invalido. Digite un monto positivo." << endl;
                else{
                    saldo = saldo + deposito;
                    cout << "\nDeposito exitoso. Nuevo saldo: " << saldo << " soles" << endl;
                }
            } while(deposito <= 0);
        }
        
        else if(opcion == "4")     //opcion 4 
        {
            cout << "\nCambio de Contrasenia..." << endl;
            string claveActual, nuevaClave, confirmar;
            
            cout << "Digite su contrasenya actual: ";cin >> claveActual;
            
            if(claveActual == clave)
            {
                cout << "Digite la nueva contrasenya: ";cin >> nuevaClave;
                cout << "Confirme la nueva contrasenya: ";cin >> confirmar;
                
                if(nuevaClave == confirmar)
                {
                    clave = nuevaClave;
                    cout << "\nContrasenya cambiada exitosamente." << endl;
                }
                else
                    cout << "\nLas contrasenyas no coinciden. Cambio cancelado." << endl;
            }
            else
                cout << "\nContrasenya actual incorrecta. Cambio cancelado." << endl;
        }
        
        else if(opcion == "5")  //opcion 5
        {
            cout << "\nAutentificarse Nuevamente..." << endl;
            string tarjetaTemp, claveTemp;
            bool autenticado = false;
            
            do{
                cout << "Digite la tarjeta : ";cin >> tarjetaTemp;
                
                if(tarjetaTemp != tarjeta)
                    cout << "No existe dicha tarjeta !!!!" << endl;
                else
                {
                    cout << "Digite la contrasenya : ";cin >> claveTemp;
                    
                    if(claveTemp != clave)
                        cout << "Contrasenya incorrecta !!!!" << endl;
                    else
                    {
                        autenticado = true;
                        cout << "\nRe-autenticacion exitosa." << endl;
                    }
                }
            } while(!autenticado);
        }
        
        else if(opcion == "6")   //opcion 6
        {
            cout << "\nSaliendo del sistema..." << endl;
        }
        
        else      // opcion invalidad
        {
            cout << "\nOpcion no valida. Digite una opcion del 1 al 6." << endl;
        }
        
    } while(opcion != "6");
    cout << "\nAdios" << endl;
    return 0;
}