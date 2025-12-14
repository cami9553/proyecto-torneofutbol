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


// validacion para leer un entero en un rango dado
int leerEnteroEnRango(int min, int max) {
    int valor;
    do {
        valor = leerEntero();
        if (valor < min || valor > max) {
            cout << "Error: El valor debe estar entre " << min << " y " << max << ". Intente nuevamente: ";
        }
    } while (valor < min || valor > max);
    return valor;
}

// validacion para opcion si o no (S/N)
char leerOpcionSN() {
    char opcion;
    string entrada;
    
    while (true) {
        getline(cin, entrada);
        
        if (entrada.length() == 1) {
            opcion = toupper(entrada[0]);
            if (opcion == 'S' || opcion == 'N') {
                return opcion;
            }
        }
        cout << "Error: Debe ingresar 'S' o 'N'. Intente nuevamente: ";
    }
}
