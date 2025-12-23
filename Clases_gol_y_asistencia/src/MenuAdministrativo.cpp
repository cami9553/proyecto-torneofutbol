#include <iostream>
#include <limits>
#include "Club.h"
#include "Jugador.h"
#include "ArchivoJugador.h"
#include "ArchivoClub.h"
#include "ArchivoTorneo.h"
#include "Validaciones.h"
#include "Torneo.h"
#include "Fecha.h"
#include <string>

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
            int op;

            do{
                system("cls");
                 cout << "\n=== REGISTRO DE CLUB ===\n";
                 cout << "1. Cargar club\n";
                 cout << "0. Volver atras\n";
                 cout << "Seleccione una opcion:";

                op = leerEnteroConIntentos(3);

                if (op == -1) {
                    cout << "Volviendo...\n";
                    cin.get();
                    continue;
                }

                switch (op) {
                    case 1:
                    {
                        char confirm = 'N';
                        do{
                            Club C;
                            C.generarNuevoId();

                            string nombre;
                            int intentos = 0;
                            bool nombreValido = false;

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        while (intentos <3) {
                            cout << "Ingrese nombre del club (solo letras y espacios): ";
                            getline(cin, nombre);

                       if (validarSoloLetrasEspacios(nombre.c_str())) {
                           nombreValido = true;
                           break;

                        } else {
                            intentos++;
                            cout << "Nombre invalido. Intento "
                                << intentos << " de 3. \n";
                            }
                        }

                        if (!nombreValido) {
                            cout << "\n Se superaron los 3 intentos. Volviendo al menu... \n";
                            cin.get();
                            break;
                        }

                        C.setNombre(nombre);

                        if (archivoClubes.existeClubPorNombre(nombre)) {
                            cout << "Error, el club ya esta registrado.\n";
                            cout << "Precione doble ENTER para continuar...\n";
                            cin.get();
                            continue;
                        }
                        if (archivoClubes.guardar(C)) 
                            cout << "Club registrado exitosamente. \n";
                        
                        else 
                            cout << "Error al guardar el club. \n";
                        

                         cout << "Desea cargar otro Club? (S/N):";
                         confirm = leerOpcionSN();
                         

            } while (confirm == 'S');

            break;
        }

        case 0:
          op = 0;
          break;
        
        default:
          cout << "Opcion invalida.\n";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cin.get();
          
       }
    } while (op != 0);
    
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

            cout << "\nPresione doble ENTER para volver...\n";
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

                cout << "\nPresione doble ENTER para volver...\n";
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

                cout << "\nPrecione doble ENTER para volver al menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();

                break;
            }
 case 6: {
    system("cls");
    cout << "\n=== REGISTRO DE JUGADOR ===\n";
    char confirm = 'N';

    do {
        Jugador J;

        // DNI
        int intentosDni = 0;
        bool dniValido = false;
        while (intentosDni < 3) {
            cout << "Ingrese DNI (0 para volver): ";
            string dniStr;
            getline(cin, dniStr);
            if (dniStr == "0") break;

            bool esNumero = true;
            for (char c : dniStr) if (!isdigit(c)) esNumero = false;

            if (!esNumero) {
                intentosDni++;
                cout << "DNI invalido. Solo numeros. Intento " << intentosDni << " de 3.\n";
                continue;
            }

            int dni = atoi(dniStr.c_str());
            if (dni < 1 || dni > 99999999) {
                intentosDni++;
                cout << "DNI invalido. Debe ser entre 1 y 99999999. Intento " << intentosDni << " de 3.\n";
                continue;
            }

            J.setDni(dni);
            dniValido = true;
            break;
        }
        if (!dniValido) break;

        // Nombre
        int intentosNombre = 0;
        bool nombreValido = false;
        while (intentosNombre < 3) {
            cout << "Ingrese nombre (0 para volver): ";
            string nombre;
            getline(cin, nombre);
            if (nombre == "0") break;

            bool valido = true;
            for (char c : nombre) if (!isalpha(c) && c != ' ') valido = false;

            if (!valido) {
                intentosNombre++;
                cout << "Nombre invalido. Solo letras y espacios. Intento " << intentosNombre << " de 3.\n";
                continue;
            }

            J.setNombre(nombre);
            nombreValido = true;
            break;
        }
        if (!nombreValido) break;

        // Apellido
        int intentosApellido = 0;
        bool apellidoValido = false;
        while (intentosApellido < 3) {
            cout << "Ingrese apellido (0 para volver): ";
            string apellido;
            getline(cin, apellido);
            if (apellido == "0") break;

            bool valido = true;
            for (char c : apellido) if (!isalpha(c) && c != ' ') valido = false;

            if (!valido) {
                intentosApellido++;
                cout << "Apellido invalido. Solo letras y espacios. Intento " << intentosApellido << " de 3.\n";
                continue;
            }

            J.setApellido(apellido);
            apellidoValido = true;
            break;
        }
        if (!apellidoValido) break;

        // Teléfono
        int intentosTel = 0;
        bool telValido = false;
        while (intentosTel < 3) {
            cout << "Ingrese telefono (0 para volver): ";
            string tel;
            getline(cin, tel);
            if (tel == "0") break;

            if (!validarTelefono(tel.c_str(), 6, 15)) {
                intentosTel++;
                cout << "Telefono invalido. Solo numeros y longitud correcta. Intento " << intentosTel << " de 3.\n";
                continue;
            }

            J.setTelefono(tel);
            telValido = true;
            break;
        }
        if (!telValido) break;

        // Email
        int intentosEmail = 0;
        bool emailValido = false;
        while (intentosEmail < 3) {
            cout << "Ingrese email (0 para volver): ";
            string email;
            getline(cin, email);
            if (email == "0") break;

            if (!validarEmail(email)) {
                intentosEmail++;
                cout << "Email invalido. Intento " << intentosEmail << " de 3.\n";
                continue;
            }

            J.setEmail(email);
            emailValido = true;
            break;
        }
        if (!emailValido) break;

        // Fecha de nacimiento
        int intentosFecha = 0;
        bool fechaValida = false;
        while (intentosFecha < 3) {
            cout << "Ingrese fecha de nacimiento (DD/MM/AAAA, 0 para volver): ";
            string fechaStr;
            getline(cin, fechaStr);
            if (fechaStr == "0") break;

            Fecha f;
            if (!validarFecha(fechaStr, f)) {
                intentosFecha++;
                cout << "Formato invalido. Intento " << intentosFecha << " de 3.\n";
                continue;
            }

            J.setFechaNacimiento(f);
            fechaValida = true;
            break;
        }
        if (!fechaValida) break;

        // Asignar ID antes de guardar
        J.setId(archivoJugadores.getSiguienteID());


        // Guardar jugador
        if (archivoJugadores.guardarRegistro(J)) {
         cout << "\nJugador registrado exitosamente.\n";
         cout << "ID asignado: " << J.getId() << "\n";
        } else {
    cout << "\nError al guardar el jugador.\n";
 }

       
        cout << "\nDesea cargar otro jugador? (S/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (confirm == 'S' || confirm == 's');

    break;
}

case 7: {
    system("cls");
    cout << "\n=== EDITAR JUGADOR ===\n";

    int cantidad = archivoJugadores.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay jugadores registrados.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        break;
    }

    // Mostrar lista de jugadores
    archivoJugadores.listarNombreApellido();

    int id;
    cout << "\nIngrese el ID del jugador a editar (0 para volver): ";
    cin >> id;

    if(id == 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer
        break; // volver al menú
    }

    // Buscar jugador por ID
    int pos = archivoJugadores.buscarPorId(id);
    if(pos == -1) {
        cout << "Jugador no encontrado.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        break;
    }

    // Leer y mostrar datos actuales
    Jugador J = archivoJugadores.leerRegistro(pos);
    cout << "\nDatos actuales del jugador:\n";
    J.mostrar();

    if (!J.esValido()) {
    cout << "Registro invalido.\n";
    system("pause");
    return;
}


    // Editar datos
    cout << "\nIngrese los nuevos datos (0 para cancelar cualquier campo):\n";
    if(J.cargar()) { // dentro de J.cargar() se puede manejar la cancelación por campo
        if(archivoJugadores.modificarRegistro(J, pos)) {
            cout << "\nJugador modificado correctamente.\n";
        } else {
            cout << "\nError al modificar el registro.\n";
        }
    } else {
        cout << "\nEdición cancelada. No se modificó el jugador.\n";
    }

    cout << "\nPresione ENTER para volver...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer antes de pausa
    cin.get();

    break;
}
  case 8: {
    system("cls");
    cout << "\n==== ELIMINAR JUGADOR ====\n";

    int cantidad = archivoJugadores.getCantidadRegistros();
    if (cantidad == 0) {
        cout << "No hay jugadores registrados.\n";
        cin.get();
        break;
    }

    cout << "Ingrese el DNI del jugador a eliminar (0 para volver): ";
    int dni = leerEnteroConIntentos(3);
    if (dni == 0) break;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia buffer

    int pos = archivoJugadores.buscarPorDni(dni);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
        cin.get();
        break;
    }

    Jugador J = archivoJugadores.leerRegistro(pos);
    cout << "\nJugador encontrado:\n";
    J.mostrar();

    cout << "\n¿Desea eliminar este jugador? (S/N):";
    char confirm = leerOpcionSN();

    if (confirm != 'S') {
        cout << "Eliminacion cancelada. Volviendo al menu...\n";
        cin.get();
        break;
    }

    if (archivoJugadores.eliminarRegistroFisico(dni)) {
        cout << "Jugador eliminado correctamente.\n";
    } else {
        cout << "Error al eliminar el jugador.\n";
    }
    cout << "\nPresione ENTER para volver...\n";
    cin.get();
    break;
}


          case 9: { 
          system("cls");
          cout << "\n=== LISTA DE JUGADORES ===\n";

           int cantidad = archivoJugadores.getCantidadRegistros();
           if (cantidad == 0) {
               cout << "No hay jugadores registrados.\n";
            } else {
             archivoJugadores.listarRegistros();
            }

          cout << "\nPresione doble ENTER para volver al menu...";
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cin.get();

        break;
    } 


            case 10: {
                system("cls");
                cout << "\n=== CREAR FIXTURE ===\n";

                ArchivoTorneo archTorneo("torneos.dat");

                int cantidad = archTorneo.CantidadRegistros();
                if (cantidad == 0) {
                    cout << "No hay torneos registrados.\n";
                    cout << "\nPrecione doble ENTER para volver al menu...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                }

                cout << "¿Desea crear el fixture del torneo? (S/N):";
                char confirm = leerOpcionSN();

                if (confirm != 'S') {
                    cout << "Operacion cancelada. Volviendo al menu...\n";
                    cin.get();
                    break;
                }

                archTorneo.crearFixture(1);

                cout << "\nFixture creado correctamente.\n";
                cout << "\nPrecione doble ENTER para volver al menu...";
                cin.get();

                break;
            }

            case 11: {

                system("cls");
                cout << "\n=== REGISTRAR TORNEO ===\n";

                Torneo t;
                t.cargar();

                cout << "\nTorneo cargado correctamente:\n";
                t.mostrar();

                cout << "\nPrecione doble ENTER para volver al menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();

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