#include <iostream>
#include "Validaciones.h"
#include <limits>
#include <string>

using namespace std;

int leerEntero() {
    int num;
       while (true) {
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: debe ingresar un número. Intente de nuevo: ";
        } else {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          return num;
        }  
      }
}  
