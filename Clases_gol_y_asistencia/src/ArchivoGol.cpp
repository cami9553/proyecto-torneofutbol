#include <iostream>
#include <cstdio>
#include "ArchivoGol.h"
using namespace std;

ArchivoGol::ArchivoGol(const std::string& nombreArchivo = "goles.dat") {
    _nombreArchivo = nombreArchivo;
    _goles = nullptr;
    _cantidadGoles = 0;
}

ArchivoGol::~ArchivoGol() {
    delete[] _goles;
}

int ArchivoGol::getCantidad() const {
    return _cantidadGoles;
}

void ArchivoGol::agregarGol(const Gol& g) {
    Gol* aux = new Gol[_cantidadGoles + 1];
    for (int i = 0; i < _cantidadGoles; i++) {
        aux[i] = _goles[i];
    }
    aux[_cantidadGoles] = g;

    delete[] _goles;
    _goles = aux;
    _cantidadGoles++;
}

void ArchivoGol::cargarDesdeArchivo() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Gol);
    rewind(pFile);

    delete[] _goles;
    _goles = new Gol[cantidad];
    fread(_goles, sizeof(Gol), cantidad, pFile);
    fclose(pFile);

    _cantidadGoles = cantidad;
}

void ArchivoGol::guardarEnArchivo() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "wb");
    if (pFile == NULL) return;

    fwrite(_goles, sizeof(Gol), _cantidadGoles, pFile);
    fclose(pFile);
}

Gol ArchivoGol::leerRegistro(int posicion){
    Gol gol;
    FILE* pFile = fopen("goles.dat", "rb");
    if (pFile == NULL) return gol;

    fseek(pFile, posicion * sizeof(Gol), SEEK_SET);
    fread(&gol, sizeof(Gol), 1, pFile);
    fclose(pFile);

    return gol;
}
