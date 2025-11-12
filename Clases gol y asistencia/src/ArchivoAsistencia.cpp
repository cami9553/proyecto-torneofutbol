#include <iostream>
#include <cstdio>
#include "Archivoasistencia.h"
#include "Asistencia.h"
using namespace std;

Archivoasistencia::Archivoasistencia(const std::string& nombreArchivo) {
    _nombreArchivo = nombreArchivo;
    _Asistencias = nullptr;
     _cantidadasistencias = 0;
}

Archivoasistencia::~Archivoasistencia() {
    delete[] _Asistencias;
}

int Archivoasistencia::getCantidad() const {
    return _cantidadasistencias;
}

void Archivoasistencia::agregarasistencia(const Asistencia& a) {
    Asistencia* aux = new Asistencia[_cantidadasistencias + 1];
    for (int i = 0; i < _cantidadasistencias; i++) {
        aux[i] = _Asistencias[i];
    }
    aux[_cantidadasistencias] = a;

    delete[] _Asistencias;
    _Asistencias = aux;
    _cantidadasistencias++;
}

void Archivoasistencia::cargarDesdeArchivo() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Asistencia);
    rewind(pFile);

    delete[] _Asistencias;
    _Asistencias = new Asistencia[cantidad];
    fread(_Asistencias, sizeof(Asistencia), cantidad, pFile);
    fclose(pFile);

    _cantidadasistencias = cantidad;
}

void Archivoasistencia::guardarEnArchivo() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "wb");
    if (pFile == NULL) return;

    fwrite(_Asistencias, sizeof(Asistencia), _cantidadasistencias, pFile);
    fclose(pFile);
}
 Asistencia Archivoasistencia::getAsistencia(int indice) const {
    if (indice < 0 || indice >= _cantidadasistencias) return Asistencia();
    return _Asistencias[indice];
 }

