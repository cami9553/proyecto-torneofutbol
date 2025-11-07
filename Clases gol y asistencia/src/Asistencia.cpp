#include "Asistencia.h"

// Getters
int Asistencia::getNroPartido() {
    return _nroPartido;
}

int Asistencia::getDniJugador() {
    return _dniJugador;
}

// Setters
void Asistencia::setNroPartido(int nro) {
    _nroPartido = nro;
}

void Asistencia::setDniJugador(int dni) {
    _dniJugador = dni;
}
