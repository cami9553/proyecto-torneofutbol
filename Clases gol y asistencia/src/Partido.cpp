#include "Partido.h"
#include <iostream>

Partido::Partido() {
    _nroPartido = 0;
    _fecha = Fecha();
    _idTorneo = 0;
    _idClubLocal = 0;
    _idClubVisitante = 0;
    _golesLocal = 0;
    _golesVisitante = 0;    
}

Partido::Partido(int nroPartido, Fecha fecha, int idTorneo, int idClubLocal, int idClubVisitante, int golesLocal, int golesVisitante) {
    _nroPartido = nroPartido;
    _fecha = fecha;
    _idTorneo = idTorneo;
    _idClubLocal = idClubLocal;
    _idClubVisitante = idClubVisitante;
    _golesLocal = golesLocal;
    _golesVisitante = golesVisitante;
}

void Partido::setNroPartido(int nro){
	_nroPartido = nro;
}

void Partido::setFecha(Fecha fecha){
	_fecha = fecha;
}

void Partido::setIdTorneo(int id){
	_idTorneo = id;
}

void Partido::setIdClubLocal(int id){
	_idClubLocal = id;
}

void Partido::setIdClubVisitante(int id){
	_idClubVisitante = id;
}

void Partido::setGolesLocal(int goles){
	_golesLocal = goles;
}

void Partido::setGolesVisitante(int goles){
	_golesVisitante = goles;
}


int Partido::getNroPartido(){
	return _nroPartido;
}

Fecha Partido::getFecha(){
	return _fecha;
}

int Partido::getIdTorneo(){
	return _idTorneo;
}

int Partido::getIdClubLocal(){
	return _idClubLocal;
}

int Partido::getIdClubVisitante(){
	return _idClubVisitante;
}

int Partido::getGolesLocal(){
	return _golesLocal;
}

int Partido::getGolesVisitante(){
	return _golesVisitante;
}

void Partido::cargar() {
    cout << "Numero de Partido: ";
    cin >> _nroPartido;
	cout << "ID Torneo: ";
    cin >> _idTorneo;
    cout << "ID Club Local: ";
    cin >> _idClubLocal;
    cout << "ID Club Visitante: ";
    cin >> _idClubVisitante;
    cout << "Goles Local: ";
    cin >> _golesLocal;
    cout << "Goles Visitante: ";
    cin >> _golesVisitante;
    cout << "Fecha: " << endl;
    _fecha.cargar();
}

void Partido::mostrar() {
    cout << "Numero de Partido: " << _nroPartido << endl;
	cout << "Id Torneo: " << _idTorneo << endl;
    cout << "Club Local: " << _idClubLocal << endl;
    cout << "Club Visitante: " << _idClubVisitante << endl;
    cout << "Goles Local: " << _golesLocal << endl;
    cout << "Goles Visitante: " << _golesVisitante << endl;
    cout << "Fecha: " << _fecha.toString() << endl;
}
