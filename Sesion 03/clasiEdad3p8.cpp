#include <iostream>
using namespace std;

int main(){
    int edad;

    cout<<"Ingrese una edad :\n";
    cout<<"=>";
    cin>>edad;
    cout<<endl;

    if(edad<0)
        cout<<"Edad negativa (invalido)\n";
    
    else if(edad>0 && edad<12)
        cout<<"Edad de un Ninyo(a)\n";

    else if(edad>13 && edad<17)
        cout<<"Edad de un Adolecente(a)\n";

    else if(edad>18 && edad<59)
        cout<<"Edad de un Adulto(a)\n";

    else  if(edad>60 && edad<90)
        cout<<"Edad de un Adulto Mayor(a)\n";

         else 
        {
            cout<<"Edad muy superior a una persona\n";
        }
        cout<<endl;

}
