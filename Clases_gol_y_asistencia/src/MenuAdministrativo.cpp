#include "MenuAdministrativo.h"
#include <iostream>
#include <limits>

#include "Club.h"
#include "Jugador.h"
#include "ArchivoJugador.h"
#include "ArchivoClub.h"
#include "ArchivoTorneo.h"
#include "Validaciones.h"
#include "Torneo.h"

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
        cout << "1. Registrar Club\n";
        cout << "2. Editar Club\n";
        cout << "3. Eliminar Club\n";
        cout << "4. Buscar Club por ID\n";
        cout << "5. Listar Clubes\n";
        cout << "6. Registrar Jugador\n";
        cout << "7. Editar Jugador\n";
        cout << "8. Eliminar Jugador\n";
        cout << "9. Listar Jugadores\n";
        cout << "10. Crear Fixture\n";
        cout << "11. Registrar Torneo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        opcion = leerEnteroConIntentos(3);


        system("cls");

        switch(opcion)
        {
            case 1:
            {
                cout << "\n=== REGISTRO DE CLUB ===\n";
                Club C;
                char confirm;
                do{
                    C.generarNuevoId();
                    C.cargar();

                    if(archivoClubes.guardar(C)){
                        cout << "Club registrado exitosamente.\n\n";
                        cin.get();
                        system("cls");
                    }
                    else cout << "Error al guardar el Club.\n";
                    cout << "Desea cargar otro Club? (S/N): " << endl;
                    confirm = leerOpcionSN();
                    system("cls");
                }while(confirm == 'S');
                break;
            }

            case 2:
            {
                cout << "\n=== EDITAR CLUB ===\n";
                int cantidad = archivoClubes.cantidadRegistros();
                for(int x = 0; x < cantidad; x++){
                    cout << archivoClubes.leerRegistro(x).getIdClub() << "- "
                         << archivoClubes.leerRegistro(x).getNombre() << endl;
                }

                cout << "\nIngrese el ID del club a editar: ";
                int id = leerEnteroEnRango(1, Club::getUltimoId());

                int pos = archivoClubes.buscar(id);
                Club findClub = archivoClubes.leerRegistro(pos);
                if (findClub.getIdClub() == 0) {
                    cout << "No se encontro el club con ese ID.\n";
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

                cin.get();
                break;
            }

            case 3:
            {
                cout << "\n==== ELIMINAR CLUB ====\n";
                cout << "Ingrese el ID del club a eliminar: ";
                int id = leerEnteroConIntentos(3);

                int pos = archivoClubes.buscar(id);

                if (pos == -1)
                    cout << "No se encontro el club con ese ID.\n";
                else {
                    Club c = archivoClubes.leerRegistro(pos);
                    cout << "\nClub encontrado:\n";
                    c.mostrar();

                    char confirm;
                    cout << "\n¿Desea eliminar este club? (S/N): ";
                    confirm = leerOpcionSN();

                    if (confirm == 'S') {
                        if (archivoClubes.eliminarRegistroFisico(id))
                            cout << "Club eliminado correctamente.\n";
                        else
                            cout << "Operación cancelada.\n";
                    }
                }

                cin.get();
                break;
            }

            case 4:
            {
                cout << "Ingrese ID del club: ";
                int id = leerEnteroConIntentos(3);

                Club* c = archivoClubes.buscarPorId(id);

                if (c != nullptr) {
                    cout << "\nClub encontrado:\n";
                    c->mostrar();
                } else {
                    cout << "Club no encontrado.\n";
                }
                cin.get();
                break;
            }

            case 5:
            {
                archivoClubes.listarRegistros();
                cin.get();
                break;
            }

            case 6:
            {
                cout << "\n=== REGISTRO DE JUGADOR ===\n";
                Jugador J;
                char confirm;
                do{
                    J.generarNuevoId();
                    if(J.cargar()){
                        if(archivoJugadores.guardarRegistro(J)){
                            cout << "Jugador registrado exitosamente.\n\n";
                            cin.get();
                            system("cls");
                        }
                        else {cout << "Error al guardar el Jugador.\n";}
                    }else{
                         cout << "Carga cancelada o incompleta. No se guardo el jugador.\n";
                    };

                    cout << "Desea cargar otro Jugador? (S/N): " << endl;
                    confirm = leerOpcionSN();
                    system("cls");

                }while(confirm == 'S');
                break;
            }

            case 7:
            {
                cout << "\n=== EDITAR JUGADOR ===\n";
                archivoJugadores.listarRegistros();
                cout << "\nIngrese el ID del jugador a editar: ";
                int id = leerEnteroEnRango(1, Jugador::getUltimoId());

                int pos = archivoJugadores.buscarPorId(id);

                if (pos == -1) {
                    cout << "Jugador no encontrado.\n";
                } else {
                    Jugador J = archivoJugadores.leerRegistro(pos);
                    cout << "\nDatos actuales del jugador:\n";
                    J.mostrar();

                    cout << "\nIngrese los nuevos datos:\n";
                    J.cargar();

                    if (archivoJugadores.modificarRegistro(J, pos))
                        cout << "Jugador modificado correctamente.\n";
                    else
                        cout << "Error al modificar el registro.\n";
                }

                cin.get();
                break;
            }

            case 8:
            {
                cout << "\n==== ELIMINAR JUGADOR ====\n";
                cout << "Ingrese el DNI del jugador a eliminar: ";
                int dni = leerEnteroConIntentos(3);

                int pos = archivoJugadores.buscarPorId(dni);

                if (pos == -1) {
                    cout << "Jugador no encontrado.\n";
                } else {
                    Jugador J = archivoJugadores.leerRegistro(pos);
                    cout << "\nJugador encontrado:\n";
                    J.mostrar();

                    char confirm;
                    cout << "\n¿Desea eliminar este jugador? (S/N): ";
                    confirm = leerOpcionSN();

                    if (confirm == 'S') {
                        if (archivoJugadores.eliminarRegistroFisico(dni))
                            cout << "Jugador eliminado correctamente.\n";
                        else
                            cout << "Error al eliminar el jugador.\n";
                    } else {
                        cout << "Operación cancelada.\n";
                    }
                }

                cin.get();
                break;
            }

            case 9:
            {
                archivoJugadores.listarRegistros();
                cin.get();
                break;
            }

            case 10:
            {
                ArchivoTorneo archTorneo("torneos.dat");
                archTorneo.crearFixture(1);
                cin.get();
                break;
            }

            case 11: {
                Torneo t;
                t.cargar();
                t.mostrar();
                break;

            }

            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "Opción inválida, intente nuevamente.\n";
            }




    } while(opcion != 0);
}
