#include <iostream>
using namespace std;
int contador = 0;

int funcion_1 (int contador)
{
    return contador = 10;
    
}
int funcion_2 (int contador)
{
    return contador + 5;

}

    int main ()
    {
        
        int contador = 0; 
        contador = funcion_1(contador);
        contador = funcion_2(contador);

        cout << contador;
        return 0;

    }