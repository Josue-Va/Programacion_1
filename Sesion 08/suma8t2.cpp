#include <iostream>
#include <string>

using namespace std;

int main () {
    int num1, num2, suma;

    cout << "SUMA\n";
    cout << "Primer valor :\n"; cin >> num1;
    cout << "Segundo valor :\n"; cin >> num2;

        int *pter1 = &num1;
        int *pter2 = &num2;
        suma = *pter1 + *pter2;


    cout << "la suma es : "<< suma;

    return 0;
}