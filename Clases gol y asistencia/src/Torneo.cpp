#include "Torneo.h"
#include <iostream>
#include <cstring>

Torneo::Torneo() {
    _idTorneo = 0;
    strcpy(_nombre, "");
    _anio = 0;
}

void Torneo::setIdTorneo(int idTorneo) {
    _idTorneo = idTorneo;
}

void Torneo::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

void Torneo::setAnio(int anio) {
    _anio = anio;
}

int Torneo::getIdTorneo() {
    return _idTorneo;
}

const char* Torneo::getNombre() {
    return _nombre;
}

int Torneo::getAnio() {
    return _anio;
}
