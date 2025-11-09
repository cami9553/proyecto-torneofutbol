#include "Torneo.h"
#include <iostream>
using namespace std;


Torneo::Torneo() {
    _idTorneo = 0;
    _nombre = "";
    _anio = 0;

}

void Torneo::setIdTorneo(int idTorneo) {
    _idTorneo = idTorneo;
}

void Torneo::setNombre(const string& nombre) {
    _nombre = nombre;
}

void Torneo::setAnio(int anio) { 
    _anio = anio;
}

int Torneo::getIdTorneo() {
    return _idTorneo;
}

string Torneo::getNombre() {
    return _nombre;
}

int Torneo::getAnio() {
    return _anio;
}
