#include "Jugador.h"
#include "ArchivoClub.h"
#include "Validaciones.h"
#include "Club.h"
#include <iomanip>
using namespace std;

Jugador::Jugador()
{
	_posicion = 0;
	_idClub = 0;
}

Jugador::Jugador(int posicion, int idClub, int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento)
    : Persona(dni, apellido, nombre, telefono, email, fechaNacimiento)
{
    _posicion = posicion;
    _idClub = idClub;
}

void Jugador::setPosicion(int posicion){
	_posicion=posicion;
}

void Jugador::setIdClub(int idClub){
	_idClub = idClub;
}

int Jugador::getPosicion(){
	return _posicion;
}

int Jugador::getIdClub(){
	return _idClub;
}

//Otros metodos
bool Jugador::cargar() {
    if(Persona::cargar() == false) return false;
    cout << "\nClub (Elige ID): "<<endl;

    //Muestro lista de clubes creados
    ArchivoClub archivo("clubes.dat");
    Club* lista = archivo.getClubes();

    if (archivo.CantidadRegistros() == 0) {
        cout << "No hay clubes cargados.\n";
        return false;
    }

    for (int i = 0; i < archivo.CantidadRegistros(); i++) {
        cout << lista[i].getIdClub() << "- " << lista[i].getNombre() << endl;
    }
    cout << "\nSu eleccion de Club (* para volver): ";
	_idClub = leerEnteroConIntentos(3);
	if (_idClub == -1) return false;

	cout << "\nPosicion (Defensor:1/Mediocampista:2/Delantero:3) (* para volver): ";
	_posicion = leerEnteroConIntentos(3);
	if (_posicion == -1) return false;
}

void Jugador::mostrar() {
    ArchivoClub archivoClub("clubes.dat");
    string nombrePosicion;

    if(_posicion == 1)
        nombrePosicion = "Defensor";
    else if(_posicion == 2)
        nombrePosicion = "Mediocampista";
    else
        nombrePosicion = "Delantero";

    Persona::mostrar();
    cout << left << setw(20) << "Club:"      << archivoClub.buscarPorId(_idClub)->getNombre() << endl;
    cout << left << setw(20) << "Posicion:"  << nombrePosicion << endl;
    cout << "====================================================\n\n" << endl;
}
