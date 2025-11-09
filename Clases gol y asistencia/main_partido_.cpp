#include <iostream>
#include "Partido.h"
using namespace std;

int main() {
    Partido p1;

    cout << "=== CARGAR PARTIDO ===" << endl;
    p1.cargar();

    cout << "\n=== MOSTRAR PARTIDO ===" << endl;
    p1.mostrar();

    return 0;
}