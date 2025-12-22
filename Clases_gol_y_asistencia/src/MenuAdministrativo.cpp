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



void menuAdministrativo() {
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

        if (opcion == -1) {
            cout << "Volviendo al menu...\n";
            cin.get();
            continue;
        }
        

        system("cls");

        switch(opcion) {

         case 1:
        {
            int op = -1;
    
            do {
                system("cls");
                cout << "\n=== REGISTRO DE CLUB ===\n";
                cout << "1. Cargar club\n";
                cout << "0. Volver atras\n";
                cout << "Seleccione una opcion: ";
    
                op = leerEnteroConIntentos(3);
    
                if (op == -1) {
                    cout << "\nOperacion cancelada. Volviendo...\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    return;
                }
    
                if (op == 0) {
                    return;             }
    
                if (op == 1) {
                    char confirm = 'N';
    
                    do {
                        Club C;
                        C.generarNuevoId();
                        C.cargar();
    
                        if (archivoClubes.guardar(C))
                            cout << "\nClub registrado correctamente.\n";
                        else
                            cout << "\nError al guardar el club.\n";
    
                        cout << "\nDesea cargar otro club? (S/N): ";
                        confirm = leerOpcionSN();
    
                    } while (confirm == 'S');
                }
    
            } while (true);
    
            break;
        }
 
  
    case 2: {
        ArchivoClub archivoClubes("clubes.dat");


        int cantidad = archivoClubes.CantidadRegistros();
        if (cantidad == 0) {
            cout << "No hay clubes registrados.\n";
            cin.get();
            break;
        }
        
        system("cls");
        cout << "\n=== EDITAR CLUB ===\n";

        for (int x = 0; x < cantidad; x++) {
            cout << archivoClubes.leerRegistro(x).getIdClub() << "- "
                 << archivoClubes.leerRegistro(x).getNombre() << endl;
        }

        cout << "\nIngrese el ID del club a editar (0 para volver):";
        int id = leerEnteroConIntentos(3);
        if (id == 0) break;

        int pos = archivoClubes.buscar(id);
        if (pos == -1) {
            cout << "No se encontro el club con ese ID..\n";
            cin.get();
            break;
        }

        Club findClub = archivoClubes.leerRegistro(pos);
        cout << "\nDatos actuales del club:\n";
        findClub.mostrar();

        cout << "\nDesea editar el nombre del club? (S/N):";
        char editar = leerOpcionSN();
        if (editar != 'S') break;


            string nuevoNombre;
            bool nombreValido = false;
            int intentos = 0;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (intentos < 3) {
                cout << "Ingrese nuevo nombre (solo letras y espacios) o 0 para cancelar:";
                getline(cin, nuevoNombre);

                if (nuevoNombre == "0") {
                    cout << "Edicion cancelada. Volviendo al menu...\n";
                    cin.get();
                    break;
                }

                if (validarSoloLetrasEspacios(nuevoNombre.c_str())) {
                    nombreValido = true;
                    break;
                } else {
                    intentos++;
                    cout << "Nombre invalido. intento" << intentos << " de 3. \n";
                }
            }

            if (nombreValido) {
                findClub.setNombre(nuevoNombre);
                if (archivoClubes.modificarRegistro(findClub, pos))
                    cout << "Club modificado correctamente.\n";
            }

            cout << "\nPresione ENTER para volver...\n";
            cin.get();
            break;
        }
    

            case 3: {
                int cantidad = archivoClubes.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay clubes registrados.\n";
                    cin.get();
                    break;
                }

                system("cls");
                cout << "\n==== ELIMINAR CLUB ====\n";

                for (int x = 0; x < cantidad; x++) {
                    Club c = archivoClubes.leerRegistro(x);
                    cout << c.getIdClub() << "- " << c.getNombre() << endl;
                }

                cout << "Ingrese el ID del club a eliminar (0 para volver): ";
                int id = leerEnteroConIntentos(3);
                if (id == 0) break;

                int pos = archivoClubes.buscar(id);
                if (pos == -1) {
                    cout << "No se encontro el club con ese ID.\n";
                    cin.get();
                    break; 
                }

                Club c = archivoClubes.leerRegistro(pos);
                cout << "\nClub encontrado:\n";
                c.mostrar();

                cout << "\nDesea eliminar este club? (S/N): ";
                char confirm = leerOpcionSN();
                if (confirm != 'S') {
                    cout << "Eliminacion cancelada. Volviendo al menu...\n";
                    cin.get();
                    break;
                }

                if (archivoClubes.eliminarRegistroFisico(id)) {
                    cout << "Club eliminado correctamente.\n";
                } else {
                    cout << "Error al eliminar el club.\n";
                }
                    cin.get();
                    break;
            }

            case 4: {
                system("cls");
                cout << "Ingrese ID del club: ";

                cout << "Ingrese ID del club (0 para volver):";
                int id = leerEnteroConIntentos(3);
                if (id == 0) break;

                Club* c = archivoClubes.buscarPorId(id);

                if (c != nullptr) {
                    cout << "\nClub encontrado:\n";
                    c->mostrar();
                } else {
                    cout << "Club no encontrado.\n";
                }

                cout << "\nPresione ENTER para volver...\n";
                cin.get();
                break;
            }

            case 5: {
                system("cls");
                cout << "\n=== LISTA DE CLUBES ===\n";

                int cantidad = archivoClubes.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay clubes registrados.\n";
                } else {
                    archivoClubes.listarRegistros();
                }

                cout << "\nPrecione ENTER para volver al menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();

                break;
            }

            case 6: {
                system("cls");
                cout << "\n=== REGISTRO DE JUGADOR ===\n";

                Jugador J;
                char confirm;

                do{
                    J.generarNuevoId();

                    if(J.cargar()){
                        if(archivoJugadores.guardarRegistro(J)){
                            cout << "Jugador registrado exitosamente.\n\n";
                        } else { 
                            cout << "Error al guardar el Jugador.\n";
                        }

                    }else {
                         cout << "Carga cancelada o incompleta. No se guardo el jugador.\n";
                    }

                    cout << "Desea cargar otro Jugador? (S/N): " << endl;
                    confirm = leerOpcionSN();

                }while(confirm == 'S');
                break;
            }

            case 7: {
                system("cls");
                cout << "\n=== EDITAR JUGADOR ===\n";

                int cantidad = archivoJugadores.getCantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay jugadores registrados. \n";
                    cin.get();
                    break;
                }

                archivoJugadores.listarNombreApellido();

                cout << "\nIngrese el ID del jugador a editar (0 para volver): ";
                int dni = leerEnteroEnRango(0, 99999999);
                if (dni == 0) break;

                int pos = archivoJugadores.buscarPorDni(dni);
                if (pos == -1) {
                    cout << "Jugador no encontrado.\n";
                    cin.get();
                    break;
                }
                    Jugador J = archivoJugadores.leerRegistro(pos);
                    cout << "\nDatos actuales del jugador:\n";
                    J.mostrar();

                    cout << "\nIngrese los nuevos datos (0 para cancelar en cualquier campo):\n";
                    if (J.cargar()) {
                        if (archivoJugadores.modificarRegistro(J, pos)) {
                        cout << "Jugador modificado correctamente.\n";
                    } else {
                        cout << "Error al modificar el registro.\n";
                }
            } else {
                cout << "Edicion cancelada. No se modifico el jugador.\n";
            }
                cout << "\nPrecione ENTER para volver...\n";
                cin.get();
                break;
            }

            case 8:
            {
                cout << "\n==== ELIMINAR JUGADOR ====\n";
                cout << "Ingrese el DNI del jugador a eliminar: ";
                int dni = leerEnteroConIntentos(3);

                int pos = archivoJugadores.buscarPorDni(dni);

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
