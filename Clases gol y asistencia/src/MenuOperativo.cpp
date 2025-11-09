#include "MenuAdministrativo.h"
#include <iostream>

using namespace std;


void menuOperativo()
{

    int opcion;

    do
    {
        system("cls");
        cout << "\n==== AREA OPERATIVA ====\n";
        cout << "1.Registrar resultado\n";
        cout << "2.Consultar tabla posiciones\n";
        cout << "3.Ver tabla goleadores\n";
        cout << "4.Ver tabla asistidores\n";

        cout << "0.Salir\n";
        cout << "Seleccione una opcion:";
        cin >> opcion;
        cin.ignore();
        system("cls");
        switch(opcion)
        {

        case 1:
        {
            cin.get();
            break;
        }
        case 2:
        {
            cin.get();
            break;
        }


        case 0:
            cout << "\nSaliendo del sistema...\n";
            break;

        default:
            cout << "Opción inválida intente nuevamente.\n";
        }
    }
    while(opcion != 0);


}
