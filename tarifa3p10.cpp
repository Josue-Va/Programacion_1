#include <iostream>
using namespace std;

int main(){
    int tipo, monto;


    cout<<"Ingrese le tipo de cliente: 1 normal, 2 Vip, 3 Premium\n";
    cout<<"=>"; cin>>tipo;
    
    cout<<"Ingrese le monto de compra\n";
    cout<<"=>"; cin>>monto;

    switch (tipo)
    {
        case 1:
            cout <<" Monto a pagar es : "<<monto<<endl;
            break;
        case 2:
            cout <<" Monto a pagar es : "<<monto - monto*0.2 <<endl;
            break;

        case 3:
            cout <<" Monto a pagar es : "<<monto - monto*0.3 <<endl;
            break;
        default:
            break;
    }
}