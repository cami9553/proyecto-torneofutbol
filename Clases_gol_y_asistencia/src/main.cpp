#include <iostream>
#include "../include/MenuOperativo.h"   
#include "../include/MenuAdministrativo.h" 
#include "../include/Validaciones.h"
using namespace std;

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

        bool valido = false;
        while (!valido) {
            cout << "Seleccione una opcion: ";
            opcion = leerEnteroConIntentos(3);

            if(opcion == -1) {
                cout << "Se alcanzo el maximo de intentos. Volviendo al menu...\n";
                break;
            }
            if(opcion >= 0 && opcion <= 2) {
                valido = true;
            } else {
                cout << "Opcion invalida. Intente de nuevo.\n";
            }
        }
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

    cout << "Saliendo del programa..." << endl;
}
