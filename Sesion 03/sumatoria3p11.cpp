#include <iostream>
using namespace std;

int main(){
    int par = 0, impar = 0;
    for(int i=0; i <=100;i++)
    {
        if (i % 2 == 0)
        {
            par += i;
        }
        else 
        {
            impar += i;
        }
        
    } 
    cout<<"El numero de pares es : " << par<<endl;
    cout<<"El numero de impares es : " << impar<<endl;
    
}

