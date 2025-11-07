#include "ArchivoJugador.h"
#include <cstdio>


ArchivoJugador::ArchivoJugador(const std::string& nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

int ArchivoJugador::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);

    return tam / sizeof(Jugador);
}

Jugador ArchivoJugador::leerRegistro(int posicion) {
    Jugador jugador;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return jugador;

    fseek(pFile, posicion * sizeof(Jugador), SEEK_SET);
    fread(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);

    return jugador;
}

bool ArchivoJugador::guardarRegistro(const Jugador& jugador) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == NULL) return false;

    bool ok = fwrite(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);
    return ok;
}

bool ArchivoJugador::modificarRegistro(const Jugador& jugador, int posicion) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, posicion * sizeof(Jugador), SEEK_SET);
    bool ok = fwrite(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);
    return ok;
}

void ArchivoJugador::leerTodos(Jugador* vector, int cantidadRegistros) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Jugador), cantidadRegistros, pFile);
    fclose(pFile);
}
