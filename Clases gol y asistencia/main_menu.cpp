#include <iostream>
#include "Gol.h"
#include "Asistencia.h"
#include "Club.h"
#include "gestionClub.h"
#include "ArchivoJugador.h"
using namespace std;

int main() {
    GestionClub gestion;
    ArchivoJugador archivoJugadores("jugadores.dat");

    int opcion;

    do{
        cout << "\n==== GESTION DE TORNEOS DE FUTBOL ====\n";
        cout << "1.Registrar Club\n";
        cout << "2.Listar Clubs\n";
        cout << "3.Buscar Club por ID\n";
        cout << "4.Registrar Jugador\n";
        cout << "5.Listar Jugadores\n";
        cout << "6.Registrar Gol (prueba)\n";
        cout << "0.Salir\n";
        cout << "Seleccione una opción:";
        cin >> opcion;
        cin.ignore();

     switch(opcion) {
            case 1: {
                int id;
                string nombre, presidente, ciudad;

                cout << "Iingrese ID del club:";
                cin >> id;
                cin.ignore();
                cout << "Ingrese nombre del club:";
                getline(cin, nombre);
                cout << "Ingrese presidente:";
                getline(cin, presidente);
                cout << "?Ingrese ciudad:";
                getline(cin, ciudad);

                Club c(id, nombre, presidente,ciudad);
                gestion.agregarClub(c);
                cout << "Club registrado exitosamente.\n";
                break;
        
            }

            case 2:
                cout << "\n=== LISTA DE CLUBS ===\n";
                gestion.listarClubs();
                break;

            case 3: {
                int id;
                cout << "Ingrese ID del club: ";
                cin >> id;
                
                Club* c = gestion.buscarClubPorId(id);
                
                if (c != nullptr) {
                    cout << "\nClub encontrado:\n";
                    c->mostrar();

                } else {
                    cout << "Club no encontrado.\n";
                }
                break;
             
            }

            case 4: {
                cout << "\n=== REGISTRP DE JUGADOR ===\n";
                Jugador J;
                J.cargar();
                if(archivoJugadores.guardarRegistro(J)) {
                    cout << "jugador registrado exitosamente.\n";
                } else {
                    cout << "Error al guardar el jugador.\n";
                }
                break;
            }
            case 5: {
                cout << "\n=== LISTA DE JUGADORES ===\n";
                int cantidad = archivoJugadores.getCantidadRegistros();
                Jugador J;
                for(int i = 0; i < cantidad; i++) {
                    J = archivoJugadores.leerRegistro(i);
                    cout << "\nJugador #" << i+1 << endl;
                    J.mostrar();    
            }
                break;
}
            case 6: {
                cout << "\n=== REGISTRO DE GOL ===\n";
                Gol g;
                cout << "Nro de partido:" << g.getNroPartido() << endl;
                cout << "DNI jugador:" << g.getDniJugador() << endl;
                cout << "Tipo de gol:" << g.getTipoGol() << endl;
                break;
            }

            case 0:
            cout << "\nSaliendo del sistema...\n";
            break;

            default:
            cout << "Opción inválida intente nuevamente.\n";
        }
    } while(opcion != 0);
    return 0;
}
