#include <iostream>
using namespace std;

void porValor(int x)
{
    x = x*2,
    cout << "Dentro del rango"<< x << endl;
}

void porReferencia(int &x)
{
    x + x*2,
    cout << "Fuera del Rango" << x << endl;
}
    int main ()
    {
        int a = 10;
        porValor(a);
        cout << "Fuera del Rango" << a << endl;

        int b = 10;
        porReferencia(b);
        cout << "Fuera del Rango" << b << endl;

        return 0;
    }




