#include "Asistencia.h"
#include <iostream>
using namespace std;

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
 void Asistencia::cargar() {
    cout << "Ingrese DNI del jugador:";
    cin >> _dniJugador;
    cout << "Ingrese número del partido:";
    cin >> _nroPartido;
 }