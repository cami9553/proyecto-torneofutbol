#include "Gol.h"

//Asignacion de valores y armado para visualizacion
Gol::Gol()
{
    _nroPartido = 3;
    _dniJugador = 12345678;
    _tipoGol = 6;
}

//Getters
int Gol::getNroPartido()
{
    return _nroPartido;
}

int Gol::getDniJugador()
{
    return _dniJugador;
}

int Gol::getTipoGol()
{
    return _tipoGol;
}

//Setters
void Gol::setNroPartido(int nro) {
    _nroPartido = nro;
}

void Gol::setDniJugador(int dni) {
    _dniJugador = dni;
}

void Gol::setTipoGol(int tipo) {
    _tipoGol = tipo;
}



