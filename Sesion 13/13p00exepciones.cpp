#include <iostream>

using namespace std;

int main()
{
    int divisor, dividiendo;
    float resultado;

    cout <<"ingresa el numero a dividir \n"; cout <<":"; cin >> dividiendo;
    cout <<"ingresa el divisor\n"; cout <<":"; cin >> divisor;

    try
    {
        if (dividiendo == 0)
        {
            throw "No  se puede dividir entre cero \n";
        return 0;
        }
        
    resultado = dividiendo / divisor;

    }    
    catch (const char *mensaje)
    {
        cout << mensaje;
    }

    cout <<"el resultado es: " << resultado << endl;
    

    try 
    {
        throw "10";
    }
    catch (int x)
    {
        cout << "Exepcion de nuemro entero " << endl;
    }

    catch (int c)
    {
        cout << "Exepcion de tipo char " << endl;
    }

    catch (...)
    {
        cout << "Exepcion desconocida " << endl;
    }


    int opcion;
    cout<<"1. Error entero"<<endl;
    cout<<"1. Error decimal"<<endl;
    cout<<"1. Otro error"<<endl;

    cin>>opcion;

    try{

        if(opcion==1){
            throw 10;
        }
        
        if(opcion==2){
            throw 4.36;
        }
        throw "error desconocido";
    }
    catch (int n)
    {
        cout <<  "Error de tipo entero " << endl;
    }
    catch (double d)
    {
        cout << "Error de tipo decimal " << endl;
    }
    catch (const char *n)
    {
        cout << "n " << endl;
    }
    catch(...)
    {
        cout << "Error desconocido"<< endl;
    }

return 0;
}