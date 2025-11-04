#include "Jugador.h"

Jugador::Jugador()
{
  
	_posicion = 0;
	_idClub = 0;
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
