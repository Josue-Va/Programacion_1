#include <iostream>
using namespace std;

int main(){
    int compra1, compra2;

    cout<<"Aproveche el descuento\n";
    cout<<"Ingrese el monto de su compra\n";
    cout<<"=>";
    cin>>compra1;
    cout<<endl;

    if(compra1<100)
      cout<<"No hay descuento\n";

    else if (compra1>100 && compra1<199){
      cout<<"Descuento es" <<compra1*0.01 <<endl; 
      cout<<"Nueva compra es :" <<compra1 -(compra1*0.01)<<endl;
    }

    else if (compra1>200 && compra1<499){
       cout<<"Descuento es :" <<compra1*0.02<<endl; 
       cout<<"Nueva compra es :" <<compra1 -(compra1*0.02)<<endl;
    }

    else {
       cout<<"Descuento es" <<compra1*0.05 <<endl; 
       cout<<"Nueva compra es :" <<compra1 -(compra1*0.05);
    }    
    cout<<endl;

}