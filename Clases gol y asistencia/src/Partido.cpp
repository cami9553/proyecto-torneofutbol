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

