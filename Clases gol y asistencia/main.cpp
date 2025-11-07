#include <iostream>
#include "Gol.h"
#include "Asistencia.h"
#include "Club.h"
#include "gestionClub.h"
#include "ArchivoJugador.h"
using namespace std;

int main()
{
    //Prueba para visualizar datos
    Gol gol1;
    Asistencia asistenciacls1;
    std::cout << gol1.getNroPartido() << endl;
    std::cout << gol1.getDniJugador() << endl;
    std::cout << gol1.getTipoGol() << endl;
    cout << endl;
    std::cout << asistenciacls1.getNroPartido() << endl;
    std::cout << asistenciacls1.getDniJugador() << endl;

  cout << "\n\n==== PRUEBA DE CLUBES ====\n";


    GestionClub gestion;

    Club c1(1, "Club A", "Presidente A", "Ciudad A");
    Club c2(2, "Club B", "Presidente B", "Ciudad B");

    gestion.agregarClub(c1);
    gestion.agregarClub(c2);

    gestion.listarClubs();


    // ************************ PROBANDO JUGADOR *******************************

    cout << "******* REGISTRO DE JUGADORES *******" << endl;
    Jugador jugadorUno, jugadorMostrar;
    ArchivoJugador primerArchivo("jugadores.dat");

    jugadorUno.cargar();
    if(primerArchivo.guardarRegistro(jugadorUno)){
        cout << "Archivo guardado existosamente.\n" << endl;
        cout << "En total hay guardados: " << primerArchivo.getCantidadRegistros() << " Registros.\n" <<endl;
    }
    else
        cout << "El archivo no pudo guardarse." << endl;

    int respuesta;
    cout << "\n\nLEER TODOS LOS REGISTROS DEL ARCHIVO? (SI-1 / NO-2): ";
    cin >> respuesta;
    if(respuesta){
            for(int x = 0; x < primerArchivo.getCantidadRegistros(); x++){
                jugadorMostrar = primerArchivo.leerRegistro(x);
                cout << "\n\n-------------" << "Jugador " << x+1 << "-------------" <<endl;
                jugadorMostrar.mostrar();
            }
    }


    return 0;
}
