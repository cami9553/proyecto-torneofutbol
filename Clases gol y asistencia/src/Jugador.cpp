#include "Jugador.h"
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
void Jugador::cargar() {
    Persona::cargar();
    cout << "Club: "<<endl; //aca habria que traer lista de clubes, cargarlo de archivo y mostrar lista para que elija una opcion de clubes ya creados.
    cin >> _idClub;
    cout << "Posición (Defensor:1/Mediocampista:2/Delantero:3):  "<<endl;
    cin.ignore();
    cin >> _posicion;
}

void Jugador::mostrar(){
    Persona::mostrar();
    cout << "------ Club ------"<<endl;
    cout << "Club: " << _idClub << endl;
    cout << "Posicion: " << _posicion << endl;
}
