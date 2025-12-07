#include <iostream>
#include "include/MenuOperativo.h"       // <- ajustar ruta
#include "include/MenuAdministrativo.h" 
using namespace std;

int pedirNumero() {
    int numero;
    while (true) {
        cin >> numero;

        if (cin.fail()) {
            cout << "Error: debes ingresar solo números. Intenta de nuevo: ";
            cin.clear();
            cin.ignore(1000, '\n');
        } else { 
            cin.ignore(1000, '\n');
            return numero;
        }
    }
}

void menuPrincipal();

int main()
{
    menuPrincipal();
    return 0;
}

 void menuPrincipal(){
    int opcion;

    do {
        system("cls");
        cout << "====== MENU PRINCIPAL ======\n";
        cout << "1. Menu Administrativo\n";
        cout << "2. Menu Operativo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        opcion = pedirNumero();
        

        switch (opcion) {
            case 1: {
            menuAdministrativo();
            break;
            }
            case 2: {
            menuOperativo();
            break;
            }
        }
    } while (opcion != 0);
}

