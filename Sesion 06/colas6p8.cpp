#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> colas;

    colas.push(12);
    colas.push(13);
    colas.push(14);
    colas.push(15);
    colas.push(16);

    cout<< "El primer elemento: "<<colas.front()<<endl;

    cout<< "El ultimo elemento: "<<colas.back()<<endl;

    colas.pop();
    cout<< "El primer elemento: "<<colas.front()<<endl;

    cout<< "Tamanyo: "<<colas.size();
    


}