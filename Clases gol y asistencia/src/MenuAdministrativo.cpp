#include "MenuAdministrativo.h"
#include <iostream>

#include "Club.h"
#include "Jugador.h"
#include "ArchivoJugador.h"
#include "ArchivoClub.h"
#include "ArchivoTorneo.h"

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
        cout << "10.Crear Fixture\n";
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
            cout << "\n=== EDITAR CLUB ===\n";
            int id, cantidad;

            cantidad = archivoClubes.cantidadRegistros();
            for(int x = 0; x < cantidad ; x++){
                cout << archivoClubes.leerRegistro(x).getIdClub() << "- " << archivoClubes.leerRegistro(x).getNombre() << endl;
            }

            cout << "\nIngrese el ID del club a editar: ";
            cin >> id;

            int pos = archivoClubes.buscar(id);
            Club findClub = archivoClubes.leerRegistro(pos);
            if (findClub.getIdClub() == 0) {
                cout << "No se encontró el club con ese ID.\n";
            } else {
                cout << "\nDatos actuales del club:\n";
                findClub.mostrar();

                cout << "\nIngrese los nuevos datos del club:\n";
                findClub.cargar();

                if (archivoClubes.modificarRegistro(findClub, pos)) {
                    cout << "Club modificado correctamente.\n";
                } else {
                    cout << "Error al modificar el registro.\n";
                }
            }

            cin.ignore();
            cin.get();
            break;
        }
        case 3:
        {
            cout << "\n==== ELIMINAR CLUB ====\n";
            int id;
            cout << "ingrese el ID del club a eliminar:";
            cin >> id;

            int pos = archivoClubes.buscar(id);

            if (pos == -1)
        {
            cout << "No se encontró el club con ese ID. \n";
        }
        else
        {
            Club c = archivoClubes.leerRegistro(pos);
            cout << "\nClub encontrado:\n";
            c.mostrar();

            char confirm;
            cout << "\n¿Desea eliminar este club? (S/N):";
            cin >> confirm;

            if (confirm == 'S' || confirm == 's')
        {
            if (archivoClubes.eliminarRegistroFisico(id))
            {
                cout << "Club eliminado correctamente. \n";
            }
            else
            {
                cout << "Operación cancelada. \n";
            }
        }

        cin.ignore();
        cin.get();
        break;
    }}

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
            archivoClubes.listarRegistros();
            cin.ignore();
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
            cout << "\n=== EDITAR JUGADOR ===\n";
            int dni;
            cout << "Ingrese el DNI del jugador a editar: ";
            cin >> dni;

            int pos = archivoJugadores.buscarPorId(dni);

            if (pos == -1) {
                cout << "Jugador no encontrado.\n";
            } else {
                Jugador J = archivoJugadores.leerRegistro(pos);
                cout << "\nDatos actuales del jugador:\n";
                J.mostrar();

                cout << "\nIngrese los nuevos datos:\n";
                J.cargar();

                if (archivoJugadores.modificarRegistro(J, pos)) {
                    cout << "Jugador modificado correctamente.\n";
                } else {
                    cout << "Error al modificar el registro.\n";
                }
            }

            cin.ignore();
            cin.get();
            break;
        }

        case 8:
        {
            cout << "\n==== ELIMINAR JUGADOR ====\n";
            int dni;
            cout << "Ingrese el DNI del jugador a eliminar:";
            cin >> dni;

            int pos = archivoJugadores.buscarPorId(dni);

            if (pos == -1)
        {
            cout << "Jugador no encontrado. \n";
        }
        else
        {
            Jugador J = archivoJugadores.leerRegistro(pos);
            cout << "\nJugador encontrado:\n";
            J.mostrar();

            char confirm;
            cout << "\n ¿Desea eliminar este jugador? (S/N):";
            cin >> confirm;

            if (confirm == 'S' || confirm == 's')
            {
                if (archivoJugadores.eliminarRegistroFisico(dni))
                {
                    cout << "Jugador eliminado correctamente.\n";
                }
                else
                {
                    cout << "Error al eliminar el jugador. \n";
                }
            }
            else
            {
                cout << "Operación cancelada. \n";
            }
        }
          cin.ignore();
          cin.get();
          break;
    }


        case 9:
        {
            archivoJugadores.listarRegistros();
            cin.ignore();
            cin.get();
            break;
        }

        case 10:{
            ArchivoTorneo archTorneo("torneos.dat");
            archTorneo.crearFixture(1);
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
