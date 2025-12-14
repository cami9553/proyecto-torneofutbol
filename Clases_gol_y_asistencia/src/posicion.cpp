#include "Posicion.h"
#include <cstring>

Posicion::Posicion() {
    idClub = 0;
    nombreClub[0] = '\0';
    partidosJugados = ganados = empatados = perdidos = golesAFavor = golesEnContra = puntos = 0;
}

void Posicion::setIdClub(int id) { idClub = id; }
void Posicion::setNombre(const char *nombre) { strcpy(nombreClub, nombre); }

int Posicion::getIdClub() { return idClub; }
const char *Posicion::getNombre() { return nombreClub; }

void Posicion::sumarPartido(int golesHechos, int golesRecibidos) {
    partidosJugados++;
    golesAFavor += golesHechos;
    golesEnContra += golesRecibidos;

    if (golesHechos > golesRecibidos) {
        ganados++;
        puntos += 3;
    } else if (golesHechos == golesRecibidos) {
        empatados++;
        puntos += 1;
    } else {
        perdidos++;
    }
}

int Posicion::getPartidosJugados() { return partidosJugados; }
int Posicion::getGanados() { return ganados; }
int Posicion::getEmpatados() { return empatados; }
int Posicion::getPerdidos() { return perdidos; }
int Posicion::getGolesAFavor() { return golesAFavor; }
int Posicion::getGolesEnContra() { return golesEnContra; }
int Posicion::getDiferenciaGoles() { return golesAFavor - golesEnContra; }
int Posicion::getPuntos() { return puntos; }
