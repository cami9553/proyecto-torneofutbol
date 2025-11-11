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
        case 3:
        {
            cout << "\n=== TABLA DE GOLEADORES ===\n";
            ArchivoGol archivoGoles("goles.dat");
            ArchivoJugador archivoJugadores("jugadores.dat");
    
            int cantGoles = archivoGoles.getCantidadRegistros();
            int cantJugadores = archivoJugadores.getCantidadRegistros();

            if (cantGoles == 0) {
                cout << "No hay goles registrados.\n";
                cin.get();
                break;
            }
              // Contar goles por jugador
            int* golesPorJugador = new int[cantJugadores]();
            int* dnis = new int[cantJugadores]();
    
             // Obtener todos los DNI de jugadores
            for (int i = 0; i < cantJugadores; i++) {
                Jugador j = archivoJugadores.leerRegistro(i);
                dnis[i] = j.getDni();
            }
            // Contar goles
            for (int i = 0; i < cantGoles; i++) {
                Gol g = archivoGoles.leerRegistro(i);
                int dniGoleador = g.getDniJugador();
                for (int j = 0; j < cantJugadores; j++) {
                    if (dnis[j] == dniGoleador) {
                        golesPorJugador[j]++;
                        break;
                    }
                }
            }
            //ordenar por goles
            int* indices = new int[cantJugadores];
            for (int i = 0; i < cantJugadores; i++) {
                 indices[i] = i;
            }
            for (int i = 0; i < cantJugadores - 1; i++) {
                 for (int j = i + 1; j < cantJugadores; j++) {
                      if (golesPorJugador[indices[j]] > golesPorJugador[indices[i]]) {
                          int temp = indices[i];
                          indices[i] = indices[j];
                          indices[j] = temp;
                      }
                 }
            }
            cout << "========================================\n";
            cout << left << setw(4) << "POS" << setw(25) << "JUGADOR" << setw(8) << "GOLES\n";
            cout << "========================================\n";
            int posicion = 1;
            for (int i = 0; i < cantJugadores; i++) {
                int idx = indices[i];
                if (golesPorJugador[idx] > 0) {
                    Jugador j = archivoJugadores.leerRegistro(idx);
                    cout << left << setw(4) << posicion++
                         << setw(25) << (j.getApellido() + " " + j.getNombre()).substr(0, 24)
                         << setw(8) << golesPorJugador[idx] << endl;
                }
            }
            cout << "========================================\n";
    
            delete[] golesPorJugador;
            delete[] dnis;
            delete[] indices;
    
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
