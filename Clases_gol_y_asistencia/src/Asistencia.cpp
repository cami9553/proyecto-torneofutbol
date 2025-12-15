#include "Asistencia.h"
#include "Validaciones.h"
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
    // dni con validacion
    cout << "Ingrese DNI del jugador: ";
    while(true) {
        _dniJugador = leerEntero();
        if(_dniJugador >= 1000000 && _dniJugador <= 99999999) {
            break;  // DNI válido
        }
        cout << "Error: DNI debe tener entre 7 y 8 digitos. Ingrese nuevamente: ";
    }
    
    // num de partido con validacion
    cout << "Ingrese número del partido: ";
    while(true) {
        _nroPartido = leerEntero();
        if(_nroPartido > 0) {
            break;  // Número válido
        }
        cout << "Error: Número de partido debe ser positivo. Ingrese nuevamente: ";
    }
}
