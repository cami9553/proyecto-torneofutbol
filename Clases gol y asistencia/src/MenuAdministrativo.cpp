#include "MenuAdministrativo.h"
#include <iostream>

#include "Club.h"
#include "Jugador.h"
#include "ArchivoJugador.h"
#include "ArchivoClub.h"
using namespace std;


void menuAdministrativo()
{

    ArchivoJugador archivoJugadores("jugadores.dat");
    ArchivoClub archivoClubes("clubes.dat");
    int opcion;

    do
    {
        system("cls");
        cout << "\n==== AREA ADMINISTRATIVA ====\n";
        cout << "1.Registrar Club\n";
        cout << "2.Editar Club\n";
        cout << "3.Eliminar Club\n";
        cout << "4.Buscar Club por ID\n";
        cout << "5.Listar Clubes\n";


        cout << "6.Registrar Jugador\n";
        cout << "7.Editar Jugador\n";
        cout << "8.Eliminar Jugador\n";
        cout << "9.Listar Jugadores\n";

        cout << "0.Salir\n";
        cout << "Seleccione una opcion:";
        cin >> opcion;
        cin.ignore();
        system("cls");
        switch(opcion)
        {

        //CRUD CLUB (1 AL 5)
        case 1:
        {
            cout << "\n=== REGISTRO DE CLUB ===\n";
            Club C;
            ArchivoClub archivoClubes("clubes.dat");

            C.cargar();
            if(archivoClubes.guardar(C))
            {
                cout << "Club registrado exitosamente.\n";
            }
            else
            {
                cout << "Error al guardar el Club.\n";
            }
            cin.get();
            break;
        }
        case 2:
        {
            cin.get();
            break;
        }
        case 3:
        {
            cin.get();
            break;
        }

        case 4:
        {
            int id;
            cout << "Ingrese ID del club: ";
            cin >> id;

            Club* c = archivoClubes.buscarPorId(id);

            if (c != nullptr)
            {
                cout << "\nClub encontrado:\n";
                c->mostrar();

            }
            else
            {
                cout << "Club no encontrado.\n";
            }
            cin.ignore();
            cin.get();
            break;
        }


        case 5:
        {
            cout << "\n=== LISTA DE CLUBES ===\n";

            int cantidad = archivoClubes.cantidadRegistros();
            Club C;
            for(int i = 0; i < cantidad; i++)
            {
                C = archivoClubes.leerRegistro(i);
                cout << "\nClub #" << i+1 << endl;
                C.mostrar();
            }
            cin.get();
            break;
        }


        //CRUD JUGADORES ()
        case 6:
        {
            cout << "\n=== REGISTRO DE JUGADOR ===\n";
            Jugador J;
            J.cargar();
            if(archivoJugadores.guardarRegistro(J))
            {
                cout << "jugador registrado exitosamente.\n";
            }
            else
            {
                cout << "Error al guardar el jugador.\n";
            }
            break;
        }

        case 7:
        {
            cin.get();
            break;
        }
        case 8:
        {
            cin.get();
            break;
        }
        case 9:
        {
            cout << "\n=== LISTA DE JUGADORES ===\n";
            int cantidad = archivoJugadores.getCantidadRegistros();
            Jugador J;
            for(int i = 0; i < cantidad; i++)
            {
                J = archivoJugadores.leerRegistro(i);
                J.mostrar();
            }
            cin.ignore();
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
