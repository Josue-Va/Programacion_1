#include <iostream>
using namespace std;

int main() {
    char letra = 'e';

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        cout << "La letra '" << letra << "' es una vocal." << endl;
    } else {
        cout << "La letra '" << letra << "' es una consonante." << endl;
    }

    return 0;
}