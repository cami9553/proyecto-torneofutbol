#ifndef ARCHIVOPARTIDO_H_INCLUDED
#define ARCHIVOPARTIDO_H_INCLUDED

#include "Partido.h"
#include <string>

class ArchivoPartido {
private:
    std::string _nombreArchivo;

public:
    ArchivoPartido(const std::string& nombreArchivo);

    int getCantidadRegistros();
    Partido leerRegistro(int posicion);
    bool guardarRegistro(const Partido& partido);
    bool modificarRegistro(const Partido& partido, int posicion);
    void leerTodos(Partido* vector, int CantidadRegistros);
    bool listarRegistros();
    void registrarResultado();
};

#endif
