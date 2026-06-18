#include <iostream>
using namespace std;

int main (){
int edad = 20;

cout<<"El valor de la variable edad es: "<<edad<<endl;
cout<<"La direccion de la variable edad es: "<<&edad<<endl;

int *puntero = &edad;

*puntero = 50;

edad = 20;
cout<<"La valor de la variable edad es: "<<*puntero<<endl;
cout<<"La direccion de la variable edad es: "<<puntero<<endl;

cout<<"El valor de la variable edad es: "<<edad<<endl;
cout<<"La direccion de la variable edad es: "<<&edad<<endl;


/*
    & operador para mostrar la direccion de la memoria
    * operador para declararnuna varible de ipo puntero
    puntero guarda la direccion de la memoria
    *puntero apunta el lugar guardado

    int datos [3] = {45, 35, 75}

    int *p = datos;

    *p = 50
    *(p+1) = 60
    *(p+2) = 70

        RESTA

    resta el 3er menos 1er.
    resta = *(p+2) - *p

    INVERTIR ORDEN
    for(int=3; i>0; i--)
    {
    cout<< "i" *(p+2);
    }

*/
return 0;
}