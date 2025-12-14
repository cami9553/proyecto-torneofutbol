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
        cout << "Seleccione una opcion: ";
        
        opcion = leerEntero();

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

