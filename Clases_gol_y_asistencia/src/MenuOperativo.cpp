#include "MenuAdministrativo.h"
#include "Archivoasistencia.h"
#include "Asistencia.h"
#include "ArchivoGol.h"
#include "ArchivoClub.h"
#include "ArchivoJugador.h"
#include "ArchivoPartido.h"
#include "Validaciones.h"
#include "ClubEnTorneo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void menuOperativo()
{

    int opcion;

    do
    {
        system("cls");
        cout << "\n==== AREA OPERATIVA ====\n";
        cout << "1.Registrar Partido\n";
        cout << "2.Ver tabla posiciones\n";
        cout << "3.Ver tabla goleadores\n";
        cout << "4.Ver tabla asistidores\n";
        cout << "5.Ver Fixture\n";
        cout << "0.Salir\n";
        cout << "Seleccione una opcion:";

        opcion = leerEnteroEnRango(0, 5);

        system("cls");


        switch(opcion)
        {

        case 1:
        {
            ArchivoPartido archPartido("partidos.dat");
            archPartido.registrarResultado();
            cin.get();
            break;
        }


        case 2:
        {
            ArchivoClub archClub("clubes.dat");
            ArchivoPartido archPartido("partidos.dat");


            int cantClubes = archClub.CantidadRegistros();


            if (cantClubes == 0) {
                cout << "No hay clubes registrados.\n";
                cin.get();
                break;
            }


            ClubEnTorneo** tabla = new ClubEnTorneo*[cantClubes];
            for (int i = 0; i < cantClubes; i++) {
                Club c = archClub.leerRegistro(i);
                tabla[i] = new ClubEnTorneo(c.getIdClub(), c.getNombre());
            }

            // Actualizar tabla con resultados de partidos
            int cantPartidos = archPartido.getCantidadRegistros();
            for (int i = 0; i < cantPartidos; i++) {
                Partido p = archPartido.leerRegistro(i);

                if(p.getJugado()){

                    // Buscar club local
                    for (int j = 0; j < cantClubes; j++) {
                        if (tabla[j]->getIdClub() == p.getIdClubLocal()) {
                            tabla[j]->sumarPartido(p.getGolesLocal(), p.getGolesVisitante());
                            break;
                        }
                    }
                    // Buscar club visitante
                    for (int j = 0; j < cantClubes; j++) {
                        if (tabla[j]->getIdClub() == p.getIdClubVisitante()) {
                            tabla[j]->sumarPartido(p.getGolesVisitante(), p.getGolesLocal());
                            break;
                        }
                    }
                }
            }

            // Ordenar tabla por PTS y luego por DG
            for (int i = 0; i < cantClubes - 1; i++) {
                for (int j = i + 1; j < cantClubes; j++) {
                    if (tabla[j]->getPTS() > tabla[i]->getPTS() ||
                       (tabla[j]->getPTS() == tabla[i]->getPTS() && tabla[j]->getDG() > tabla[i]->getDG())) {
                        ClubEnTorneo* temp = tabla[i];
                        tabla[i] = tabla[j];
                        tabla[j] = temp;
                    }
                }
            }

            // Mostrar tabla de posiciones
            cout << "\n=== TABLA DE POSICIONES ===\n";
            cout << left << setw(4) << "POS" << setw(20) << "CLUB"
                 << setw(4) << "PJ" << setw(4) << "G" << setw(4) << "E" << setw(4) << "P"
                 << setw(4) << "GF" << setw(4) << "GC" << setw(4) << "DG" << setw(4) << "PTS\n";

            for (int i = 0; i < cantClubes; i++) {
                cout << left << setw(4) << (i + 1)
                     << setw(20) << tabla[i]->getNombre()
                     << setw(4) << tabla[i]->getPJ()
                     << setw(4) << tabla[i]->getG()
                     << setw(4) << tabla[i]->getE()
                     << setw(4) << tabla[i]->getP()
                     << setw(4) << tabla[i]->getGF()
                     << setw(4) << tabla[i]->getGC()
                     << setw(4) << tabla[i]->getDG()
                     << setw(4) << tabla[i]->getPTS() << endl;
            }


            for (int i = 0; i < cantClubes; i++)
                delete tabla[i];
            delete[] tabla;

            cin.get();
            break;
        }


        case 3:
        {
            cout << "\n=== TABLA DE GOLEADORES ===\n";
            ArchivoGol archivoGoles("goles.dat");
            ArchivoJugador archivoJugadores("jugadores.dat");

            archivoGoles.cargarDesdeArchivo();
            int cantGoles = archivoGoles.getCantidad();
            int cantJugadores = archivoJugadores.getCantidadRegistros();

            if (cantGoles == 0)
            {
                cout << "No hay goles registrados.\n";
                cin.get();
                break;
            }
            // Contar goles por jugador
            int* golesPorJugador = new int[cantJugadores]();
            int* dnis = new int[cantJugadores]();

            // Obtener todos los DNI de jugadores
            for (int i = 0; i < cantJugadores; i++)
            {
                Jugador j = archivoJugadores.leerRegistro(i);
                dnis[i] = j.getDni();
            }
            // Contar goles
            for (int i = 0; i < cantGoles; i++)
            {
                Gol g = archivoGoles.leerRegistro(i);
                int dniGoleador = g.getDniJugador();
                for (int j = 0; j < cantJugadores; j++)
                {
                    if (dnis[j] == dniGoleador)
                    {
                        golesPorJugador[j]++;
                        break;
                    }
                }
            }
            //ordenar por goles
            int* indices = new int[cantJugadores];
            for (int i = 0; i < cantJugadores; i++)
            {
                indices[i] = i;
            }
            for (int i = 0; i < cantJugadores - 1; i++)
            {
                for (int j = i + 1; j < cantJugadores; j++)
                {
                    if (golesPorJugador[indices[j]] > golesPorJugador[indices[i]])
                    {
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
            for (int i = 0; i < cantJugadores; i++)
            {
                int idx = indices[i];
                if (golesPorJugador[idx] > 0)
                {
                    Jugador j = archivoJugadores.leerRegistro(idx);
                    cout << left << setw(4) << posicion++
                         << setw(25) << (std::string(j.getApellido()) + " " + j.getNombre()).substr(0, 24)
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

        case 4:
        {

            cout << "\n=== TABLA DE ASISTIDORES ===\n";
            Archivoasistencia archivoAsistencias("asistencias.dat");
            ArchivoJugador archivoJugadores("jugadores.dat");

            archivoAsistencias.cargarDesdeArchivo();
            int cantAsistencias = archivoAsistencias.getCantidad();
            int cantJugadores = archivoJugadores.getCantidadRegistros();

            if (cantAsistencias == 0)
            {
                cout << "No hay asistencias registradas.\n";
                cin.get();
                break;
            }

            int* asistenciasPorJugador = new int[cantJugadores]();
            int* dnis = new int[cantJugadores]();

            // Guardar los DNI de los jugadores
            for (int i = 0; i < cantJugadores; i++)
            {
                Jugador j = archivoJugadores.leerRegistro(i);
                dnis[i] = j.getDni();
            }

            // Contar asistencias
            for (int i = 0; i < cantAsistencias; i++)
            {
                Asistencia a = archivoAsistencias.getAsistencia(i);
                int dniAsistente = a.getDniJugador();
                for (int j = 0; j < cantJugadores; j++)
                {
                    if (dnis[j] == dniAsistente)
                    {
                        asistenciasPorJugador[j]++;
                        break;
                    }
                }
            }

            // Ordenar por cantidad de asistencias (descendente)
            int* indices = new int[cantJugadores];
            for (int i = 0; i < cantJugadores; i++) indices[i] = i;

            for (int i = 0; i < cantJugadores - 1; i++)
            {
                for (int j = i + 1; j < cantJugadores; j++)
                {
                    if (asistenciasPorJugador[indices[j]] > asistenciasPorJugador[indices[i]])
                    {
                        int temp = indices[i];
                        indices[i] = indices[j];
                        indices[j] = temp;
                    }
                }
            }

            cout << "----------------------------------------\n";
            cout << "POS\tJUGADOR\t\tASISTENCIAS\n";
            cout << "----------------------------------------\n";

            int posicion = 1;
            for (int i = 0; i < cantJugadores; i++)
            {
                int idx = indices[i];
                if (asistenciasPorJugador[idx] > 0)
                {
                    Jugador j = archivoJugadores.leerRegistro(idx);
                    cout << posicion << "\t"
                         << j.getApellido() << " " << j.getNombre()
                         << "\t" << asistenciasPorJugador[idx] << endl;
                    posicion++;
                }
            }

            cout << "----------------------------------------\n";

            delete[] asistenciasPorJugador;
            delete[] dnis;
            delete[] indices;

            cin.get();
            break;

        }

        case 5:
        {
            ArchivoPartido archPartido("partidos.dat");
            archPartido.listarRegistros();
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

/*void registrarAsistencia() {
    Archivoasistencia archivo("asistencias.dat");

    Asistencia a;
    cout << "\n=== REGISTRAR ASISTENCIA ===\n";
    a.cargar(); // el método cargar() debería pedir dniJugador, idPartido.
    archivo.cargarDesdeArchivo();  // carga las que ya hay
    archivo.agregarasistencia(a);  // suma la nueva
    archivo.guardarEnArchivo();    // guarda todo
    cout << "Asistencia registrada correctamente.\n";
    cin.get();
}*/
