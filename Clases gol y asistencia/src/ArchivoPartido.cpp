#include "ArchivoPartido.h"
#include <cstdio>

ArchivoPartido::ArchivoPartido(const std::string& nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

int ArchivoPartido::getCantidadRegistros() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);

    return tam / sizeof(Partido);
}

Partido ArchivoPartido::leerRegistro(int posicion) {
    Partido partido;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return partido;

    fseek(pFile, posicion * sizeof(Partido), SEEK_SET);
    fread(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);

    return partido;
}

bool ArchivoPartido::guardarRegistro(const Partido& partido) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == NULL) return false;

    bool ok = fwrite(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);
    return ok;
}

bool ArchivoPartido::modificarRegistro(const Partido& partido, int posicion) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, posicion * sizeof(Partido), SEEK_SET);
    bool ok = fwrite(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);
    return ok;
}

void ArchivoPartido::leerTodos(Partido* vector, int cantidadRegistros) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Partido), cantidadRegistros, pFile);
    fclose(pFile);
}
