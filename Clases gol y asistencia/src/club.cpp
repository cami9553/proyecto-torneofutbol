#include "club.h"
#include <iostream>
using namespace std;

Club::Club() {
    _idClub = 0;
    _nombre = "";
    _presidente = "";
    _ciudad = "";

}

Club::Club(int idClub, string nombre, string presidente, string ciudad) {
    _idClub = idClub;
    _nombre = nombre;
    _presidente = presidente;
    _ciudad = ciudad;
}

void Club::setIdClub(int idClub){ _idClub = idClub;}
void Club::setNombre(string nombre){ _nombre = nombre;}
void Club::setPresidente(string presidente){ _presidente = presidente;}
void Club::setCiudad(string ciudad){ _ciudad = ciudad;}

int Club::getIdClub(){ return _idClub;}
string Club::getNombre(){ return _nombre;}
string Club::getPresidente(){ return _presidente;}
string Club::getCiudad(){ return _ciudad;}

void Club::agregarJugador(Jugador j){
    _jugadores.push_back(j);
}

void Club::mostrar(){
    cout << "ID Club: " << _idClub << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Presidente: " << _presidente << endl;
    cout << "Ciudad: " << _ciudad << endl;
    cout << "Cantidad de jugadores: " << _jugadores.size() << endl;
}